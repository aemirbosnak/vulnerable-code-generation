//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 80
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 6

typedef struct {
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
    int action;
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *ip, char *port, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        exit(1);
    }

    strncpy(rules[num_rules].ip, ip, MAX_IP_LEN);
    strncpy(rules[num_rules].port, port, MAX_PORT_LEN);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(rule_t *rules, int num_rules, char *ip, char *port) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].action;
        }
    }

    return 0;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "192.168.1.1", "80", 1);
    add_rule(rules, num_rules, "192.168.1.2", "443", 0);
    add_rule(rules, num_rules, "192.168.1.3", "22", 1);

    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        printf("Enter port number: ");
        scanf("%s", port);

        int action = match_rule(rules, num_rules, ip, port);

        if (action == 1) {
            printf("Access allowed.\n");
        } else {
            printf("Access denied.\n");
        }
    }

    return 0;
}