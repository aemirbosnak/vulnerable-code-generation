//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

typedef struct {
    char action;
    char protocol;
    char source_ip[16];
    char dest_ip[16];
    char source_port[6];
    char dest_port[6];
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter action (A/D/R): ");
    char action;
    scanf("%c", &action);

    printf("Enter protocol (TCP/UDP): ");
    char protocol;
    scanf("%c", &protocol);

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

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d. %c %c %s -> %s:%s\n", i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].dest_ip, rules[i].dest_port);
    }
}

int main() {
    printf("Welcome to the Firewall Configuration System\n");

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