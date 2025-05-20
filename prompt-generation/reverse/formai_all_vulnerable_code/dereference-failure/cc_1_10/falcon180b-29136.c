//Falcon-180B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 100

typedef struct {
    char *rule;
    int action;
} Rule;

Rule rules[MAX_RULES];
int num_rules;

void add_rule(char *rule, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules!\n");
        exit(1);
    }
    rules[num_rules].rule = strdup(rule);
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(char *request) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(request, rules[i].rule) == 0) {
            return rules[i].action;
        }
    }
    return 0;
}

int main() {
    int i;
    char *input;
    char *rule;
    int action;

    printf("Welcome to the Funny C Firewall!\n");

    while (1) {
        printf("Enter a rule (e.g. block https://www.google.com): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        rule = strtok(input, " ");
        action = atoi(strtok(NULL, " "));
        add_rule(rule, action);
    }

    while (1) {
        printf("Enter a request: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        match_rule(input);
    }

    return 0;
}