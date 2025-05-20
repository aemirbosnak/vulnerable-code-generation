//Falcon-180B DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

typedef struct {
    char ip[16];
    char mask[16];
    char action;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(char* ip, char* mask, char action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached!\n");
        return;
    }

    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].mask, mask);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(char* ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(ip, rules[i].ip) == 0) {
            return rules[i].action;
        }
    }

    return 0;
}

int main() {
    add_rule("192.168.1.0", "255.255.255.0", 1);
    add_rule("192.168.2.0", "255.255.255.0", 0);

    char ip[16];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        int action = match_rule(ip);

        if (action == 1) {
            printf("Allowed\n");
        } else {
            printf("Denied\n");
        }
    }

    return 0;
}