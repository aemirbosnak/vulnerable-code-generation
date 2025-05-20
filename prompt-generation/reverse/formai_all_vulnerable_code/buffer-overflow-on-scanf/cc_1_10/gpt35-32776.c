//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 50

typedef struct firewall_rule {
    char ip_address[16];
    bool allow;
} firewall_rule;

firewall_rule rules[MAX_RULES];
int num_rules = 0;

void add_rule(char* ip_address, bool allow) {
    if (num_rules >= MAX_RULES) {
        printf("Sorry, we can't add any more rules\n");
    } else {
        strcpy(rules[num_rules].ip_address, ip_address);
        rules[num_rules].allow = allow;
        num_rules++;
        printf("Rule added successfully!\n");
    }
}

bool check_rule(char* ip_address) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(ip_address, rules[i].ip_address) == 0) {
            printf("Rule found for IP address %s\n", ip_address);
            return rules[i].allow;
        }
    }
    printf("No rule found for IP address %s\n", ip_address);
    return false;
}

int main() {
    char ip_address[16];
    bool allow;
    char choice;

    while (true) {
        printf("Do you want to add a rule? (y/n) ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter the IP address: ");
            scanf("%s", ip_address);
            printf("Do you want to allow or block traffic from this IP? (a/b) ");
            scanf(" %c", &choice);
            if (choice == 'a' || choice == 'A')
                allow = true;
            else if (choice == 'b' || choice == 'B')
                allow = false;
            else {
                printf("Invalid choice!\n");
                continue;
            }
            add_rule(ip_address, allow);
        } else if (choice == 'n' || choice == 'N') {
            printf("Enter the IP address to check: ");
            scanf("%s", ip_address);
            bool allow_traffic = check_rule(ip_address);
            if (allow_traffic)
                printf("Traffic from IP address %s is allowed!\n", ip_address);
            else
                printf("Traffic from IP address %s is blocked!\n", ip_address);
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
            break;
    }

    return 0;
}