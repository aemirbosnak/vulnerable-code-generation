import os
import json
from pathlib import Path

BASE_DIR    = os.path.dirname(os.path.abspath(__file__))
DATA_PATH   = "../../FormAI-v2/FormAI-v2.json"
OUTPUT_ROOT = "formai_all_vulnerable_code"

# Basic bucket rules
cc_buckets = {
    "cc_1_10": lambda cc: 1 <= cc <= 10,
    "cc_11_20": lambda cc: 11 <= cc <= 20,
    "cc_21_50": lambda cc: 21 <= cc <= 50,
}

def safe_filename(name):
    return name.replace("/", "_").replace("\\", "_")

def main():
    with open(DATA_PATH, "r") as f:
        records = json.load(f)

    count = 0

    for sample in records:
        if sample.get("verification_finished") != "yes":
            continue
        if sample.get("error_type") in [None, "N/A"]:
            continue
        if not sample.get("source_code") or len(sample["source_code"]) < 20:
            continue

        vuln_type = sample["error_type"].split(":")[0].strip().lower().replace(" ", "-")
        try:
            cc = float(sample.get("cyclomatic_complexity", -1))
        except ValueError:
            continue

        # Assign to a complexity bucket
        bucket_name = None
        for name, check in cc_buckets.items():
            if check(cc):
                bucket_name = name
                break
        if not bucket_name:
            continue

        filename = safe_filename(sample["file_name"])
        out_dir = Path(OUTPUT_ROOT) / vuln_type / bucket_name
        out_dir.mkdir(parents=True, exist_ok=True)

        out_file = out_dir / f"{filename}"
        with open(out_file, "w") as fout:
            fout.write(sample["source_code"])

        count += 1

    print(f"[done] Extracted {count} vulnerable files into {OUTPUT_ROOT}")

if __name__ == "__main__":
    main()
