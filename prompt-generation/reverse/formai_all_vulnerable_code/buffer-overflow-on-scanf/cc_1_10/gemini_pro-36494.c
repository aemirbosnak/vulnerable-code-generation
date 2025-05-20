//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

// Rule struct
typedef struct rule {
    char *pattern;
    char *action;
} rule_t;

// Rule list
rule_t rules[MAX_RULES];

// Initialize rules
void init_rules() {
    // Rule 1: Block access to malicious website
    rules[0].pattern = "www.maliciouswebsite.com";
    rules[0].action = "block";

    // Rule 2: Allow access to trusted website
    rules[1].pattern = "www.trustedwebsite.com";
    rules[1].action = "allow";
}

// Check if a URL matches a rule
int check_rules(char *url) {
    for (int i = 0; i < MAX_RULES; i++) {
        if (strstr(url, rules[i].pattern)) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    // Initialize rules
    init_rules();

    // Get URL from user
    char url[MAX_RULE_LENGTH];
    printf("Enter URL: ");
    scanf("%s", url);

    // Check if URL matches a rule
    int result = check_rules(url);

    // Take action based on rule
    if (result >= 0) {
        printf("Rule %d matched: %s\n", result + 1, rules[result].action);
    } else {
        printf("No matching rule found.\n");
    }

    return 0;
}