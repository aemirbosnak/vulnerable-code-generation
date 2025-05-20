//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule(char* ip, char action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[num_rules].ip, ip);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(char* ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    char line[MAX_RULE_LENGTH];
    char ip[MAX_IP_LENGTH];
    char action;

    printf("Enter rules in the format <IP> <A/D>\n");

    while (fgets(line, MAX_RULE_LENGTH, stdin)!= NULL) {
        if (sscanf(line, "%15s %c", ip, &action) == 2) {
            add_rule(ip, action);
        } else {
            printf("Invalid rule format.\n");
        }
    }

    while (1) {
        printf("Enter an IP address to check: ");
        fgets(ip, MAX_IP_LENGTH, stdin);

        int result = match_rule(ip);

        if (result == -1) {
            printf("No matching rule found.\n");
        } else if (result == 'A') {
            printf("Access allowed.\n");
        } else {
            printf("Access denied.\n");
        }
    }

    return 0;
}