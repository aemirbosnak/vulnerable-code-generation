//FormAI DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_IP_LEN 15
#define MAX_RULES 100

// Define struct for firewall rules
typedef struct FirewallRule {
    char ip[MAX_IP_LEN+1];
    int port;
    char protocol[4];
} FirewallRule;

// Declare function to add firewall rule to array
int addFirewallRule(FirewallRule rules[], int currentNumRules);

int main() {
    // Declare variables
    FirewallRule rules[MAX_RULES];
    int numRules = 0;
    char userInput;

    // Print welcome message and instructions
    printf("Welcome to the Firewall Configuration Program!\n");
    printf("Please choose an action:\n");
    printf("1. Add a new firewall rule.\n");
    printf("2. Print the current firewall rules.\n");
    printf("3. Exit the program.\n");

    // Loop until user chooses to exit
    while(1) {
        // Get user input
        printf("\nEnter your choice: ");
        scanf(" %c", &userInput);
        printf("\n");

        // Handle input
        switch (userInput) {
            case '1':
                numRules = addFirewallRule(rules, numRules);
                break;
            case '2':
                // Print current rules
                printf("Current Firewall Rules:\n");
                for (int i = 0; i < numRules; i++) {
                    printf("%s:%d %s\n", rules[i].ip, rules[i].port, rules[i].protocol);
                }
                break;
            case '3':
                // Exit the program
                printf("Exiting Program...");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a firewall rule
int addFirewallRule(FirewallRule rules[], int currentNumRules) {
    // Declare variables
    char ip[MAX_IP_LEN+1];
    int port;
    char protocol[4];
    char addAnother;

    // Get user input
    printf("Enter IP address (xxx.xxx.xxx.xxx format): ");
    scanf("%s", ip);
    printf("Enter port number: ");
    scanf("%d", &port);
    printf("Enter protocol (TCP or UDP): ");
    scanf("%s", protocol);
    printf("Do you want to add another rule? (y/n): ");
    scanf(" %c", &addAnother);

    // Create new rule and add to array
    FirewallRule newRule;
    strcpy(newRule.ip, ip);
    newRule.port = port;
    strcpy(newRule.protocol, protocol);
    rules[currentNumRules] = newRule;
    currentNumRules++;

    // Check if user wants to add another rule
    if (addAnother == 'y' || addAnother == 'Y') {
        // Recursively call function to add another rule
        currentNumRules = addFirewallRule(rules, currentNumRules);
    }

    return currentNumRules;
}