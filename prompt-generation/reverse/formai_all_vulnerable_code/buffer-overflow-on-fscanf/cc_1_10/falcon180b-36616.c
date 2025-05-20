//Falcon-180B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

// Struct to hold a firewall rule
typedef struct {
    char rule[MAX_RULE_LENGTH];
    int allowed;
} rule_t;

// Function to read rules from a file
void read_rules(rule_t rules[], FILE *file) {
    int num_rules = 0;
    rule_t rule;

    // Read each line from the file
    while (fscanf(file, "%s %d", rule.rule, &rule.allowed) == 2) {
        // Check if we've reached the maximum number of rules
        if (num_rules == MAX_RULES) {
            printf("Error: Maximum number of rules reached.\n");
            exit(1);
        }

        // Copy the rule to the rules array
        strcpy(rules[num_rules].rule, rule.rule);
        num_rules++;
    }

    // Check if we read any rules
    if (num_rules == 0) {
        printf("Error: No rules found in file.\n");
        exit(1);
    }
}

// Function to check if a packet is allowed
int check_packet(char *packet, rule_t rules[], int num_rules) {
    int i;

    // Loop through each rule
    for (i = 0; i < num_rules; i++) {
        // Check if the packet matches the rule
        if (strcmp(packet, rules[i].rule) == 0) {
            // If the rule is allowed, return true
            if (rules[i].allowed) {
                return 1;
            } else {
                // Otherwise, return false
                return 0;
            }
        }
    }

    // If we reach this point, the packet is not allowed
    return 0;
}

// Main function
int main() {
    // Initialize the rules array
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    // Read the rules from a file
    FILE *file = fopen("rules.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open rules file.\n");
        exit(1);
    }
    read_rules(rules, file);
    fclose(file);

    // Loop through each packet
    char packet[MAX_RULE_LENGTH];
    while (fgets(packet, MAX_RULE_LENGTH, stdin)!= NULL) {
        // Check if the packet is allowed
        if (check_packet(packet, rules, num_rules)) {
            printf("Packet allowed.\n");
        } else {
            printf("Packet denied.\n");
        }
    }

    return 0;
}