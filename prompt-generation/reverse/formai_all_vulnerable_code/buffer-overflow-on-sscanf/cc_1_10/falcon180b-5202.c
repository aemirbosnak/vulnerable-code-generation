//Falcon-180B DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

typedef struct rule {
    char source_ip[16];
    char dest_ip[16];
    char protocol[8];
    char action[8];
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(char* source_ip, char* dest_ip, char* protocol, char* action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strncpy(rules[num_rules].source_ip, source_ip, 16);
    strncpy(rules[num_rules].dest_ip, dest_ip, 16);
    strncpy(rules[num_rules].protocol, protocol, 8);
    strncpy(rules[num_rules].action, action, 8);

    num_rules++;
}

bool check_rule(char* source_ip, char* dest_ip, char* protocol) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 &&
            strcmp(rules[i].dest_ip, dest_ip) == 0 &&
            strcmp(rules[i].protocol, protocol) == 0) {
            return rules[i].action[0] == 'a';
        }
    }

    return false;
}

int main() {
    char input[MAX_RULE_LENGTH];
    char source_ip[16];
    char dest_ip[16];
    char protocol[8];
    char action[8];

    printf("Enter firewall rules (format: source_ip dest_ip protocol action):\n");

    while (fgets(input, MAX_RULE_LENGTH, stdin)!= NULL) {
        sscanf(input, "%s %s %s %s", source_ip, dest_ip, protocol, action);
        add_rule(source_ip, dest_ip, protocol, action);
    }

    while (true) {
        printf("Enter packet details (source_ip dest_ip protocol):\n");
        fgets(input, MAX_RULE_LENGTH, stdin);
        sscanf(input, "%s %s %s", source_ip, dest_ip, protocol);

        if (check_rule(source_ip, dest_ip, protocol)) {
            printf("Packet allowed.\n");
        } else {
            printf("Packet dropped.\n");
        }
    }

    return 0;
}