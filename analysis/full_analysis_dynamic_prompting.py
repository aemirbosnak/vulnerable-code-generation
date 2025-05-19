import os
import json
import sys

import pandas as pd
from collections import Counter

SUMMARY_DIR = "vuln-analysis-summary/dynamic"
OUTPUT_PATH = "../final-summary/dynamic_prompting_full_analysis.txt"

def load_detailed_summary(model_name):
    if "temp" in model_name:
        path = os.path.join(SUMMARY_DIR, f"{model_name}_detailed_summary.json")
    else:
        path = os.path.join(SUMMARY_DIR, f"{model_name}_dynamic_prompt_detailed_summary.json")
    with open(path, 'r') as f:
        data = json.load(f)

    records = []
    for fname, entry in data.items():
        records.append({
            "file_name":            fname,
            "vulnerability_type":   entry.get("vulnerability_type"),
            "subtype":              entry.get("subtype"),
            "intent":               entry.get("intent"),
            "form":                 entry.get("form"),
            "context":              entry.get("context"),
            "prompt":               entry.get("prompt"),
            "temperature":          entry.get("temperature", None),
            "esbmc_output":         entry.get("esbmc_output"),
            "violated_property":    entry.get("violated_property"),
            "parsing_error_reason": entry.get("parsing_error_reason")
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
    if "temp" in model_name:
        path = os.path.join(SUMMARY_DIR, f"{model_name}_executive_summary.json")
    else:
        path = os.path.join(SUMMARY_DIR, f"{model_name}_dynamic_prompt_executive_summary.json")
    with open(path, "r") as f:
        summary = json.load(f)

    print("RQ0: Absolute counts (from executive vuln-analysis-summary)")
    print(f" Total prompts:    {summary['total_prompts']}")
    print(f" Code generated:   {summary.get('code_generated', 'N/A')}")
    print(f" Compilable code:  {summary.get('compilable_code', 'N/A')}\n")

    print("--- Status Breakdown ---")
    for status, count in summary["status_counts"].items():
        if isinstance(count, dict):  # e.g. parsing error breakdown
            print(f"{status}: {count['total']}")
            for reason, subcount in count.items():
                if reason != "total":
                    print(f"  └── {reason}: {subcount}")
        else:
            print(f"{status}: {count}")
    print()

    if "temperature_breakdown" in summary:
        print("Temperature sample sizes:")
        for temp, count in summary["temperature_breakdown"].items():
            print(f" T={temp}: {count} prompts")
        print()

def analyze_rq1(df):
    print("RQ1: Vulnerable‐code and correct‐vuln counts")
    if "temperature" in df.columns and df["temperature"].notnull().any():
        for t in sorted(df["temperature"].dropna().unique()):
            print(f"\n→ Temperature {t}")
            tdf = df[df["temperature"] == t]
            vuln_df = tdf[tdf["vulnerable_code"] == 1]
            counts = vuln_df["vulnerability_type"].value_counts()
            corrects = vuln_df.groupby("vulnerability_type")["correct_vulnerability"].sum()
            print(pd.DataFrame({
                "vuln_code_count": counts,
                "correct_vuln_count": corrects
            }))
    else:
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
    if "temperature" in df.columns and df["temperature"].notnull().any():
        for t in sorted(df["temperature"].dropna().unique()):
            print(f"\n→ Temperature {t}")
            tdf = df[df["temperature"] == t]
            stats = tdf.groupby("intent").agg(
                vuln_count=("vulnerable_code", "sum"),
                correct_vuln_count=("correct_vulnerability", "sum"),
            )
            print(stats)
    else:
        stats = df.groupby("intent").agg(
            vuln_count=("vulnerable_code", "sum"),
            correct_vuln_count=("correct_vulnerability", "sum"),
        )
        print(stats)
    print()

def analyze_rq3(df):
    print("RQ3: By form (absolute counts)")
    if "temperature" in df.columns and df["temperature"].notnull().any():
        for t in sorted(df["temperature"].dropna().unique()):
            print(f"\n→ Temperature {t}")
            tdf = df[df["temperature"] == t]
            stats = tdf.groupby("form").agg(
                vuln_count=("vulnerable_code", "sum"),
                correct_vuln_count=("correct_vulnerability", "sum"),
            )
            print(stats)
    else:
        stats = df.groupby("form").agg(
            vuln_count=("vulnerable_code", "sum"),
            correct_vuln_count=("correct_vulnerability", "sum"),
        )
        print(stats)
    print()

def analyze_incorrect_vulnerabilities(df, top_n=10):
    """
    When the model generates *some* vulnerability but not the one requested,
    what types of violations were actually produced?
    This function analyzes the mapping: expected subtype/type → actual violated_property.
    """
    print("RQ4: Incorrect Vulnerability Generation Patterns\n")

    mismatch_counter = Counter()
    violated_counter = Counter()

    for _, row in df.iterrows():
        if row["vulnerable_code"] == 1 and row["correct_vulnerability"] == 0:
            expected = (row["subtype"] or row["vulnerability_type"] or "unknown").replace("-", " ").lower()
            violated = (row["violated_property"] or "unknown").lower().strip()
            mismatch_counter[(expected, violated)] += 1
            violated_counter[violated] += 1

    if not mismatch_counter:
        print("No mismatches found.\n")
        return

    # ——— Top Expected → Violated Mappings ———
    mismatch_df = pd.DataFrame([
        {"expected": e, "violated": v, "count": c}
        for (e, v), c in mismatch_counter.items()
    ])
    mismatch_df = mismatch_df.sort_values(by="count", ascending=False)

    print("Top Unexpected Vulnerability Mappings (Expected → Violated):\n")
    print(mismatch_df.to_string(index=False))
    print()

    # ——— Summary of Most Frequently Generated Violated Properties ———
    top_violated = violated_counter.most_common(top_n)
    print(f"Top {top_n} Most Common Violated Vulnerabilities When Incorrectly Generated:\n")
    for violated, count in top_violated:
        print(f" {violated:<60} {count:>5}")
    print()

def run_complete_analysis():
    models = [
        "qwen2", "mistral", "gemma",
        "qwen2_temp_sample",
        "mistral_temp_sample",
        "gemma_temp_sample"
    ]

    with open(OUTPUT_PATH, "w") as f:
        sys.stdout = f
        for m in models:
            print(f"\n=== ANALYSIS FOR {m.upper()} ===\n")
            analyze_rq0(m)
            df = load_detailed_summary(m)
            df = prepare_dataframe(df)
            analyze_rq1(df)
            analyze_rq2(df)
            analyze_rq3(df)
            analyze_incorrect_vulnerabilities(df)
        sys.stdout = sys.__stdout__  # reset stdout

if __name__ == "__main__":
    run_complete_analysis()
