//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char *rule;
    int action;
} Rule;

int main() {
    int num_rules = 0;
    Rule rules[MAX_RULES];

    printf("Welcome to the C Firewall!\n");
    printf("Enter rules in the format: \"<rule> <allow/deny>\", e.g. \"tcp 80 allow\".\n");
    printf("Enter \"done\" when finished.\n");

    while (1) {
        char rule[MAX_RULE_LENGTH];
        char action[10];

        printf("Enter rule: ");
        scanf("%s", rule);

        if (strcmp(rule, "done") == 0) {
            break;
        }

        printf("Enter action (allow/deny): ");
        scanf("%s", action);

        if (strcmp(action, "allow") == 0 || strcmp(action, "deny") == 0) {
            rules[num_rules].rule = strdup(rule);
            rules[num_rules].action = (strcmp(action, "allow") == 0)? 1 : 0;
            num_rules++;
        } else {
            printf("Invalid action.\n");
        }
    }

    printf("\nFirewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s %s\n", rules[i].rule, rules[i].action? "allow" : "deny");
    }

    return 0;
}