//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    int port;
    int action;
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *ip, int port, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    strncpy(rules[num_rules].ip, ip, MAX_IP_LENGTH);
    rules[num_rules].port = port;
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(rule_t *rules, int num_rules, char *ip, int port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && rules[i].port == port) {
            return rules[i].action;
        }
    }
    return 0;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "192.168.1.1", 80, 1);
    add_rule(rules, num_rules, "192.168.1.2", 443, 1);
    add_rule(rules, num_rules, "192.168.1.3", 22, 0);

    char input_ip[MAX_IP_LENGTH];
    int input_port;

    while (1) {
        printf("Enter an IP address and port number (e.g. 192.168.1.1:80): ");
        scanf("%s:%d", input_ip, &input_port);

        int action = match_rule(rules, num_rules, input_ip, input_port);

        if (action == 1) {
            printf("Access allowed.\n");
        } else if (action == 0) {
            printf("Access denied.\n");
        } else {
            printf("Invalid rule.\n");
        }
    }

    return 0;
}