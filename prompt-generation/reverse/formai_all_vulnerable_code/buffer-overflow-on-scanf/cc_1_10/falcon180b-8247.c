//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULE_LENGTH 100
#define MAX_RULE_COUNT 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    int source_port;
    int dest_port;
    int action;
};

struct rule rules[MAX_RULE_COUNT];
int rule_count = 0;

void add_rule() {
    if (rule_count >= MAX_RULE_COUNT) {
        printf("Error: maximum rule count reached.\n");
        return;
    }

    printf("Enter source IP address: ");
    scanf("%s", rules[rule_count].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[rule_count].dest_ip);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", rules[rule_count].protocol);

    printf("Enter source port: ");
    scanf("%d", &rules[rule_count].source_port);

    printf("Enter destination port: ");
    scanf("%d", &rules[rule_count].dest_port);

    printf("Enter action (allow/deny): ");
    scanf("%d", &rules[rule_count].action);

    rule_count++;
}

void print_rules() {
    printf("Firewall rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("%d. %s -> %s, %s, %d:%d -> %d:%d (%s)\n", i+1, rules[i].source_ip, rules[i].dest_ip, rules[i].protocol, rules[i].source_port, rules[i].dest_port, rules[i].action == 0? "allow" : "deny");
    }
}

int main() {
    printf("Cyberpunk Firewall v1.0\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add rule\n");
        printf("2. Print rules\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
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