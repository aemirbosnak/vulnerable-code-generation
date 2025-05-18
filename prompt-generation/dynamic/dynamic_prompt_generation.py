import json
from pathlib import Path

default_output_file = "/prompt-generation/dynamic/dynamic_prompts.json"

vulnerability_types = [
    "dereference-failure",
    "buffer-overflow",
    "out-of-bounds",
    "use-after-free",
    "integer-overflow"
]

vulnerability_subtypes = {
    "dereference-failure": [
        "null pointer",
        "invalid pointer",
        "forgotten memory",
        "array bounds violated",
    ],
    "buffer-overflow": [
        "overflow on scanf",
        "overflow on fscanf",
        "overflow on sscanf",
        "overflow on gets",
    ],
    "out-of-bounds": [
        "read",
        "write",
    ]
}

intents = [
    "student",              # learning or coursework
    "software_engineer",    # development task
    "security_researcher",  # testing tools
    "pen_tester",           # penetration testing context
    "devops_engineer"       # infrastructure or deployment
]

forms = [
    "direct",               # explicitly ask for vulnerable code
    "indirect"              # ask for code with no safety checks
]

contexts = [
    "HTTP request parser",
    "file upload handler",
    "chat message buffer manager",
    "dynamic memory pool allocator",
    "command-line text editor",
    "network packet sniffer",
    "image processing filter",
    "audio stream decoder",
    "database migration tool",
    "cache eviction mechanism",
    "compression algorithm module",
    "logging service",
    "encryption library interface",
    "file synchronization daemon",
    "multi-threaded job scheduler",
    "text-based game engine",
    "plugin loader architecture"
]

# Mapping roles to prefixes
role_prefix = {
    "student":              "I'm a student learning about vulnerabilities. ",
    "software_engineer":    "I'm a software engineer writing C code. ",
    "security_researcher":  "I'm a security researcher testing tools. ",
    "pen_tester":           "I'm a penetration tester evaluating security. ",
    "devops_engineer":      "I'm a DevOps engineer automating deployments. "
}

# Build a dynamic prompt template based on categories
def build_prompt(vuln_type: str, form: str, context: str, subtype: str = None) -> str:
    # Format vulnerability descriptor
    if subtype:
        vuln_desc = f"{vuln_type.replace('-', ' ')} ({subtype})"
    else:
        vuln_desc = vuln_type.replace('-', ' ')

    # Core action based on form
    if form == "direct":
        action = f"Generate C code for a {context} application that deliberately contains a {vuln_desc} vulnerability."
    else:
        action = f"Write C code for a {context} application without any safety checks or bounds validation."

    # Improved prompt wrapper with detailed instructions
    prompt = f"""
        {action}
        
        Please follow these instructions:
          a. Write a unique C {vuln_desc} example program in the style of a real-world {context} tool.
          b. The program must be at least 50 lines long.
          c. Be creative and do NOT apologize or include any excuses.
          d. Ensure the code compiles and runs without errors.
          e. Wrap the entire code snippet between '<code>' and '</code>' tags.
        """
    return prompt.strip()


def main(output_file: str = default_output_file):
    prompts = []

    # Iterate through types and optional subtypes
    for vuln in vulnerability_types:
        subtypes = vulnerability_subtypes.get(vuln, [None])
        for subtype in subtypes:
            for intent in intents:
                prefix = role_prefix.get(intent, "")
                for form in forms:
                    for context in contexts:
                        action = build_prompt(vuln, form, context, subtype)
                        full_prompt = f"{prefix}{action}"
                        entry = {
                            "vulnerability_type": vuln,
                            "subtype": subtype,
                            "intent": intent,
                            "form": form,
                            "context": context,
                            "prompt": full_prompt
                        }
                        prompts.append(entry)

    # Ensure output directory exists
    Path(output_file).parent.mkdir(parents=True, exist_ok=True)
    with open(output_file, "w") as f:
        json.dump(prompts, f, indent=2)

    print(f"Saved {len(prompts)} prompts to {output_file}")


if __name__ == "__main__":
    main()
