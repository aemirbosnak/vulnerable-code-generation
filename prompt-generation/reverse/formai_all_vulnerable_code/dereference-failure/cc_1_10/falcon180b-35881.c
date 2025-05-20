//Falcon-180B DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 512
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    bool allow;
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(const char* ip, const char* port, bool allow) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }
    strncpy(rules[num_rules].ip, ip, MAX_IP_LENGTH);
    strncpy(rules[num_rules].port, port, MAX_PORT_LENGTH);
    rules[num_rules].allow = allow;
    num_rules++;
}

bool check_rule(const char* ip, const char* port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].allow;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }
    char ip[MAX_IP_LENGTH] = {0};
    char port[MAX_PORT_LENGTH] = {0};
    strncpy(ip, argv[1], MAX_IP_LENGTH);
    strncpy(port, argv[2], MAX_PORT_LENGTH);
    bool allow = check_rule(ip, port);
    if (allow) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
    return 0;
}