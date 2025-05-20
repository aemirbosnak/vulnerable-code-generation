//Falcon-180B DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char action;
    char protocol[10];
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
};

void add_rule(struct rule *rules, int num_rules) {
    printf("Enter rule action (allow/deny): ");
    scanf("%c", &rules[num_rules].action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%d", &rules[num_rules].dest_port);
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("Enter firewall rule (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_rule(rules, num_rules);
            num_rules++;
        } else {
            break;
        }
    }

    printf("\nFirewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %c %s %s:%d -> %s:%d\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].source_port, rules[i].dest_ip, rules[i].dest_port);
    }

    return 0;
}