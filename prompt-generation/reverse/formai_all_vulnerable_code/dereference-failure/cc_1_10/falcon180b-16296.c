//Falcon-180B DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define ALLOW 1
#define DENY 0

typedef struct {
    char ip[16];
    char port[6];
    int action;
} rule_t;

int main() {
    int num_rules = 0;
    rule_t rules[MAX_RULES];
    char input[MAX_RULE_LENGTH];
    char *token;

    printf("Enter firewall rules in the format <IP>:<Port>:<Allow/Deny>\n");

    while (fgets(input, MAX_RULE_LENGTH, stdin)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Maximum number of rules (%d) reached.\n", MAX_RULES);
            break;
        }

        token = strtok(input, ":");
        strcpy(rules[num_rules].ip, token);
        token = strtok(NULL, ":");
        strcpy(rules[num_rules].port, token);
        rules[num_rules].action = ALLOW; // default action is allow

        if (strcmp(token, "Deny") == 0) {
            rules[num_rules].action = DENY;
        }

        num_rules++;
    }

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s:%s %s\n", rules[i].ip, rules[i].port, rules[i].action == ALLOW? "Allow" : "Deny");
    }

    return 0;
}