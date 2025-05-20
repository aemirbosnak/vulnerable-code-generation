//Falcon-180B DATASET v1.0 Category: Firewall ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char action[20];
    char source_ip[MAX_IP_LENGTH];
    char dest_ip[MAX_IP_LENGTH];
    char source_port[MAX_PORT_LENGTH];
    char dest_port[MAX_PORT_LENGTH];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    printf("Enter action (allow/deny): ");
    scanf("%s", rules[num_rules].action);

    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dest_port);

    num_rules++;
}

void print_rules() {
    for (int i = 0; i < num_rules; i++) {
        printf("%d: %s %s %s:%s -> %s:%s\n", i+1, rules[i].action, rules[i].source_ip, rules[i].source_port, rules[i].dest_ip, rules[i].dest_port);
    }
}

int main() {
    printf("Firewall Configuration\n");
    printf("=====================\n");

    while (num_rules < MAX_RULES) {
        printf("\nEnter 'a' to add a rule or 'p' to print the rules:\n");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_rule();
                break;
            case 'p':
                print_rules();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}