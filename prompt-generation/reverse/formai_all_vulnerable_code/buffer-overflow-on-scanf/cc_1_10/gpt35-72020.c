//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <stdio.h>

// Define maximum size of the firewall
#define MAX_SIZE 100

// Declare the firewall variables
char firewall[MAX_SIZE][15];
int num_rules = 0;

// Function to add a rule to the firewall
void add_rule(char *rule) {
    if (num_rules < MAX_SIZE) {
        // Copy the rule to the firewall
        sprintf(firewall[num_rules], "%s", rule);
        num_rules++;
        printf("Rule added to the firewall.\n");
    } else {
        printf("Firewall is full. Cannot add more rules.\n");
    }
}

// Function to remove a rule from the firewall
void remove_rule(int rule_num) {
    if (rule_num >= 1 && rule_num <= num_rules) {
        // Remove the rule from the firewall
        for (int i = rule_num - 1; i < num_rules - 1; i++) {
            sprintf(firewall[i], "%s", firewall[i + 1]);
        }
        num_rules--;
        printf("Rule removed from the firewall.\n");
    } else {
        printf("Invalid rule number.\n");
    }
}

// Function to print the firewall rules
void print_firewall() {
    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d. %s\n", i + 1, firewall[i]);
    }
}

int main() {
    char input[15];
    int rule_num;
    
    // Add some initial rules to the firewall
    add_rule("allow port 80");
    add_rule("deny port 21");
    
    // Loop to accept user input
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            printf("Enter rule to add: ");
            scanf("%s", input);
            add_rule(input);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter rule number to remove: ");
            scanf("%d", &rule_num);
            remove_rule(rule_num);
        } else if (strcmp(input, "print") == 0) {
            print_firewall();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}