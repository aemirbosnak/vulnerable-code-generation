//Falcon-180B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

struct rule {
    char action;
    char protocol;
    char source_ip[MAX_IP_LENGTH];
    char dest_ip[MAX_IP_LENGTH];
    char source_port[6];
    char dest_port[6];
};

int load_rules(struct rule* rules) {
    FILE* fp = fopen("firewall_rules.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open firewall_rules.txt\n");
        exit(1);
    }

    int num_rules = 0;
    while (fscanf(fp, "%c %c %15s %15s %5s %5s\n", &rules[num_rules].action, &rules[num_rules].protocol, rules[num_rules].source_ip, rules[num_rules].dest_ip, rules[num_rules].source_port, rules[num_rules].dest_port) == 6) {
        num_rules++;
        if (num_rules >= MAX_RULES) {
            printf("Error: too many rules in firewall_rules.txt\n");
            exit(1);
        }
    }

    fclose(fp);
    return num_rules;
}

int match_rule(struct rule* rules, int num_rules, char* ip, int port, char* protocol) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(protocol, rules[i].protocol) == 0) {
            if (strcmp(ip, rules[i].source_ip) == 0 || strcmp(ip, rules[i].dest_ip) == 0) {
                if (atoi(rules[i].source_port) == port || atoi(rules[i].dest_port) == port) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = load_rules(rules);

    char* ip;
    int port;
    char protocol[6];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        printf("Enter port number: ");
        scanf("%d", &port);

        printf("Enter protocol (tcp or udp): ");
        scanf("%s", protocol);

        int rule_index = match_rule(rules, num_rules, ip, port, protocol);
        if (rule_index >= 0) {
            if (rules[rule_index].action == 'a') {
                printf("Access allowed\n");
            } else {
                printf("Access denied\n");
            }
        } else {
            printf("No matching rule found\n");
        }
    }

    return 0;
}