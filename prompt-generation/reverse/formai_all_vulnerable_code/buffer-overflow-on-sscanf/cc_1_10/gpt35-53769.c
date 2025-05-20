//FormAI DATASET v1.0 Category: Firewall ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define a maximum number of rules allowed
#define MAX_RULES 100


// Define a rule struct
typedef struct {
    char src_ip[16];
    char dest_ip[16];
    int src_port;
    int dest_port;
    char protocol[10];
    char action[10];
} Rule;


// Function to read rules from a file
int load_rules(FILE *fp, Rule *rules) {
    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        Rule rule;
        sscanf(line, "%s %s %d %d %s %s", rule.src_ip, rule.dest_ip, &rule.src_port, &rule.dest_port, rule.protocol, rule.action);
        rules[i] = rule;
        i++;
    }
    return i;
}


// Function to check if a packet matches a rule
int match_rule(Rule rule, char *src_ip, char *dest_ip, int src_port, int dest_port, char *protocol) {
    if (strcmp(rule.src_ip, "*") == 0 || strcmp(rule.src_ip, src_ip) == 0) {
        if (strcmp(rule.dest_ip, "*") == 0 || strcmp(rule.dest_ip, dest_ip) == 0) {
            if (rule.src_port == 0 || rule.src_port == src_port) {
                if (rule.dest_port == 0 || rule.dest_port == dest_port) {
                    if (strcmp(rule.protocol, "*") == 0 || strcmp(rule.protocol, protocol) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


// Function to determine the action to take based on a packet
char *apply_rules(Rule *rules, int num_rules, char *src_ip, char *dest_ip, int src_port, int dest_port, char *protocol) {
    char *action = "deny";
    for (int i = 0; i < num_rules; i++) {
        if (match_rule(rules[i], src_ip, dest_ip, src_port, dest_port, protocol)) {
            action = rules[i].action;
            break;
        }
    }
    return action;
}


int main() {
    // Load rules from file
    FILE *fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open rules file\n");
        return 1;
    }

    Rule rules[MAX_RULES];
    int num_rules = load_rules(fp, rules);

    // Loop to process packets
    while (1) {
        char packet[1024];
        printf("Enter packet information (src_ip dest_ip src_port dest_port protocol): ");
        fgets(packet, sizeof(packet), stdin);

        char src_ip[16];
        char dest_ip[16];
        int src_port;
        int dest_port;
        char protocol[10];
        sscanf(packet, "%s %s %d %d %s", src_ip, dest_ip, &src_port, &dest_port, protocol);

        // Apply rules to determine action to take
        char *action = apply_rules(rules, num_rules, src_ip, dest_ip, src_port, dest_port, protocol);

        printf("Action: %s\n", action);
    }

    return 0;
}