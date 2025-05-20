//Falcon-180B DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    int source_port;
    int dest_port;
    int action;
};

void add_rule(struct rule *rules, int num_rules) {
    printf("Enter the source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter the destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter the protocol (TCP or UDP): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter the source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter the destination port: ");
    scanf("%d", &rules[num_rules].dest_port);

    printf("Enter the action (allow or deny): ");
    scanf("%d", &rules[num_rules].action);

    num_rules++;
}

void print_rules(struct rule *rules, int num_rules) {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i + 1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Dest IP: %s\n", rules[i].dest_ip);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source Port: %d\n", rules[i].source_port);
        printf("Dest Port: %d\n", rules[i].dest_port);
        printf("Action: %s\n\n", rules[i].action == 0? "allow" : "deny");
    }
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("Enter 'a' to add a rule or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'a' || choice == 'A') {
            add_rule(rules, num_rules);
        } else if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    print_rules(rules, num_rules);

    return 0;
}