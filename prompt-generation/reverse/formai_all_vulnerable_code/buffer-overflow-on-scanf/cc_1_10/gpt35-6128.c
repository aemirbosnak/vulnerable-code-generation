//FormAI DATASET v1.0 Category: Firewall ; Style: calm
// This program is a simple firewall implementation
// It checks incoming packets for certain rules
// And allows or blocks traffic accordingly

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 100 // Maximum number of rules to be loaded
#define MAX_IP_LEN 16 // Maximum length of an IP address

struct Rule {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    int source_port;
    int dest_port; 
    bool allow;
};

struct Packet {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    int source_port;
    int dest_port;
};

// Function to check if a packet matches a rule
bool match_rule(const struct Packet* packet, const struct Rule* rule) {
    if (strcmp(packet->source_ip, rule->source_ip) == 0 ||
        strcmp(rule->source_ip, "any") == 0) {
        if (strcmp(packet->dest_ip, rule->dest_ip) == 0 ||
            strcmp(rule->dest_ip, "any") == 0) {
            if (packet->source_port == rule->source_port ||
                rule->source_port == -1) {
                if (packet->dest_port == rule->dest_port ||
                    rule->dest_port == -1) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Main function
int main() {
    struct Rule rules[MAX_RULES];
    int num_rules = 0;
    char input[MAX_IP_LEN + 1];
    
    printf("Enter rules (type 'done' to finish):\n");
    while (num_rules < MAX_RULES) {
        printf("Rule #%d: ", num_rules + 1);
        scanf(" %s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        strcpy(rules[num_rules].source_ip, input);
        scanf(" %s", input);
        strcpy(rules[num_rules].dest_ip, input);
        scanf("%d", &rules[num_rules].source_port);
        scanf("%d", &rules[num_rules].dest_port);
        scanf(" %s", input);
        if (strcmp(input, "allow") == 0) {
            rules[num_rules].allow = true;
        } else {
            rules[num_rules].allow = false;
        }
        num_rules++;
    }
    
    printf("Enter packets (type 'done' to finish):\n");
    while (true) {
        printf("Packet: ");
        struct Packet packet;
        scanf(" %s", packet.source_ip);
        if (strcmp(packet.source_ip, "done") == 0) {
            break;
        }
        scanf(" %s", packet.dest_ip);
        scanf("%d", &packet.source_port);
        scanf("%d", &packet.dest_port);
        
        bool allowed = false;
        for (int i = 0; i < num_rules; i++) {
            if (match_rule(&packet, &rules[i])) {
                if (rules[i].allow) {
                    printf("Packet allowed.\n");
                    allowed = true;
                    break;
                } else {
                    printf("Packet blocked.\n");
                    allowed = true;
                    break;
                }
            }
        }
        if (!allowed) {
            printf("Packet allowed (no matching rules).\n");
        }
    }
    
    return 0;
}