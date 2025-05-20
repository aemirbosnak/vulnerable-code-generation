//Falcon-180B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define ALLOW 1
#define DENY 0

typedef struct {
    char rule[MAX_RULE_LENGTH];
    int action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(char* new_rule) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[num_rules].rule, new_rule);
    rules[num_rules].action = ALLOW;
    num_rules++;
}

int match_rule(char* request) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strstr(request, rules[i].rule)!= NULL) {
            return rules[i].action;
        }
    }

    return DENY;
}

int main() {
    char buffer[1024];
    char* request;
    int action;

    printf("Welcome to the C Firewall!\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);

        request = strtok(buffer, " ");

        if (strcmp(request, "ADD_RULE") == 0) {
            request = strtok(NULL, " ");
            add_rule(request);
        } else if (strcmp(request, "REQUEST") == 0) {
            request = strtok(NULL, " ");
            action = match_rule(request);

            if (action == ALLOW) {
                printf("Request allowed.\n");
            } else {
                printf("Request denied.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}