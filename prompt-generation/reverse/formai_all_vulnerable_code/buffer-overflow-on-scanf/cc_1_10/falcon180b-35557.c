//Falcon-180B DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char source[MAX_RULE_LENGTH];
    char destination[MAX_RULE_LENGTH];
    char action[MAX_RULE_LENGTH];
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    printf("Enter number of rules: ");
    scanf("%d", &num_rules);

    for (int i = 0; i < num_rules; i++) {
        printf("Enter rule %d:\n", i+1);
        printf("Source: ");
        scanf("%s", rules[i].source);
        printf("Destination: ");
        scanf("%s", rules[i].destination);
        printf("Action: ");
        scanf("%s", rules[i].action);
    }

    printf("Enter packet source: ");
    char source[MAX_RULE_LENGTH];
    scanf("%s", source);

    printf("Enter packet destination: ");
    char destination[MAX_RULE_LENGTH];
    scanf("%s", destination);

    bool allowed = false;

    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source, source) == 0 && strcmp(rules[i].destination, destination) == 0) {
            if (strcmp(rules[i].action, "allow") == 0) {
                allowed = true;
                break;
            }
        }
    }

    if (allowed) {
        printf("Packet allowed\n");
    } else {
        printf("Packet denied\n");
    }

    return 0;
}