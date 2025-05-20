//Falcon-180B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char action;
    char protocol;
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
};

int add_rule(struct rule *rules, int num_rules) {
    printf("Enter action (A/D): ");
    scanf("%c", &rules[num_rules].action);

    printf("Enter protocol (TCP/UDP): ");
    scanf("%c", &rules[num_rules].protocol);

    printf("Enter source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter destination IP address: ");
    scanf("%s", rules[num_rules].destination_ip);

    printf("Enter source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter destination port: ");
    scanf("%d", &rules[num_rules].destination_port);

    return num_rules + 1;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        num_rules = add_rule(rules, num_rules);
    }

    while (1) {
        char packet[1024];
        int len = recv(0, packet, sizeof(packet), 0);

        if (len <= 0) {
            break;
        }

        struct rule *match = NULL;
        for (int i = 0; i < num_rules; i++) {
            if ((packet[9] == rules[i].protocol && rules[i].action == 'A') ||
                (packet[9] == rules[i].protocol && rules[i].action == 'D')) {
                match = &rules[i];
                break;
            }
        }

        if (match == NULL) {
            printf("Packet dropped\n");
        } else {
            printf("Packet allowed\n");
        }
    }

    return 0;
}