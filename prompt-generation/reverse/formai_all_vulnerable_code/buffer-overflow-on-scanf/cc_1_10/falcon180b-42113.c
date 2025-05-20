//Falcon-180B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULE_LENGTH 100
#define MAX_RULES 50

typedef struct {
    char source_ip[16];
    char destination_ip[16];
    char source_port[6];
    char destination_port[6];
    int protocol;
    int action;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].destination_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].destination_port);

    printf("Enter protocol (TCP or UDP): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter action (allow or deny): ");
    scanf("%s", rules[num_rules].action);

    num_rules++;
}

void print_rules() {
    printf("Number of rules: %d\n", num_rules);
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].destination_ip);
        printf("Source Port: %s\n", rules[i].source_port);
        printf("Destination Port: %s\n", rules[i].destination_port);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Action: %s\n\n", rules[i].action);
    }
}

int main() {
    printf("Welcome to the C Firewall!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a rule\n");
        printf("2. Print rules\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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