//Falcon-180B DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char action;
    char protocol;
    char source_ip[MAX_IP_LENGTH];
    char dest_ip[MAX_IP_LENGTH];
    char source_port[6];
    char dest_port[6];
} rule_t;

void add_rule(rule_t rules[], int num_rules) {
    printf("Enter action (allow/deny): ");
    scanf("%c", &rules[num_rules].action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%c", &rules[num_rules].protocol);

    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dest_port);

    num_rules++;
}

void print_rules(rule_t rules[], int num_rules) {
    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%c %c %s -> %s %s:%s\n", rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].dest_ip, rules[i].source_port, rules[i].dest_port);
    }
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("Enter firewall rule (leave blank to finish):\n");
        add_rule(rules, num_rules);
    }

    print_rules(rules, num_rules);

    return 0;
}