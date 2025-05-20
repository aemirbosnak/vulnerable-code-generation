//Falcon-180B DATASET v1.0 Category: Firewall ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

typedef struct {
    char protocol[10];
    char src_ip[20];
    char dst_ip[20];
    char src_port[10];
    char dst_port[10];
    char action[10];
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter rule details:\n");
    printf("Protocol: ");
    scanf("%s", rules[num_rules].protocol);

    printf("Source IP: ");
    scanf("%s", rules[num_rules].src_ip);

    printf("Destination IP: ");
    scanf("%s", rules[num_rules].dst_ip);

    printf("Source Port: ");
    scanf("%s", rules[num_rules].src_port);

    printf("Destination Port: ");
    scanf("%s", rules[num_rules].dst_port);

    printf("Action: ");
    scanf("%s", rules[num_rules].action);

    num_rules++;
}

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source IP: %s\n", rules[i].src_ip);
        printf("Destination IP: %s\n", rules[i].dst_ip);
        printf("Source Port: %s\n", rules[i].src_port);
        printf("Destination Port: %s\n", rules[i].dst_port);
        printf("Action: %s\n\n", rules[i].action);
    }
}

int main() {
    printf("Welcome to the Firewall Configuration Tool!\n");

    while (true) {
        printf("\nOptions:\n");
        printf("1. Add Rule\n");
        printf("2. Print Rules\n");
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
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}