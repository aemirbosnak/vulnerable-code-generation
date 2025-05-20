//Falcon-180B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define MAX_PROTOCOL_LENGTH 10

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    char protocol[MAX_PROTOCOL_LENGTH];
    bool allow;
} Rule;

int numRules = 0;
Rule rules[MAX_RULES];

void addRule() {
    if (numRules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter IP address: ");
    scanf("%s", rules[numRules].ip);

    printf("Enter port number: ");
    scanf("%s", rules[numRules].port);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", rules[numRules].protocol);

    printf("Allow? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    rules[numRules].allow = (choice == 'y' || choice == 'Y');

    numRules++;
}

void displayRules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < numRules; i++) {
        printf("Rule %d: %s %s/%s %s %s\n", i+1, rules[i].allow? "Allow" : "Deny", rules[i].ip, rules[i].port, rules[i].protocol, rules[i].allow? "" : " (Default)");
    }
}

int main() {
    printf("Welcome to the Romantic Firewall!\n");

    while (true) {
        displayRules();

        printf("\nEnter option:\n");
        printf("1. Add rule\n");
        printf("2. Exit\n");

        char option;
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addRule();
                break;
            case '2':
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}