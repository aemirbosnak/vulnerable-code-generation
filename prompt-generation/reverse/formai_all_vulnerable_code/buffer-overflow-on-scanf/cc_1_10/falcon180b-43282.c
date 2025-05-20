//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

typedef struct {
    char action;
    char source_ip[16];
    char destination_ip[16];
    char port[6];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule(char action, char* source_ip, char* destination_ip, char* port) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strncpy(rules[num_rules].source_ip, source_ip, 16);
    strncpy(rules[num_rules].destination_ip, destination_ip, 16);
    strncpy(rules[num_rules].port, port, 6);

    rules[num_rules].action = action;
    num_rules++;
}

bool check_rule(char* source_ip, char* destination_ip, char* port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 &&
            strcmp(rules[i].destination_ip, destination_ip) == 0 &&
            strcmp(rules[i].port, port) == 0) {
            return rules[i].action == 'A';
        }
    }

    return false;
}

int main() {
    add_rule('A', "192.168.1.1", "192.168.1.2", "80");
    add_rule('D', "192.168.1.3", "192.168.1.4", "443");

    char source_ip[16];
    char destination_ip[16];
    char port[6];

    printf("Enter source IP: ");
    scanf("%s", source_ip);

    printf("Enter destination IP: ");
    scanf("%s", destination_ip);

    printf("Enter port: ");
    scanf("%s", port);

    if (check_rule(source_ip, destination_ip, port)) {
        printf("Connection allowed.\n");
    } else {
        printf("Connection denied.\n");
    }

    return 0;
}