//Falcon-180B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define MAX_RULE_LENGTH 1024

typedef struct rule {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *ip, char *port, int action) {
    if (num_rules >= MAX_RULE_LENGTH) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }

    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);
    rules[num_rules].action = action;

    num_rules++;
}

int main() {
    rule_t rules[MAX_RULE_LENGTH];
    int num_rules = 0;

    add_rule(rules, num_rules, "192.168.0.1", "80", 1);
    add_rule(rules, num_rules, "10.0.0.2", "443", 0);

    char packet_ip[MAX_IP_LENGTH];
    char packet_port[MAX_PORT_LENGTH];

    printf("Enter the IP address of the packet: ");
    scanf("%s", packet_ip);

    printf("Enter the port number of the packet: ");
    scanf("%s", packet_port);

    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(packet_ip, rules[i].ip) == 0 && strcmp(packet_port, rules[i].port) == 0) {
            if (rules[i].action == 1) {
                printf("Packet allowed.\n");
            } else {
                printf("Packet dropped.\n");
            }
            break;
        }
    }

    if (i == num_rules) {
        printf("No matching rule found.\n");
    }

    return 0;
}