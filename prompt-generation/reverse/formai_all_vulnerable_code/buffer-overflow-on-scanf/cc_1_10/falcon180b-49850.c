//Falcon-180B DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 80

struct rule {
    char action;
    char ip[16];
    char port[6];
};

void add_rule(struct rule *rules, int num_rules, char action, char *ip, char *port) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);
    rules[num_rules].action = action;

    num_rules++;
}

void print_rules(struct rule *rules, int num_rules) {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %c %s:%s\n", i+1, rules[i].action, rules[i].ip, rules[i].port);
    }
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    printf("Welcome to the Firewall!\n");

    while (1) {
        printf("\nEnter a command (add/print/exit): ");
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            char ip[16];
            char port[6];
            printf("Enter IP address: ");
            scanf("%s", ip);
            printf("Enter port number: ");
            scanf("%s", port);

            printf("Enter action (A/D): ");
            char action;
            scanf(" %c", &action);

            add_rule(rules, num_rules, action, ip, port);
        } else if (strcmp(cmd, "print") == 0) {
            print_rules(rules, num_rules);
        } else if (strcmp(cmd, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}