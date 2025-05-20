//Falcon-180B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char action;
} firewall_rule;

void add_rule(firewall_rule *rules, int num_rules) {
    char source_ip[16];
    char dest_ip[16];
    char action;

    printf("Enter the source IP address: ");
    scanf("%s", source_ip);

    printf("Enter the destination IP address: ");
    scanf("%s", dest_ip);

    printf("Enter the action (allow/deny): ");
    scanf(" %c", &action);

    strcpy(rules[num_rules].source_ip, source_ip);
    strcpy(rules[num_rules].dest_ip, dest_ip);
    rules[num_rules].action = action;

    printf("Rule added.\n");
}

void display_rules(firewall_rule *rules, int num_rules) {
    int i;

    for (i = 0; i < num_rules; i++) {
        printf("Rule %d: ", i + 1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].dest_ip);
        printf("Action: %c\n", rules[i].action);
        printf("\n");
    }
}

int main() {
    firewall_rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("Enter 1 to add a rule, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_rule(rules, num_rules);
        } else if (choice!= 0) {
            printf("Invalid input.\n");
        } else {
            break;
        }
    }

    printf("Firewall rules:\n");
    display_rules(rules, num_rules);

    return 0;
}