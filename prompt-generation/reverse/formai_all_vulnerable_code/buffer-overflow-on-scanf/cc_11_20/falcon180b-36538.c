//Falcon-180B DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULE_NUM 100
#define MAX_RULE_LEN 100
#define MAX_PORT_NUM 65535

typedef struct {
    char ip[16];
    char mask[16];
    char port[6];
    char rule_type;
} Rule;

int main(int argc, char *argv[]) {
    int num_rules = 0;
    Rule rules[MAX_RULE_NUM];

    while (num_rules < MAX_RULE_NUM) {
        printf("Enter a rule (ip mask port type): ");
        scanf("%s %s %s %c", rules[num_rules].ip, rules[num_rules].mask, rules[num_rules].port, &rules[num_rules].rule_type);
        num_rules++;
    }

    char packet_ip[16];
    char packet_port[6];
    while (1) {
        printf("Enter a packet (ip port): ");
        scanf("%s %s", packet_ip, packet_port);

        int i;
        for (i = 0; i < num_rules; i++) {
            if (rules[i].rule_type == 'A') {
                if (strcmp(packet_ip, rules[i].ip) == 0 && strcmp(packet_port, rules[i].port) == 0) {
                    printf("Packet allowed.\n");
                    break;
                }
            } else if (rules[i].rule_type == 'D') {
                if (strcmp(packet_ip, rules[i].ip) == 0 && strcmp(packet_port, rules[i].port) == 0) {
                    printf("Packet denied.\n");
                    break;
                }
            }
        }

        if (i == num_rules) {
            printf("No matching rule found.\n");
        }
    }

    return 0;
}