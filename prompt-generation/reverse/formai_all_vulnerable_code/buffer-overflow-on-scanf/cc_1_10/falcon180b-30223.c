//Falcon-180B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char action;
    char protocol;
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(char *action, char *protocol, char *ip, char *port) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[num_rules].action, action);
    strcpy(rules[num_rules].protocol, protocol);
    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);

    num_rules++;
}

void print_rules() {
    printf("Firewall Rules:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d. %c %c %s:%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].ip, rules[i].port);
    }
    printf("\n");
}

int main() {
    printf("Firewall Configuration\n");
    printf("---------------------\n");

    char action;
    char protocol;
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];

    printf("Enter action (allow/deny): ");
    scanf("%c", &action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%c", &protocol);

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter port number: ");
    scanf("%s", port);

    add_rule(action, protocol, ip, port);
    print_rules();

    return 0;
}