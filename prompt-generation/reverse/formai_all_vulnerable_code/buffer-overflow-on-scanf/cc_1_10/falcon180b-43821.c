//Falcon-180B DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

// Struct to store firewall rules
typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    char action[10];
} FirewallRule;

// Function to add a new rule to the firewall
void add_rule(FirewallRule *rules, int num_rules) {
    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter action (allow/deny): ");
    scanf("%s", rules[num_rules].action);

    num_rules++;
}

// Function to print all firewall rules
void print_rules(FirewallRule *rules, int num_rules) {
    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s -> %s (%s) %s\n", i+1, rules[i].source_ip, rules[i].dest_ip, rules[i].protocol, rules[i].action);
    }
}

// Function to check if a packet matches a firewall rule
int check_rule(FirewallRule *rules, int num_rules, char *source_ip, char *dest_ip, char *protocol) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].dest_ip, dest_ip) == 0 && strcmp(rules[i].protocol, protocol) == 0) {
            if (strcmp(rules[i].action, "allow") == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    FirewallRule rules[MAX_RULES];
    int num_rules = 0;

    // Initialize firewall with default deny all rule
    rules[num_rules].source_ip[0] = '\0';
    rules[num_rules].dest_ip[0] = '\0';
    rules[num_rules].protocol[0] = '\0';
    strcpy(rules[num_rules].action, "deny");
    num_rules++;

    // Add new rules
    int choice;
    do {
        printf("\nFirewall options:\n1. Add rule\n2. Print rules\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_rule(rules, num_rules);
                break;
            case 2:
                print_rules(rules, num_rules);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}