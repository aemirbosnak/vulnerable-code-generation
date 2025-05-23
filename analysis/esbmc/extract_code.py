import os
import json
import subprocess
import re
from pathlib import Path

# Common headers to inject if missing
COMMON_HEADERS = [
    '<stdio.h>',
    '<stdlib.h>',
    '<string.h>',
    '<stdint.h>',
    '<stddef.h>',
    '<stdbool.h>'
]

def slugify(text: str) -> str:
    """
    Turn arbitrary text into a filesystem-safe lowercase slug:
    spaces→hyphens, drop non-alphanumerics.
    """
    text = text.lower()
    # replace any non-alphanumeric with hyphens
    text = re.sub(r'[^a-z0-9]+', '-', text)
    # strip leading/trailing hyphens
    return text.strip('-')

def extract_c_files(json_path, out_dir):
    """
    Extract C code blocks from <model>_results.json into .c files.
    Filenames will be: 000_<vuln>[_<subtype>]_ <context>.c
    """
    print(f"[extract] Loading prompts from {json_path}")
    os.makedirs(out_dir, exist_ok=True)
    with open(json_path, 'r') as f:
        entries = json.load(f)

    total_entries = len(entries)
    skipped = 0
    prompts_map = {}

    # regexes for ```c and <code> fences
    fence_backtick = re.compile(r'```(?:c)?\s*(?P<code>.*?)\s*```', re.DOTALL)
    fence_html     = re.compile(r'<code>(?P<code>.*?)</code>', re.DOTALL)

    for i, entry in enumerate(entries):
        output = entry.get('output', '')
        # pull code block
        match = fence_backtick.search(output) or fence_html.search(output)
        if not match:
            print(f"[extract] No code fence in entry {i}; skipping")
            skipped += 1
            continue

        code_body = match.group('code').strip()

        # inject missing headers
        missing = []
        for hdr in COMMON_HEADERS:
            inc = f'#include {hdr}'
            if inc not in code_body:
                missing.append(inc)

        full_code = ("\n".join(missing) + "\n\n" if missing else "") + code_body + "\n"

        # build descriptive filename
        vtype   = entry.get('vulnerability_type', '')
        subtype = entry.get('subtype') or ''
        context = entry.get('context', '')

        parts = [f"{i:03d}", slugify(vtype)]
        if subtype:
            parts.append(slugify(subtype))
        if context:
            parts.append(slugify(context))

        fname = "_".join(parts) + ".c"
        path  = os.path.join(out_dir, fname)

        with open(path, 'w') as cf:
            cf.write(full_code)
        print(f"[extract] Wrote {path} (injected {len(missing)} headers)")

        # map descriptive fname → original prompt text
        prompts_map[fname] = entry.get('prompt', entry.get('input', ''))

    extracted = total_entries - skipped
    print(f"[extract] Extracted {extracted}/{total_entries} .c files to {out_dir}")
    return prompts_map, skipped, total_entries


def compile_c_files(c_dir):
    """
    Try to compile each .c file in c_dir with gcc -std=gnu11 -Wall.
    Returns a dict mapping filename -> (success: bool, stderr: str).
    Removes any non-.c artifacts afterwards.
    """
    compile_results = {}

    for fname in sorted(os.listdir(c_dir)):
        if not fname.endswith('.c'):
            continue

        src_path = os.path.join(c_dir, fname)
        bin_path = os.path.join(c_dir, fname[:-2] + '.out')
        cmd = ['gcc', '-std=gnu11', '-Wall', src_path, '-o', bin_path]

        try:
            subprocess.run(cmd, check=True,
                           stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE,
                           text=True)
            compile_results[fname] = (True, "")
        except subprocess.CalledProcessError as e:
            compile_results[fname] = (False, e.stderr)

    # cleanup any binaries or other files
    for other in os.listdir(c_dir):
        if not other.endswith('.c'):
            os.remove(os.path.join(c_dir, other))

    return compile_results


def main():
    print("[main] Starting code extraction")

    filename = input("Enter the model result filename (e.g., reverse/qwen2/qwen2_reverse_prompting_full.json): ").strip()
    path_parts = Path(filename).parts

    if len(path_parts) < 2:
        print("[error] Expected format: <mode>/<model>/<file.json>")
        return

    mode, model = path_parts[0], path_parts[1]
    if mode not in {"dynamic", "reverse"}:
        print(f"[error] Invalid mode: {mode}. Must be 'dynamic' or 'reverse'.")
        return

    file_path = Path(__file__).resolve().parent / f"../../model-outputs/{mode}" / model / path_parts[2]
    c_out_dir = Path(__file__).resolve().parent / f"../../c-code/{mode}" / model

    if not file_path.exists():
        print(f"[error] File not found: {file_path}")
        return

    os.makedirs(c_out_dir, exist_ok=True)

    prompts_map, skipped, total = extract_c_files(file_path, c_out_dir)

    print(f"[compile] Checking compilability in {c_out_dir}")
    comp_results = compile_c_files(c_out_dir)
    succ = sum(1 for ok, _ in comp_results.values() if ok)
    fail = len(comp_results) - succ

    for fname, (ok, _) in comp_results.items():
        if not ok:
            os.remove(os.path.join(c_out_dir, fname))
            print(f"[cleanup] Removed non-compilable source: {fname}")

    print(f"[compile] {succ}/{succ+fail} files compiled successfully, {fail} failed")
    print(f"[summary] Mode={mode}, Model={model}: no code: {skipped}, compilable: {succ}, non-compilable: {fail}")
    print("[main] All code processed.")



if __name__ == '__main__':
    main()
