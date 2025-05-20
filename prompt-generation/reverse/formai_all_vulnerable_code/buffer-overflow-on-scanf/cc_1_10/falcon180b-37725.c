//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *rule;
    int deny;
} Rule;

Rule rules[MAX_RULES];
int num_rules;

void add_rule(char *rule) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    rules[num_rules].rule = strdup(rule);
    rules[num_rules].deny = 0;

    num_rules++;
}

void deny_rule(int index) {
    rules[index].deny = 1;
}

int check_rule(char *input) {
    for (int i = 0; i < num_rules; i++) {
        if (strstr(input, rules[i].rule)!= NULL && rules[i].deny == 1) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char input[MAX_RULE_LENGTH];

    printf("Enter a rule (e.g. deny \"example.com\"):\n");
    scanf("%s", input);

    add_rule(input);

    printf("Enter a URL to check:\n");
    scanf("%s", input);

    if (check_rule(input)) {
        printf("Denied!\n");
    } else {
        printf("Allowed.\n");
    }

    return 0;
}