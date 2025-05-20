//Falcon-180B DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

// Struct to hold firewall rules
typedef struct {
    char ip[16];
    char allowed;
} rule_t;

// Function to add a rule
void add_rule(rule_t* rules, int num_rules, char* ip, char allowed) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules.\n");
        exit(1);
    }

    strcpy(rules[num_rules].ip, ip);
    rules[num_rules].allowed = allowed;
    num_rules++;
}

// Function to check if an IP is allowed
char is_allowed(rule_t* rules, int num_rules, char* ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].allowed;
        }
    }

    return 'N';
}

int main() {
    // Initialize rules
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    // Add some rules
    add_rule(rules, num_rules, "192.168.0.1", 'Y');
    add_rule(rules, num_rules, "192.168.0.2", 'N');

    // Test the rules
    char ip[16];
    while (1) {
        printf("Enter an IP address: ");
        scanf("%s", ip);

        char allowed = is_allowed(rules, num_rules, ip);
        if (allowed == 'Y') {
            printf("Allowed\n");
        } else {
            printf("Denied\n");
        }
    }

    return 0;
}