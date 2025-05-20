//Falcon-180B DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    int source_port;
    int dest_port;
    int action;
} Rule;

void add_rule(Rule *rule, int index) {
    printf("Enter source IP: ");
    scanf("%s", rule->source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rule->dest_ip);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", rule->protocol);

    printf("Enter source port: ");
    scanf("%d", &rule->source_port);

    printf("Enter destination port: ");
    scanf("%d", &rule->dest_port);

    printf("Enter action (allow/deny): ");
    scanf("%d", &rule->action);

    if (index == MAX_RULES - 1) {
        printf("\nMaximum number of rules reached.\n");
    }
}

int match_rule(char *ip, int port, Rule *rules, int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, ip) == 0 && rules[i].source_port == port) {
            return rules[i].action;
        } else if (strcmp(rules[i].dest_ip, ip) == 0 && rules[i].dest_port == port) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    Rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        add_rule(rules + num_rules, num_rules);
        num_rules++;
    }

    char packet_ip[16];
    int packet_port;

    while (1) {
        printf("\nEnter packet IP: ");
        scanf("%s", packet_ip);

        printf("Enter packet port: ");
        scanf("%d", &packet_port);

        int action = match_rule(packet_ip, packet_port, rules, num_rules);

        if (action == -1) {
            printf("\nNo matching rule found.\n");
        } else if (action == 0) {
            printf("\nPacket allowed.\n");
        } else {
            printf("\nPacket denied.\n");
        }
    }

    return 0;
}