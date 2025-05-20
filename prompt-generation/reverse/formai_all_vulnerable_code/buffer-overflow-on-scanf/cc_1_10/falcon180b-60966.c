//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Claude Shannon
/* C Firewall example program in a Claude Shannon style */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    int source_port;
    int dest_port;
    int action;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

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

void print_rules() {
    printf("Number of rules: %d\n", num_rules);
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].dest_ip);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source Port: %d\n", rules[i].source_port);
        printf("Destination Port: %d\n", rules[i].dest_port);
        printf("Action: %s\n\n", rules[i].action == 0? "Allow" : "Deny");
    }
}

int main() {
    printf("C Firewall example program in a Claude Shannon style\n");

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