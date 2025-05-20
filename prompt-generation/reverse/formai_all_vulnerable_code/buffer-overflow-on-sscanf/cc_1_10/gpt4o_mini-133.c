//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Maximum number of rules that can be held in the firewall
#define MAX_RULES 10

// Structure to hold firewall rules
typedef struct {
    char action[6]; // "ALLOW" or "DENY"
    char ip[16];    // IP address in string format
} FirewallRule;

// Global variable to hold the firewall rules
FirewallRule rules[MAX_RULES];
int rule_count = 0;

// Function to add a rule to the firewall
void add_rule(char *action, char *ip) {
    if (rule_count < MAX_RULES) {
        strcpy(rules[rule_count].action, action);
        strcpy(rules[rule_count].ip, ip);
        rule_count++;
        printf("Rule added: %s %s\n", action, ip);
    } else {
        printf("Maximum rules reached! Cannot add more.\n");
    }
}

// Function to check if an IP is allowed or denied
const char* check_ip(char *ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].action; // Return the action of matched rule
        }
    }
    return "ALLOW"; // Default action if no rules match
}

// Function to display all current rules
void display_rules() {
    printf("--- Current Firewall Rules ---\n");
    for (int i = 0; i < rule_count; i++) {
        printf("Rule %d: %s %s\n", i + 1, rules[i].action, rules[i].ip);
    }
}

// Simple command interface to manage firewall
void command_interface() {
    char command[50];
    char action[6], ip[16];

    printf("Welcome to the Firewall Management System!\n");
    printf("Commands: ADD [ALLOW|DENY] [IP] or SHOW to view rules or EXIT to quit.\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        if (sscanf(command, "ADD %s %s", action, ip) == 2) {
            add_rule(action, ip);
        } else if (strcmp(command, "SHOW") == 0) {
            display_rules();
        } else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting the Firewall Management System.\n");
            break;
        } else {
            printf("Invalid command or format.\n");
        }
    }
}

int main() {
    // Start the command interface to manage the firewall
    command_interface();
    return 0;
}