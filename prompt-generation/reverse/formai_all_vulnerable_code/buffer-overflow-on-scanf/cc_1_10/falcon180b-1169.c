//Falcon-180B DATASET v1.0 Category: Firewall ; Style: beginner-friendly
/* C Firewall Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 20

typedef struct {
    char ip[MAX_IP_LENGTH];
    int port;
    int action;
} rule_t;

void add_rule(rule_t rules[], int num_rules) {
    printf("Enter IP address: ");
    scanf("%s", rules[num_rules].ip);
    printf("Enter port number: ");
    scanf("%d", &rules[num_rules].port);
    printf("Enter action (0 for allow, 1 for deny): ");
    scanf("%d", &rules[num_rules].action);
    num_rules++;
}

int check_rule(rule_t rules[], int num_rules, char* ip, int port) {
    int i;
    for(i=0; i<num_rules; i++) {
        if(strcmp(rules[i].ip, ip) == 0 && rules[i].port == port) {
            if(rules[i].action == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;
    char input[MAX_RULE_LENGTH];

    printf("Welcome to the C Firewall!\n");
    printf("Enter rules in the format: IP_address port_number action (0 for allow, 1 for deny)\n");

    while(num_rules < MAX_RULES) {
        printf("Enter a rule: ");
        scanf("%s", input);
        if(strlen(input) == 0) {
            continue;
        }
        add_rule(rules, num_rules);
    }

    while(1) {
        printf("Enter an IP address and port number to check: ");
        scanf("%s %d", rules[num_rules-1].ip, &rules[num_rules-1].port);
        if(check_rule(rules, num_rules, rules[num_rules-1].ip, rules[num_rules-1].port) == 1) {
            printf("Connection allowed.\n");
        } else {
            printf("Connection denied.\n");
        }
    }

    return 0;
}