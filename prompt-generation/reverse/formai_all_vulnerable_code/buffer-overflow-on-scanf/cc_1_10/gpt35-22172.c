//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 50
#define MAX_IP_LEN 15
#define MAX_PORT_LEN 5
#define MAX_PROTOCOL_LEN 10

typedef struct FirewallRule {
    char ip[MAX_IP_LEN];
    int port;
    char protocol[MAX_PROTOCOL_LEN];
} FirewallRule;

typedef struct Packet {
    char ip[MAX_IP_LEN];
    int port;
    char protocol[MAX_PROTOCOL_LEN];
} Packet;

void parse_packet(char *packet_str, Packet *packet) {
    char *token = strtok(packet_str, " ");
    int count = 0;
    while (token != NULL) {
        if (count == 0) {
            strcpy(packet->ip, token);
        } else if (count == 1) {
            packet->port = atoi(token);
        } else if (count == 2) {
            strcpy(packet->protocol, token);
        }
        token = strtok(NULL, " ");
        count++;
    }
}

bool apply_rule(FirewallRule *rule, Packet *packet) {
    if (strcmp(rule->ip, packet->ip) == 0 && rule->port == packet->port && strcmp(rule->protocol, packet->protocol) == 0) {
        return true;
    }
    return false;
}

int main() {
    int num_rules;
    printf("Enter number of firewall rules (up to %d): ", MAX_RULES);
    scanf("%d", &num_rules);

    // Read in rules
    FirewallRule rules[MAX_RULES];
    for (int i = 0; i < num_rules; i++) {
        char ip[MAX_IP_LEN], protocol[MAX_PROTOCOL_LEN];
        int port;
        printf("Enter rule %d (IP address, port number, protocol): ", i+1);
        scanf("%s %d %s", ip, &port, protocol);
        strcpy(rules[i].ip, ip);
        rules[i].port = port;
        strcpy(rules[i].protocol, protocol);
    }

    // Read in packets until "quit" is entered
    while (true) {
        char packet_str[MAX_IP_LEN + MAX_PORT_LEN + MAX_PROTOCOL_LEN + 2];
        printf("Enter packet information to check (IP address, port number, protocol): ");
        scanf("%s", packet_str);

        if (strcmp(packet_str, "quit") == 0) {
            break;
        }

        Packet packet;
        parse_packet(packet_str, &packet);

        bool allowed = false;
        for (int i = 0; i < num_rules; i++) {
            if (apply_rule(&rules[i], &packet)) {
                allowed = true;
                break;
            }
        }

        if (allowed) {
            printf("Packet allowed.\n");
        } else {
            printf("Packet blocked.\n");
        }
    }

    return 0;
}