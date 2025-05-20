//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_PATTERN_SIZE 1024
#define MAX_RULES 1024

// Rule structure
typedef struct {
    char *pattern;
    char *action;
} Rule;

// Function prototypes
int load_rules(Rule *rules, int max_rules);
int match_rule(char *line, Rule *rules, int num_rules);

int main() {
    char line[MAX_LINE_SIZE];
    Rule rules[MAX_RULES];
    int num_rules;

    // Load rules
    num_rules = load_rules(rules, MAX_RULES);

    // Read input
    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        // Match rule
        if (match_rule(line, rules, num_rules)) {
            printf("Intrusion detected!\n");
        }
    }

    return 0;
}

int load_rules(Rule *rules, int max_rules) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int num_rules = 0;

    fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open rules file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (num_rules >= max_rules) {
            printf("Error: Too many rules.\n");
            exit(1);
        }

        char *pattern = strtok(line, " ");
        char *action = strtok(NULL, " ");

        if (pattern == NULL || action == NULL) {
            printf("Error: Invalid rule format.\n");
            exit(1);
        }

        rules[num_rules].pattern = strdup(pattern);
        rules[num_rules].action = strdup(action);

        num_rules++;
    }

    fclose(fp);

    return num_rules;
}

int match_rule(char *line, Rule *rules, int num_rules) {
    char *word;
    int i;

    word = strtok(line, " ");
    while (word!= NULL) {
        for (i = 0; i < num_rules; i++) {
            if (strcmp(word, rules[i].pattern) == 0) {
                printf("Rule triggered: %s\n", rules[i].action);
                return 1;
            }
        }
        word = strtok(NULL, " ");
    }

    return 0;
}