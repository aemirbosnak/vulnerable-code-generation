//Falcon-180B DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char action;
    char protocol;
    char ip[MAX_IP_LENGTH];
    char port[6];
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

void add_rule() {
    char action;
    char protocol[6];
    char ip[MAX_IP_LENGTH];
    char port[6];

    printf("Enter the action (allow/deny): ");
    scanf("%c", &action);

    printf("Enter the protocol (tcp/udp): ");
    scanf("%s", protocol);

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the port number: ");
    scanf("%s", port);

    rules[num_rules].action = action;
    strcpy(rules[num_rules].protocol, protocol);
    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);

    num_rules++;
}

void print_rules() {
    int i;

    for(i=0; i<num_rules; i++) {
        printf("Rule %d:\n");
        printf("Action: %c\n", rules[i].action);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("IP Address: %s\n", rules[i].ip);
        printf("Port Number: %s\n\n", rules[i].port);
    }
}

int main() {
    int choice, i;

    printf("Welcome to the Firewall Rule Editor!\n");
    printf("Please choose an option:\n");
    printf("1. Add a rule\n");
    printf("2. Print rules\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_rule();
            break;
        case 2:
            print_rules();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}