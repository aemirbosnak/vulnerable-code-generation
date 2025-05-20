//Falcon-180B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

struct rule {
    char *src_ip;
    char *dst_ip;
    char *src_port;
    char *dst_port;
    int action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    while (num_rules < MAX_RULES) {
        printf("Enter rule (src_ip dst_ip src_port dst_port action):\n");
        scanf("%s %s %s %s %d", rules[num_rules].src_ip, rules[num_rules].dst_ip, rules[num_rules].src_port, rules[num_rules].dst_port, &rules[num_rules].action);
        num_rules++;
    }

    char packet[1024];
    while (fgets(packet, sizeof(packet), stdin)!= NULL) {
        char *src_ip = strtok(packet, " ");
        char *dst_ip = strtok(NULL, " ");
        char *src_port = strtok(NULL, " ");
        char *dst_port = strtok(NULL, " ");

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(src_ip, rules[i].src_ip) == 0 && strcmp(dst_ip, rules[i].dst_ip) == 0 && strcmp(src_port, rules[i].src_port) == 0 && strcmp(dst_port, rules[i].dst_port) == 0) {
                if (rules[i].action == 1) {
                    printf("Packet allowed.\n");
                } else {
                    printf("Packet denied.\n");
                }
                break;
            }
        }

        if (i == num_rules) {
            printf("Packet dropped.\n");
        }
    }

    return 0;
}