//Falcon-180B DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100

struct rule {
    char *protocol;
    char *src_ip;
    char *dest_ip;
    char *src_port;
    char *dest_port;
    int action;
};

void add_rule(struct rule *rules, int num_rules, char *protocol, char *src_ip, char *dest_ip, char *src_port, char *dest_port, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    rules[num_rules].protocol = strdup(protocol);
    rules[num_rules].src_ip = strdup(src_ip);
    rules[num_rules].dest_ip = strdup(dest_ip);
    rules[num_rules].src_port = strdup(src_port);
    rules[num_rules].dest_port = strdup(dest_port);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(struct rule *rules, int num_rules, char *protocol, char *src_ip, char *dest_ip, char *src_port, char *dest_port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].protocol, protocol) == 0 &&
            strcmp(rules[i].src_ip, src_ip) == 0 &&
            strcmp(rules[i].dest_ip, dest_ip) == 0 &&
            strcmp(rules[i].src_port, src_port) == 0 &&
            strcmp(rules[i].dest_port, dest_port) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

void print_rules(struct rule *rules, int num_rules) {
    printf("Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d: %s %s:%s -> %s:%s %s\n", i, rules[i].protocol, rules[i].src_ip, rules[i].src_port, rules[i].dest_ip, rules[i].dest_port, (rules[i].action == 1? "allow" : "deny"));
    }
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "tcp", "192.168.1.100", "192.168.1.200", "80", "80", 1);
    add_rule(rules, num_rules, "tcp", "192.168.1.200", "192.168.1.100", "80", "80", 1);
    add_rule(rules, num_rules, "tcp", "192.168.1.100", "192.168.1.200", "22", "22", 0);

    char *packet = "tcp 192.168.1.100:80 -> 192.168.1.200:80";

    int action = match_rule(rules, num_rules, "tcp", "192.168.1.100", "192.168.1.200", "80", "80");

    if (action == 1) {
        printf("Packet allowed.\n");
    } else {
        printf("Packet denied.\n");
    }

    return 0;
}