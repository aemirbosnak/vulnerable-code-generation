//Falcon-180B DATASET v1.0 Category: Firewall ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define ALLOW 1
#define DENY 0
#define INVALID_RULE -1
#define PACKET_ALLOWED 1
#define PACKET_DENIED 0

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
} Rule;

void add_rule(Rule* rules, int num_rules) {
    printf("Enter IP address: ");
    scanf("%s", rules[num_rules].ip);
    printf("Enter port number: ");
    scanf("%s", rules[num_rules].port);
    printf("Enter action (allow/deny): ");
    char action[MAX_RULE_LENGTH];
    scanf("%s", action);
    if (strcmp(action, "allow") == 0) {
        rules[num_rules].action = ALLOW;
    } else if (strcmp(action, "deny") == 0) {
        rules[num_rules].action = DENY;
    } else {
        printf("Invalid action\n");
        return;
    }
    num_rules++;
}

int match_rule(Rule* rules, int num_rules, char* ip, char* port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].action;
        }
    }
    return DENY;
}

int main() {
    Rule rules[MAX_RULES];
    int num_rules = 0;
    while (num_rules < MAX_RULES) {
        add_rule(rules, num_rules);
    }

    char* ip;
    char* port;
    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);
        printf("Enter port number: ");
        scanf("%s", port);
        int action = match_rule(rules, num_rules, ip, port);
        if (action == ALLOW) {
            printf("Packet allowed\n");
        } else {
            printf("Packet denied\n");
        }
    }

    return 0;
}