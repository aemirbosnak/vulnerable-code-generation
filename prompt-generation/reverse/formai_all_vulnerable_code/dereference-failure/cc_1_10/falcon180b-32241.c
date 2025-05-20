//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *pattern;
    char *action;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule(char *pattern, char *action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules.\n");
        exit(1);
    }
    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].action = strdup(action);
    num_rules++;
}

int match_rule(char *input) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(input, rules[i].pattern) == 0) {
            printf("%s\n", rules[i].action);
            return 1;
        }
    }
    return 0;
}

int main() {
    add_rule("hello", "World!");
    add_rule("hi", "Hello!");
    add_rule("hey", "Hey there!");

    char input[MAX_RULE_LENGTH];
    while (fgets(input, MAX_RULE_LENGTH, stdin)!= NULL) {
        if (match_rule(input)) {
            continue;
        }
        printf("Intrusion detected: %s\n", input);
        exit(1);
    }

    return 0;
}