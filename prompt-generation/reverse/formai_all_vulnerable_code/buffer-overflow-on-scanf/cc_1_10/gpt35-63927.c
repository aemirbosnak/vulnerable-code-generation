//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50 // Maximum number of rules allowed
#define MAX_IP_LEN 16 // Maximum length of IP address string
#define MAX_PORTS_LEN 16 // Maximum length of port number string
#define MAX_ACTION_LEN 10 // Maximum length of rule action string

typedef struct {
    char ip[MAX_IP_LEN];
    char ports[MAX_PORTS_LEN];
    char action[MAX_ACTION_LEN];
} Rule; // Structure for each firewall rule

int main() {
    Rule rules[MAX_RULES]; // Array of firewall rules
    int num_rules = 0; // Number of current rules
    char input[MAX_PORTS_LEN + MAX_IP_LEN + MAX_ACTION_LEN + 3]; // Input buffer for adding rules

    printf("Welcome to the ephemeral firewall!\n");

    while (1) {
        printf("\nCurrent rules:\n");

        for (int i = 0; i < num_rules; i++) {
            printf("%d. IP: %s, Ports: %s, Action: %s\n", i + 1, rules[i].ip, rules[i].ports, rules[i].action);
        }

        printf("\nOptions:\n");
        printf("1. Add rule\n");
        printf("2. Remove rule\n");
        printf("3. Exit\n");

        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nEnter IP address, ports, and action (allow/deny), separated by spaces: ");
            scanf("%s", input);

            // Parse input into IP address, ports, and action
            char *token = strtok(input, " ");
            strcpy(rules[num_rules].ip, token);

            token = strtok(NULL, " ");
            strcpy(rules[num_rules].ports, token);

            token = strtok(NULL, " ");
            strcpy(rules[num_rules].action, token);

            printf("Rule added successfully.\n");
            num_rules++;
        } else if (option == 2) {
            printf("\nEnter the number of the rule to remove: ");
            int rule_num;
            scanf("%d", &rule_num);

            if (rule_num < 1 || rule_num > num_rules) {
                printf("Invalid rule number.\n");
            } else {
                for (int i = rule_num - 1; i < num_rules - 1; i++) {
                    rules[i] = rules[i + 1];
                }

                num_rules--;
                printf("Rule removed successfully.\n");
            }
        } else if (option == 3) {
            printf("Exiting ephemeral firewall.");
            return 0;
        } else {
            printf("Invalid option.\n");
        }
    }
}