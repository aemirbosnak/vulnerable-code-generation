//Falcon-180B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(char *ip, char action) {
    strcpy(rules[num_rules].ip, ip);
    rules[num_rules].action = action;
    num_rules++;
}

bool match_rule(char *ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(ip, rules[i].ip) == 0) {
            return rules[i].action == 'a';
        }
    }
    return false;
}

int main() {
    add_rule("192.168.1.1", 'a');
    add_rule("192.168.1.2", 'd');
    add_rule("10.0.0.1", 'a');
    add_rule("10.0.0.2", 'd');

    char ip[MAX_IP_LENGTH];
    while (true) {
        printf("Enter an IP address: ");
        scanf("%s", ip);
        if (match_rule(ip)) {
            printf("Access allowed.\n");
        } else {
            printf("Access denied.\n");
        }
    }

    return 0;
}