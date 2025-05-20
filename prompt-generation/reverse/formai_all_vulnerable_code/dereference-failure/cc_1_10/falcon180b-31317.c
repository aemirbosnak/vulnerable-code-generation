//Falcon-180B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 1000

typedef struct {
    char *rule;
    int action;
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *rule, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules\n");
        exit(1);
    }

    int rule_length = strlen(rule);
    if (rule_length >= MAX_RULE_LENGTH) {
        printf("Error: Rule is too long\n");
        exit(1);
    }

    rules[num_rules].rule = malloc(rule_length + 1);
    strcpy(rules[num_rules].rule, rule);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(rule_t *rules, int num_rules, char *input) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].rule, input) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "allow 192.168.0.1", 1);
    add_rule(rules, num_rules, "deny 192.168.0.2", 0);
    add_rule(rules, num_rules, "allow 10.0.0.1", 1);

    char input[MAX_RULE_LENGTH];

    while (1) {
        printf("Enter an IP address: ");
        fgets(input, MAX_RULE_LENGTH, stdin);

        int action = match_rule(rules, num_rules, input);

        if (action == 1) {
            printf("Allowed\n");
        } else if (action == 0) {
            printf("Denied\n");
        } else {
            printf("No rule found\n");
        }
    }

    return 0;
}