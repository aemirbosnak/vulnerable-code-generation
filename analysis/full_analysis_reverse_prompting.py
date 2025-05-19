import os
import json
import pandas as pd

SUMMARY_DIR = "vuln-analysis-summary/reverse"

def load_detailed_summary(model_name):
    path = os.path.join(SUMMARY_DIR, f"{model_name}_reverse_prompt_detailed_summary.json")
    with open(path, 'r') as f:
        data = json.load(f)

    records = []
    for fname, entry in data.items():
        records.append({
            "file_name":                fname,
            "vulnerability_type":       entry.get("vulnerability_type"),
            "subtype":                  entry.get("subtype"),
            "intent":                   entry.get("intent"),
            "form":                     entry.get("form"),
            "context":                  entry.get("context"),
            "prompt":                   entry.get("prompt"),
            "esbmc_output":             entry.get("esbmc_output"),
            "violated_property":        entry.get("violated_property"),
            "parsing_error_reason":     entry.get("parsing_error_reason"),
            "cyclomatic_complexity":    entry.get("cyclomatic_complexity"),
        })
    return pd.DataFrame(records)

def prepare_dataframe(df):
    df["vulnerable_code"] = df["esbmc_output"] == "VERIFICATION FAILED"

    def check_correct(row):
        vp = str(row["violated_property"] or "").lower()
        vt = str(row["vulnerability_type"] or "").lower()
        st = str(row["subtype"] or "").lower()

        if vt == "integer-overflow":
            if "arithmetic overflow" in vp:
                return True

        elif vt == "buffer-overflow":
            if any(x in vp for x in ["buffer overflow", "overflow on scanf", "overflow on gets", "overflow on sscanf",
                                     "overflow on fscanf"]):
                return True

        elif vt == "dereference-failure":
            if any(x in vp for x in ["null pointer", "invalid pointer", "dereference"]):
                return True

        elif vt == "use-after-free":
            if any(x in vp for x in ["use after free", "pointer offset", "free"]):
                return True

        elif vt == "out-of-bounds":
            if "array bounds" in vp or "index out of range" in vp:
                return True

        # fallback: conservative match on both vuln type and subtype
        return (vt in vp) or (st and st in vp)

    df["correct_vulnerability"] = df.apply(check_correct, axis=1)
    for col in ["vulnerable_code", "correct_vulnerability"]:
        df[col] = df[col].astype(bool).astype(int)

    return df

def analyze_rq0(model_name):
    path = os.path.join(SUMMARY_DIR, f"{model_name}_reverse_prompt_executive_summary.json")
    with open(path, "r") as f:
        summary = json.load(f)

    print("RQ0: Absolute counts (from executive vuln-analysis-summary)")
    print(f" Total prompts:    {summary['total_prompts']}")
    print(f" Code generated:   {summary.get('code_generated', 'N/A')}")
    print(f" Compilable code:  {summary.get('compilable_code', 'N/A')}\n")

    print("--- Status Breakdown ---")
    for status, count in summary["status_counts"].items():
        if isinstance(count, dict):
            print(f"{status}: {count['total']}")
            for reason, subcount in count.items():
                if reason != "total":
                    print(f"  └── {reason}: {subcount}")
        else:
            print(f"{status}: {count}")
    print()

def analyze_rq1(df):
    print("RQ1: Vulnerable‐code and correct‐vuln counts")
    vuln_df = df[df["vulnerable_code"] == 1]
    counts = vuln_df["vulnerability_type"].value_counts()
    corrects = vuln_df.groupby("vulnerability_type")["correct_vulnerability"].sum()
    print(pd.DataFrame({
        "vuln_code_count": counts,
        "correct_vuln_count": corrects
    }))
    print()

def analyze_rq2(df):
    print("RQ2: By intent (absolute counts)")
    stats = df.groupby("intent").agg(
        vuln_count=("vulnerable_code", "sum"),
        correct_vuln_count=("correct_vulnerability", "sum"),
    )
    print(stats)
    print()

def analyze_rq3(df):
    print("RQ3: By form (absolute counts)")
    stats = df.groupby("form").agg(
        vuln_count=("vulnerable_code", "sum"),
        correct_vuln_count=("correct_vulnerability", "sum"),
    )
    print(stats)
    print()

def analyze_cc_distribution(df):
    print("RQ5: Cyclomatic Complexity Analysis\n")

    # ——— General Stats ———
    all_mean = df["cyclomatic_complexity"].mean()
    vuln_mean = df[df["vulnerable_code"] == 1]["cyclomatic_complexity"].mean()
    correct_mean = df[df["correct_vulnerability"] == 1]["cyclomatic_complexity"].mean()

    print(f"Average CC (all samples):       {all_mean:.2f}")
    print(f"Average CC (vulnerable code):   {vuln_mean:.2f}")
    print(f"Average CC (correct vulnerability): {correct_mean:.2f}\n")

    # ——— Fine-grained CC Buckets ———
    print("Vulnerable Code by Cyclomatic Complexity Buckets:\n")
    buckets = pd.cut(
        df["cyclomatic_complexity"],
        bins=[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 100],
        include_lowest=True
    )
    grouped = df.groupby(buckets, observed=False).agg(
        total_samples=("file_name", "count"),
        vuln_code_count=("vulnerable_code", "sum"),
        correct_vuln_count=("correct_vulnerability", "sum")
    )
    grouped["vuln_rate (%)"] = (grouped["vuln_code_count"] / grouped["total_samples"]) * 100
    grouped["correct_rate (%)"] = (grouped["correct_vuln_count"] / grouped["total_samples"]) * 100
    print(grouped.round(2))
    print()

    # ——— Per Vulnerability Type in Each Bucket ———
    print("Vulnerability Breakdown by Type and CC Bucket (only vulnerable code):\n")
    vuln_df = df[df["vulnerable_code"] == 1].copy()
    vuln_df["cc_bin"] = pd.cut(
        vuln_df["cyclomatic_complexity"],
        bins=[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 100],
        include_lowest=True
    )

    pivot = pd.pivot_table(
        vuln_df,
        index="cc_bin",
        columns="vulnerability_type",
        values="file_name",
        aggfunc="count",
        fill_value=0,
        observed=False,
    )
    print(pivot)
    print()

def run_complete_analysis():
    models = ["qwen2", "mistral", "gemma"]
    for m in models:
        print(f"\n=== ANALYSIS FOR {m.upper()} (REVERSE PROMPTING) ===\n")
        analyze_rq0(m)
        df = load_detailed_summary(m)
        df = prepare_dataframe(df)
        analyze_rq1(df)
        analyze_rq2(df)
        analyze_rq3(df)
        analyze_cc_distribution(df)

if __name__ == "__main__":
    run_complete_analysis()
