//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char action; // A for allow, D for deny
    char protocol[10];
    char source_ip[MAX_IP_LENGTH];
    char dest_ip[MAX_IP_LENGTH];
    int source_port;
    int dest_port;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    printf("Enter action (A for allow, D for deny): ");
    char action;
    scanf("%c", &action);

    printf("Enter protocol (e.g. TCP, UDP): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%d", &rules[num_rules].dest_port);

    num_rules++;
}

void print_rules() {
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Action: %c\n", rules[i].action);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].dest_ip);
        printf("Source Port: %d\n", rules[i].source_port);
        printf("Destination Port: %d\n", rules[i].dest_port);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nFirewall Configuration\n");
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}