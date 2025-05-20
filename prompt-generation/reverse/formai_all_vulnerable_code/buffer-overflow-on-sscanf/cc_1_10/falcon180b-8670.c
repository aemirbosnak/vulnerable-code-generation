//Falcon-180B DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100
#define MAX_IP_LEN 16

typedef struct {
    char ip[MAX_IP_LEN];
    char action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(char *ip, char action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    strncpy(rules[num_rules].ip, ip, MAX_IP_LEN);
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(char *ip) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    char input[MAX_RULE_LEN];
    char action;

    printf("Enter firewall rules (IP address followed by action: allow or deny):\n");

    while (fgets(input, MAX_RULE_LEN, stdin)!= NULL) {
        if (sscanf(input, "%s %c", rules[num_rules].ip, &action)!= 2) {
            printf("Invalid rule format.\n");
            continue;
        }

        add_rule(rules[num_rules].ip, action);
    }

    printf("Enter IP addresses to check:\n");

    while (fgets(input, MAX_RULE_LEN, stdin)!= NULL) {
        int result = match_rule(input);

        if (result == -1) {
            printf("No rule found for IP address %s.\n", input);
        } else if (result == 'a') {
            printf("IP address %s is allowed.\n", input);
        } else {
            printf("IP address %s is denied.\n", input);
        }
    }

    return 0;
}