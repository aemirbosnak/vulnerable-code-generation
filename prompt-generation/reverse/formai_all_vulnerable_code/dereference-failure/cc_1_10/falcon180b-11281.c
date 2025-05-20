//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

struct rule {
    char *pattern;
    int action;
};

void load_rules(struct rule *rules, int num_rules) {
    FILE *f;
    char line[MAX_RULE_LEN];
    int i = 0;

    f = fopen("rules.txt", "r");
    if (f == NULL) {
        printf("Error: could not open rules.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_RULE_LEN, f)!= NULL) {
        if (i >= num_rules) {
            printf("Error: too many rules\n");
            exit(1);
        }

        rules[i].pattern = strdup(line);
        rules[i].action = 0; // default action is allow
        i++;
    }

    fclose(f);
}

int match_rule(struct rule *rules, int num_rules, char *input) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].pattern, input) == 0) {
            return rules[i].action;
        }
    }

    return 0; // no match found
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules;
    char input[MAX_RULE_LEN];

    printf("Enter the number of rules: ");
    scanf("%d", &num_rules);

    load_rules(rules, num_rules);

    while (1) {
        printf("Enter a string to check: ");
        fgets(input, MAX_RULE_LEN, stdin);

        int action = match_rule(rules, num_rules, input);

        if (action == 0) {
            printf("String allowed\n");
        } else {
            printf("String denied\n");
        }
    }

    return 0;
}