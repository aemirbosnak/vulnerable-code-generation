import os
import json
import subprocess
from multiprocessing import Pool
from collections import Counter, OrderedDict
from pathlib import Path


def load_entries(json_path):
    """
    Load the original list of LLM-output entries (each with
    vulnerability_type, subtype, intent, form, context, prompt, output, etc.).
    """
    with open(json_path, 'r') as f:
        return json.load(f)


def esbmc_worker(args):
    """
    Run ESBMC on a single C file, then merge in the original
    prompt metadata (by numeric prefix in the filename).
    """
    model_name, c_dir, fname, entries = args
    src = os.path.join(c_dir, fname)
    report_dir = os.path.join(REPORTS_DIR, model_name)
    os.makedirs(report_dir, exist_ok=True)
    out_txt = os.path.join(report_dir, fname.replace('.c', '.esbmc.txt'))

    cmd = [
        'esbmc', src,
        '--timeout', '15',
        '--incremental-bmc',
        '--overflow-check'
    ]
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True)
    raw = []
    try:
        for line in proc.stdout:
            raw.append(line)
        proc.wait(timeout=300)
    except subprocess.TimeoutExpired:
        proc.kill()

    raw_text = ''.join(raw)
    with open(out_txt, 'w') as f:
        f.write(raw_text)

    status = 'UNKNOWN'
    subreason = None
    if any('ERROR: Timed out'    in l for l in raw):
        status = 'ERROR: Timed out'
    elif any('ERROR: PARSING ERROR' in l for l in raw):
        status = 'ERROR: PARSING ERROR'
        # if gets() caused it, note that
        try:
            with open(src, 'r') as sf:
                src_txt = sf.read()
                if 'gets(' in src_txt:
                    subreason = 'deprecated_gets'
        except:
            pass
    elif any('VERIFICATION FAILED'     in l for l in raw):
        status = 'VERIFICATION FAILED'
    elif any('VERIFICATION SUCCESSFUL' in l for l in raw):
        status = 'VERIFICATION SUCCESSFUL'

    violated = None
    if status == 'VERIFICATION FAILED':
        for idx, line in enumerate(raw):
            if 'Violated property:' in line:
                if idx + 2 < len(raw):
                    violated = raw[idx+2].strip()
                break

    prefix = fname.split('_', 1)[0]
    idx = int(prefix)
    entry = entries[idx]

    metadata = {
        'vulnerability_type': entry.get('vulnerability_type'),
        'subtype':            entry.get('subtype'),
        'intent':             entry.get('intent'),
        'form':               entry.get('form'),
        'context':            entry.get('context'),
        'prompt':             entry.get('prompt'),
    }

    if 'temperature' in entry:
        metadata['temperature'] = entry['temperature']

    if 'cyclomatic_complexity' in entry:
        metadata['cyclomatic_complexity'] = entry['cyclomatic_complexity']

    result = {
        **metadata,
        'esbmc_output':      status,
        'violated_property': violated
    }
    if status == 'ERROR: PARSING ERROR' and subreason:
        result['parsing_error_reason'] = subreason

    return fname, result


def analyze_with_esbmc(model_name, c_dir, entries):
    """
    Run ESBMC in parallel on every .c file in c_dir, merging in metadata.
    Writes both a detailed-vuln-analysis-summary JSON and an executive-vuln-analysis-summary JSON.
    """
    c_files = [f for f in os.listdir(c_dir) if f.endswith('.c')]
    pool_size = min(8, len(c_files))
    args = [(model_name, c_dir, f, entries) for f in c_files]

    summary = {}
    with Pool(pool_size) as pool:
        for fname, result in pool.imap_unordered(esbmc_worker, args):
            summary[fname] = result
            print(f"[analyze] {result['esbmc_output']} for {fname}")

    # sort by filename
    ordered = OrderedDict(sorted(summary.items(), key=lambda x: x[0]))

    det_path = os.path.join(SUMMARY_DIR, f"{model_name}_detailed_summary.json")
    with open(det_path, 'w') as f:
        json.dump(ordered, f, indent=2)
    print(f"[analyze] Detailed vuln-analysis-summary written to {det_path}")

    counts = Counter()
    parsing_breakdown = Counter()
    for res in ordered.values():
        st = res['esbmc_output']
        counts[st] += 1
        if st == 'ERROR: PARSING ERROR':
            reason = res.get('parsing_error_reason', 'other')
            parsing_breakdown[reason] += 1

    status_counts = dict(counts)
    if 'ERROR: PARSING ERROR' in status_counts:
        status_counts['ERROR: PARSING ERROR'] = {
            'total': counts['ERROR: PARSING ERROR'],
            **dict(parsing_breakdown)
        }

    executive = {
        'total_files':   len(ordered),
        'status_counts': status_counts
    }

    temperature_counts = Counter()
    has_temperature = any('temperature' in res for res in ordered.values())
    if has_temperature:
        for res in ordered.values():
            temp = res.get('temperature')
            if temp is not None:
                temperature_counts[str(temp)] += 1
        executive['temperature_breakdown'] = dict(temperature_counts)

    exec_path = os.path.join(SUMMARY_DIR, f"{model_name}_executive_summary.json")
    with open(exec_path, 'w') as f:
        json.dump(executive, f, indent=2)
    print(f"[analyze] Executive vuln-analysis-summary written to {exec_path}")


def main():
    print("[main] Starting ESBMC analysis")
    filename = input("Enter the model result filename (e.g. reverse/qwen2/qwen2_reverse_prompting_sample.json): ").strip()
    path_parts = Path(filename).parts

    if len(path_parts) < 3:
        print("[error] Expected format: <mode>/<model>/<filename>")
        return

    mode, model, file = path_parts[0], path_parts[1], path_parts[2]
    if mode not in {"dynamic", "reverse"}:
        print(f"[error] Invalid mode: {mode}. Must be 'dynamic' or 'reverse'.")
        return

    # Update all paths accordingly
    base_dir = Path(__file__).resolve().parent
    json_path = base_dir / f"../../model-outputs/{mode}/{model}/{file}"
    c_out_dir = base_dir / f"../../c-code/{mode}/{model}"
    report_dir = base_dir / f"../esbmc-reports/{mode}"
    summary_dir = base_dir / f"../vuln-analysis-summary/{mode}"
    summary_prefix = f"{model}_{file.replace('.json', '')}"

    for d in (report_dir, summary_dir):
        d.mkdir(parents=True, exist_ok=True)

    if not json_path.exists():
        print(f"[error] File not found: {json_path}")
        return

    entries = load_entries(json_path)

    # Patch global variables for this run
    global REPORTS_DIR, SUMMARY_DIR
    REPORTS_DIR = str(report_dir)
    SUMMARY_DIR = str(summary_dir)

    analyze_with_esbmc(summary_prefix, str(c_out_dir), entries)
    print("[main] Analysis complete")


if __name__ == '__main__':
    main()
