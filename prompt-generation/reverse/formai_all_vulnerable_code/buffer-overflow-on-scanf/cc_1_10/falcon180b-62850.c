//Falcon-180B DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *ip, char *port, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(rule_t *rules, int num_rules, char *ip, char *port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].action;
        }
    }

    return 0;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "192.168.0.1", "80", 1);
    add_rule(rules, num_rules, "192.168.0.2", "443", 0);

    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        printf("Enter port number: ");
        scanf("%s", port);

        int action = match_rule(rules, num_rules, ip, port);

        if (action == 1) {
            printf("Access granted.\n");
        } else {
            printf("Access denied.\n");
        }
    }

    return 0;
}