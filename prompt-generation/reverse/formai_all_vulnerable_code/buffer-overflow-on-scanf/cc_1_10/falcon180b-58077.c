//Falcon-180B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char action[10];
    char protocol[10];
    char source_ip[20];
    char dest_ip[20];
    char source_port[10];
    char dest_port[10];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    printf("Enter action (allow/deny): ");
    scanf("%s", rules[num_rules].action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dest_port);

    num_rules++;
}

void print_rules() {
    printf("Number of rules: %d\n", num_rules);
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Action: %s\n", rules[i].action);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].dest_ip);
        printf("Source Port: %s\n", rules[i].source_port);
        printf("Destination Port: %s\n", rules[i].dest_port);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("Firewall Configuration Menu:\n");
        printf("1. Add rule\n");
        printf("2. Print rules\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}