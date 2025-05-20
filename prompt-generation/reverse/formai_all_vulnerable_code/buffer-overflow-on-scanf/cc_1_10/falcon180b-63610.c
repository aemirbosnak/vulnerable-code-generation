//Falcon-180B DATASET v1.0 Category: Firewall ; Style: sophisticated
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
    char action;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(char *ip, char *port, char action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }
    strncpy(rules[num_rules].ip, ip, MAX_IP_LEN);
    strncpy(rules[num_rules].port, port, MAX_PORT_LEN);
    rules[num_rules].action = action;
    num_rules++;
}

int check_rule(char *ip, char *port) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].action;
        }
    }
    return -1;
}

int main() {
    add_rule("192.168.1.1", "80", 'A');
    add_rule("192.168.1.2", "443", 'A');
    add_rule("192.168.1.3", "22", 'D');
    add_rule("192.168.1.4", "25", 'D');

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", rules[num_rules].ip);
        printf("Enter port number: ");
        scanf("%s", rules[num_rules].port);
        printf("Enter action (A - Allow, D - Deny): ");
        scanf(" %c", &rules[num_rules].action);
        num_rules++;
    }

    return 0;
}