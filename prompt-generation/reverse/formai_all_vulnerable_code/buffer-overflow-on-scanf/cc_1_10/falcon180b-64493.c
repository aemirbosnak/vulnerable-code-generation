//Falcon-180B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_ADDRESS_LENGTH 16

struct rule {
    char action;
    char protocol[10];
    char source_ip[MAX_IP_ADDRESS_LENGTH];
    char dest_ip[MAX_IP_ADDRESS_LENGTH];
    char source_port[10];
    char dest_port[10];
};

int num_rules = 0;
struct rule rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter rule action (allow/deny): ");
    scanf("%c", &rules[num_rules].action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%s", rules[num_rules].protocol);

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

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %c %s %s:%s -> %s:%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].source_port, rules[i].dest_ip, rules[i].dest_port);
    }
}

int main() {
    printf("Welcome to the Firewall Configuration Utility!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add rule\n");
        printf("2. Print rules\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_rule();
                break;
            case 2:
                print_rules();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}