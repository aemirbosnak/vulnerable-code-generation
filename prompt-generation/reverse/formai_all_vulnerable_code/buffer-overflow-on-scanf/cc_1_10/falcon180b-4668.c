//Falcon-180B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define MAX_ACTION_LENGTH 10

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    char action[MAX_ACTION_LENGTH];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter IP address: ");
    scanf("%s", rules[num_rules].ip);

    printf("Enter port number: ");
    scanf("%s", rules[num_rules].port);

    printf("Enter action (allow/deny): ");
    scanf("%s", rules[num_rules].action);

    num_rules++;
}

void print_rules() {
    printf("Number of rules: %d\n", num_rules);
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("IP address: %s\n", rules[i].ip);
        printf("Port number: %s\n", rules[i].port);
        printf("Action: %s\n\n", rules[i].action);
    }
}

int main() {
    printf("Welcome to the Funky Firewall!\n");

    while (1) {
        printf("\nChoose an option:\n");
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
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}