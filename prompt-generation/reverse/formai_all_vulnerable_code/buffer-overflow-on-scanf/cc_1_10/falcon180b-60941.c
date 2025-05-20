//Falcon-180B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char protocol;
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
    scanf(" %c", &rules[num_rules].protocol);

    printf("Enter the source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter the destination port: ");
    scanf("%d", &rules[num_rules].dest_port);

    printf("Enter the action (allow or deny): ");
    scanf(" %c", &rules[num_rules].action);

    num_rules++;
}

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d: %s -> %s:%d (%c:%d) -> %c\n", i+1, rules[i].source_ip, rules[i].dest_ip, rules[i].dest_port, rules[i].protocol, rules[i].source_port, rules[i].action);
    }
}

int main() {
    printf("Welcome to the Firewall Configuration Tool!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a rule\n");
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