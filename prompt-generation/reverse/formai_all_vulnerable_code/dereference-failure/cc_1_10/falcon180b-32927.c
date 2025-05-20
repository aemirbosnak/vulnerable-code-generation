//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char action;
    char source[MAX_RULE_LENGTH];
    char destination[MAX_RULE_LENGTH];
    char protocol[MAX_RULE_LENGTH];
    char port[MAX_RULE_LENGTH];
};

void add_rule(struct rule *rules, int num_rules, char *action, char *source, char *destination, char *protocol, char *port) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        exit(1);
    }

    strcpy(rules[num_rules].action, action);
    strcpy(rules[num_rules].source, source);
    strcpy(rules[num_rules].destination, destination);
    strcpy(rules[num_rules].protocol, protocol);
    strcpy(rules[num_rules].port, port);

    num_rules++;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "allow", "192.168.0.1", "192.168.0.2", "tcp", "80");
    add_rule(rules, num_rules, "deny", "192.168.0.3", "192.168.0.4", "udp", "53");

    char *source_ip = "192.168.0.5";
    char *dest_ip = "192.168.0.6";
    char *protocol_str = "tcp";
    int dest_port = 22;

    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].action, "allow") == 0 &&
            strcmp(rules[i].source, source_ip) == 0 &&
            strcmp(rules[i].destination, dest_ip) == 0 &&
            strcmp(rules[i].protocol, protocol_str) == 0 &&
            atoi(rules[i].port) >= dest_port) {
            printf("Packet allowed.\n");
            return 0;
        } else if (strcmp(rules[i].action, "deny") == 0 &&
                   strcmp(rules[i].source, source_ip) == 0 &&
                   strcmp(rules[i].destination, dest_ip) == 0 &&
                   strcmp(rules[i].protocol, protocol_str) == 0 &&
                   atoi(rules[i].port) >= dest_port) {
            printf("Packet denied.\n");
            return 1;
        }
    }

    printf("Packet dropped.\n");
    return 2;
}