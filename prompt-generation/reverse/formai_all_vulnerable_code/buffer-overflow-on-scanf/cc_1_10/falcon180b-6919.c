//Falcon-180B DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char action;
};

int main() {
    int num_rules;
    struct rule rules[MAX_RULES];

    printf("Enter the number of rules:\n");
    scanf("%d", &num_rules);

    for (int i = 0; i < num_rules; i++) {
        printf("Enter rule %d:\n", i+1);
        scanf("%s %s %c", rules[i].source_ip, rules[i].dest_ip, &rules[i].action);
    }

    char packet_src_ip[16];
    char packet_dest_ip[16];

    printf("Enter the source IP of the packet:\n");
    scanf("%s", packet_src_ip);

    printf("Enter the destination IP of the packet:\n");
    scanf("%s", packet_dest_ip);

    for (int i = 0; i < num_rules; i++) {
        if (strcmp(packet_src_ip, rules[i].source_ip) == 0 && strcmp(packet_dest_ip, rules[i].dest_ip) == 0) {
            switch (rules[i].action) {
                case 'A':
                    printf("Packet allowed.\n");
                    break;
                case 'D':
                    printf("Packet dropped.\n");
                    break;
                default:
                    printf("Invalid action.\n");
                    break;
            }
            return 0;
        }
    }

    printf("No rule found for the given packet.\n");

    return 0;
}