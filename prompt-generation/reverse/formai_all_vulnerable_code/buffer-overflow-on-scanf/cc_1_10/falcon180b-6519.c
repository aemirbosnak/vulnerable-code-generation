//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define MAX_ACTION_LENGTH 10

typedef struct {
    char src_ip[MAX_IP_LENGTH];
    char dst_ip[MAX_IP_LENGTH];
    char src_port[MAX_PORT_LENGTH];
    char dst_port[MAX_PORT_LENGTH];
    char action[MAX_ACTION_LENGTH];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].src_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dst_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].src_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dst_port);

    printf("Enter action (allow/deny): ");
    scanf("%s", rules[num_rules].action);

    num_rules++;
}

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s -> %s :%s -> %s :%s -> %s\n", i+1, rules[i].src_ip, rules[i].dst_ip, rules[i].src_port, rules[i].dst_port, rules[i].action);
    }
}

int main() {
    printf("Welcome to the Romeo and Juliet Firewall!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add rule\n");
        printf("2. Print rules\n");
        printf("3. Exit\n");

        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_rule();
                break;
            case '2':
                print_rules();
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}