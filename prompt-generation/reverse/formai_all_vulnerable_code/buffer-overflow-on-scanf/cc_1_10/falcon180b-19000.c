//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    int port;
    bool allow;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

void add_rule(const char* ip, int port, bool allow) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached\n");
        return;
    }

    strncpy(rules[num_rules].ip, ip, MAX_IP_LENGTH);
    rules[num_rules].port = port;
    rules[num_rules].allow = allow;

    num_rules++;
}

bool check_rule(const char* ip, int port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && rules[i].port == port) {
            return rules[i].allow;
        }
    }

    return false;
}

int main() {
    add_rule("192.168.1.2", 80, true);
    add_rule("192.168.1.3", 443, false);

    char ip[MAX_IP_LENGTH];
    int port;

    while (true) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        printf("Enter port number: ");
        scanf("%d", &port);

        bool allowed = check_rule(ip, port);

        if (allowed) {
            printf("Access granted\n");
        } else {
            printf("Access denied\n");
        }
    }

    return 0;
}