//Falcon-180B DATASET v1.0 Category: Firewall ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
} Rule;

void addRule(Rule *rules, int numRules, char *ip, char *port, int action) {
    strcpy(rules[numRules].ip, ip);
    strcpy(rules[numRules].port, port);
    rules[numRules].action = action;
    numRules++;
}

void printRules(Rule *rules, int numRules) {
    for (int i = 0; i < numRules; i++) {
        printf("Rule %d: %s:%s -> %s\n", i+1, rules[i].ip, rules[i].port, (rules[i].action == 1? "Allow" : "Deny"));
    }
}

void processPacket(Rule *rules, int numRules, char *ip, char *port) {
    for (int i = 0; i < numRules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            if (rules[i].action == 1) {
                printf("Packet allowed: %s:%s\n", ip, port);
                return;
            } else {
                printf("Packet denied: %s:%s\n", ip, port);
                return;
            }
        }
    }
    printf("Packet dropped: %s:%s\n", ip, port);
}

int main() {
    Rule rules[MAX_RULES];
    int numRules = 0;

    addRule(rules, numRules, "192.168.1.0", "80", 1);
    addRule(rules, numRules, "10.0.0.0", "443", 1);
    addRule(rules, numRules, "172.16.0.0", "22", 0);

    printRules(rules, numRules);

    while (1) {
        char ip[MAX_IP_LENGTH];
        char port[MAX_PORT_LENGTH];
        printf("Enter packet details (IP:Port): ");
        scanf("%s:%s", ip, port);
        processPacket(rules, numRules, ip, port);
    }

    return 0;
}