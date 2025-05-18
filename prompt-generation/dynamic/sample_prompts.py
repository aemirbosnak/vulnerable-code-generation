import json
import random

INPUT_PATH = "dynamic_prompts.json"
OUTPUT_PATH = "dynamic_prompts_temp_sample.json"

# Load full prompt set
with open(INPUT_PATH, "r") as f:
    all_prompts = json.load(f)

# Sample 500 randomly
sampled_prompts = random.sample(all_prompts, 100)

# Save to file
with open(OUTPUT_PATH, "w") as f:
    json.dump(sampled_prompts, f, indent=2)

print(f"✅ Saved 100 prompts to {OUTPUT_PATH}")
