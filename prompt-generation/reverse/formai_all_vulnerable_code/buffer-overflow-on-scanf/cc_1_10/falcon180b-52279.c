//Falcon-180B DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char action;
};

void add_rule(struct rule *rules, int count, char *source_ip, char *dest_ip, char action) {
    if (count >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    strcpy(rules[count].source_ip, source_ip);
    strcpy(rules[count].dest_ip, dest_ip);
    rules[count].action = action;

    count++;
}

int main() {
    struct rule rules[MAX_RULES];
    int count = 0;

    add_rule(rules, count, "192.168.1.1", "192.168.1.2", 'A');
    add_rule(rules, count, "192.168.1.3", "192.168.1.4", 'D');

    char packet_source_ip[16];
    char packet_dest_ip[16];

    printf("Enter the source IP address of the packet: ");
    scanf("%s", packet_source_ip);

    printf("Enter the destination IP address of the packet: ");
    scanf("%s", packet_dest_ip);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(rules[i].source_ip, packet_source_ip) == 0 && strcmp(rules[i].dest_ip, packet_dest_ip) == 0) {
            if (rules[i].action == 'A') {
                printf("Packet allowed.\n");
            } else if (rules[i].action == 'D') {
                printf("Packet dropped.\n");
            }
        }
    }

    if (i == count) {
        printf("No matching rule found.\n");
    }

    return 0;
}