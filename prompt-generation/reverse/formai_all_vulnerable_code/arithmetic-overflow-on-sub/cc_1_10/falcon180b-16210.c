//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 100

typedef struct {
    char action;
    char protocol;
    char source_ip[15];
    char dest_ip[15];
    char source_port[6];
    char dest_port[6];
} rule_t;

int num_rules = 0;
rule_t rules[MAX_RULES];

void add_rule() {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    printf("Enter rule action (allow/deny): ");
    char action = getchar();

    printf("Enter protocol (tcp/udp): ");
    char protocol = getchar();

    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dest_port);

    rules[num_rules].action = action;
    rules[num_rules].protocol = protocol;

    num_rules++;
}

void print_rules() {
    printf("Firewall Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d: Action: %c, Protocol: %c, Source IP: %s, Dest IP: %s, Source Port: %s, Dest Port: %s\n",
                i+1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].dest_ip, rules[i].source_port, rules[i].dest_port);
    }
}

int main() {
    printf("Firewall Configuration\n");

    while(1) {
        printf("\n1. Add Rule\n2. Print Rules\n3. Exit\n");
        int choice = getchar() - '0';

        switch(choice) {
            case 1:
                add_rule();
                break;
            case 2:
                print_rules();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}