//Falcon-180B DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(char *ip, char action) {
    rules[num_rules].ip[0] = '\0';
    strncat(rules[num_rules].ip, ip, MAX_IP_LENGTH);
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(char *ip) {
    int i;
    for(i = 0; i < num_rules; i++) {
        if(strcmp(ip, rules[i].ip) == 0) {
            return rules[i].action;
        }
    }
    return 0;
}

int main() {
    // Example rules
    add_rule("192.168.0.1", 'A');
    add_rule("192.168.0.2", 'D');
    add_rule("10.0.0.0/8", 'A');

    // Test matches
    char ip[MAX_IP_LENGTH];
    printf("Enter IP address: ");
    scanf("%s", ip);
    int action = match_rule(ip);

    if(action == 'A') {
        printf("Access granted.\n");
    } else if(action == 'D') {
        printf("Access denied.\n");
    } else {
        printf("No rule found.\n");
    }

    return 0;
}