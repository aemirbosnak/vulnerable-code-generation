//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
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
    printf("Enter rule action (allow/deny): ");
    char action = getchar();
    printf("Enter protocol (tcp/udp): ");
    char protocol = getchar();
    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);
    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dest_ip);
    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);
    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dest_port);
    rules[num_rules].action = action;
    rules[num_rules].protocol = protocol;
    num_rules++;
}

void print_rules(rule_t rules[], int num_rules) {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %c %c %s -> %s:%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].dest_ip, rules[i].dest_port);
    }
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules);
    add_rule(rules, num_rules);
    add_rule(rules, num_rules);

    print_rules(rules, num_rules);

    return 0;
}