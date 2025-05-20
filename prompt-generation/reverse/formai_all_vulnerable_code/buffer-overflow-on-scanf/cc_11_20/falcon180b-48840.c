//Falcon-180B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

struct rule {
    char *protocol;
    char *source_ip;
    char *destination_ip;
    char *source_port;
    char *destination_port;
    int action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    while (num_rules < MAX_RULES) {
        printf("Enter rule (protocol source_ip destination_ip source_port destination_port action):\n");
        scanf("%s %s %s %s %s %d", rules[num_rules].protocol, rules[num_rules].source_ip, rules[num_rules].destination_ip, rules[num_rules].source_port, rules[num_rules].destination_port, &rules[num_rules].action);
        num_rules++;
    }

    while (1) {
        char packet[1000];
        fgets(packet, sizeof(packet), stdin);

        char *protocol = strtok(packet, " ");
        char *source_ip = strtok(NULL, " ");
        char *destination_ip = strtok(NULL, " ");
        char *source_port = strtok(NULL, " ");
        char *destination_port = strtok(NULL, " ");

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(protocol, rules[i].protocol) == 0 && strcmp(source_ip, rules[i].source_ip) == 0 && strcmp(destination_ip, rules[i].destination_ip) == 0 && strcmp(source_port, rules[i].source_port) == 0 && strcmp(destination_port, rules[i].destination_port) == 0) {
                if (rules[i].action == 1) {
                    printf("Packet allowed.\n");
                } else {
                    printf("Packet denied.\n");
                }
                break;
            }
        }

        if (i == num_rules) {
            printf("No rule found.\n");
        }
    }

    return 0;
}