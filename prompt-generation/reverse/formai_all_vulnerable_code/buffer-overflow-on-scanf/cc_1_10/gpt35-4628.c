//FormAI DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold firewall rules
typedef struct rule {
    int port;
    char action[10];
} Rule;

int main() {
    int num_rules;
    
    // Get number of rules from user
    printf("How many firewall rules do you want to create?\n");
    scanf("%d", &num_rules);
    
    Rule rules[num_rules];
    
    // Get rules from user
    for (int i = 0; i < num_rules; i++) {
        printf("Enter port number for rule %d: ", i+1);
        scanf("%d", &rules[i].port);
        printf("Allow or Deny? ");
        scanf("%s", rules[i].action);
    }
    
    // Set up firewall
    printf("\nSetting up firewall...\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Creating rule for port %d: %s...\n", rules[i].port, rules[i].action);
    }
    printf("Firewall is now active.\n\n");
    
    // Loop until user exits
    int port;
    char input[10];
    while (1) {
        printf("Enter a port number to check (or 'exit' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        }
        port = atoi(input);
        int allowed = 0;
        for (int i = 0; i < num_rules; i++) {
            if (rules[i].port == port) {
                if (strcmp(rules[i].action, "Allow") == 0) {
                    printf("Port %d is ALLOWED.\n", port);
                } else {
                    printf("Port %d is DENIED.\n", port);
                }
                allowed = 1;
                break;
            }
        }
        if (!allowed) {
            printf("Port %d is NOT COVERED by any rule.\n", port);
        }
    }
    
    return 0;
}