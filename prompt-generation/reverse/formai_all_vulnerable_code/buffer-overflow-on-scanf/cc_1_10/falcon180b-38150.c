//Falcon-180B DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
    int protocol;
    int action;
};

void add_rule(struct rule *rules, int num_rules) {
    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%d", &rules[num_rules].dest_port);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%d", &rules[num_rules].protocol);

    printf("Enter action (allow/deny): ");
    scanf("%d", &rules[num_rules].action);

    num_rules++;
}

void print_rules(struct rule *rules, int num_rules) {
    printf("Number of rules: %d\n", num_rules);
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Destination IP: %s\n", rules[i].dest_ip);
        printf("Source port: %d\n", rules[i].source_port);
        printf("Destination port: %d\n", rules[i].dest_port);
        printf("Protocol: %d\n", rules[i].protocol);
        printf("Action: %s\n\n", rules[i].action == 0? "allow" : "deny");
    }
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        printf("Enter 1 to add a rule, 0 to finish:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_rule(rules, num_rules);
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    print_rules(rules, num_rules);

    return 0;
}