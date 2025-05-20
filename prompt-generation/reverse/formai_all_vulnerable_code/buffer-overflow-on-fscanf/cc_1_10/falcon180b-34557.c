//Falcon-180B DATASET v1.0 Category: Firewall ; Style: introspective
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
    int action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    FILE *rules_file = fopen("firewall_rules.txt", "r");

    if (rules_file == NULL) {
        printf("Error: Could not open rules file.\n");
        exit(1);
    }

    while (fscanf(rules_file, "%s %s %d", rules[num_rules].ip, rules[num_rules].port, &rules[num_rules].action)!= EOF) {
        num_rules++;

        if (num_rules >= MAX_RULES) {
            printf("Error: Too many rules.\n");
            exit(1);
        }
    }

    fclose(rules_file);

    char input_ip[MAX_IP_LENGTH];
    char input_port[MAX_PORT_LENGTH];

    while (1) {
        printf("Enter IP address: ");
        fgets(input_ip, MAX_IP_LENGTH, stdin);

        printf("Enter port number: ");
        fgets(input_port, MAX_PORT_LENGTH, stdin);

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(input_ip, rules[i].ip) == 0 && strcmp(input_port, rules[i].port) == 0) {
                if (rules[i].action == 0) {
                    printf("Access denied.\n");
                } else {
                    printf("Access granted.\n");
                }
                break;
            }
        }

        if (i == num_rules) {
            printf("No rule found for this IP/port combination.\n");
        }
    }

    return 0;
}