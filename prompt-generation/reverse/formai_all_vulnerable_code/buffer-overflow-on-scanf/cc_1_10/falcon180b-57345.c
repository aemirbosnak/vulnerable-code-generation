//Falcon-180B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

struct rule {
    char action;
    char protocol;
    char source_ip[MAX_IP_LENGTH];
    char destination_ip[MAX_IP_LENGTH];
    char source_port[6];
    char destination_port[6];
};

void add_rule(struct rule *rules, int num_rules) {
    printf("Enter action (allow/deny): ");
    scanf("%c", &rules[num_rules].action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%c", &rules[num_rules].protocol);

    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].destination_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].destination_port);

    num_rules++;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("\nEnter firewall rule (or type 'done' to finish):\n");
        add_rule(rules, num_rules);

        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }
    }

    printf("\nFirewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %c %c %s -> %s :%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].destination_ip, rules[i].destination_port);
    }

    return 0;
}