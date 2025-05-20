//Falcon-180B DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_FILTER_LENGTH 20

typedef struct {
    char *filter;
    int action;
} rule_t;

void add_rule(rule_t rules[], int num_rules, char *filter, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    rules[num_rules].filter = strdup(filter);
    rules[num_rules].action = action;

    num_rules++;
}

int match_filter(rule_t rule, char *data) {
    int i, j;

    for (i = 0; i < strlen(rule.filter); i++) {
        if (rule.filter[i] == '*') {
            while (isalnum(data[j])) {
                j++;
            }
        } else if (tolower(rule.filter[i])!= tolower(data[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "*.txt", 1);
    add_rule(rules, num_rules, "*.exe", 0);

    char input_file[MAX_FILTER_LENGTH];

    while (1) {
        printf("Enter file name: ");
        scanf("%s", input_file);

        int matched_rule = 0;

        for (int i = 0; i < num_rules; i++) {
            if (match_filter(rules[i], input_file)) {
                matched_rule = 1;
                break;
            }
        }

        if (matched_rule) {
            if (rules[matched_rule-1].action == 1) {
                printf("File allowed.\n");
            } else {
                printf("File blocked.\n");
            }
        } else {
            printf("No rule found.\n");
        }
    }

    return 0;
}