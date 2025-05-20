//Falcon-180B DATASET v1.0 Category: Firewall ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

struct rule {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    char action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    while (num_rules < MAX_RULES) {
        printf("Enter rule (ip:port:allow/deny): ");
        scanf("%s:%s:%c", rules[num_rules].ip, rules[num_rules].port, &rules[num_rules].action);
        num_rules++;
    }

    char input_ip[MAX_IP_LENGTH];
    char input_port[MAX_PORT_LENGTH];

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", input_ip);

        printf("Enter port number: ");
        scanf("%s", input_port);

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(input_ip, rules[i].ip) == 0 && strcmp(input_port, rules[i].port) == 0) {
                if (rules[i].action == 'a') {
                    printf("Access allowed.\n");
                } else {
                    printf("Access denied.\n");
                }
                break;
            }
        }

        if (i == num_rules) {
            printf("No rule found for this IP address and port.\n");
        }
    }

    return 0;
}