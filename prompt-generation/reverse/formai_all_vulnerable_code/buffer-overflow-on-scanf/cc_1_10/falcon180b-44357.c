//Falcon-180B DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char action;
};

int num_rules = 0;
struct rule rules[MAX_RULES];

void add_rule() {
    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter action (allow/deny): ");
    scanf(" %c", &rules[num_rules].action);

    num_rules++;
}

int match_rule(char *source_ip, char *dest_ip) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].dest_ip, dest_ip) == 0) {
            return rules[i].action;
        }
    }
    return -1;
}

int main() {
    int choice, i;

    printf("Welcome to the happy firewall!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add rule\n");
        printf("2. Display rules\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_rule();
            break;

        case 2:
            printf("\nFirewall rules:\n");
            for (i = 0; i < num_rules; i++) {
                printf("Rule %d: %s -> %s -> %c\n", i, rules[i].source_ip, rules[i].dest_ip, rules[i].action);
            }
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}