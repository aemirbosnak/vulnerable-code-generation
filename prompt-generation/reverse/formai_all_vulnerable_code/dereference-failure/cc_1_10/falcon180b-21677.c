//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char action;
    char protocol;
    char source_ip[16];
    char dest_ip[16];
    char source_port[6];
    char dest_port[6];
} FirewallRule;

void add_rule(FirewallRule *rules, int num_rules, char *rule_str) {
    char *token;
    int i = 0;
    while ((token = strtok(rule_str, " "))!= NULL) {
        if (i >= MAX_RULE_LENGTH) {
            printf("Error: Rule exceeds maximum length\n");
            exit(1);
        }
        strcpy(rules[num_rules].action, token);
        i++;
    }
    num_rules++;
    rules[num_rules-1].action = '\0';
}

void print_rules(FirewallRule *rules, int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s\n", i+1, rules[i].action);
    }
}

int main() {
    FirewallRule rules[MAX_RULES];
    int num_rules = 0;
    char input_buffer[1024];

    printf("Welcome to the Ada Lovelace Firewall!\n");

    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        char *rule_str = strtok(input_buffer, "\n");
        if (rule_str!= NULL) {
            add_rule(rules, num_rules, rule_str);
            num_rules++;
        }
    }

    print_rules(rules, num_rules);

    return 0;
}