//FormAI DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <string.h>

struct rule {
    char src_ip[16];
    char dest_ip[16];
    char protocol[10];
    int src_port;
    int dest_port;
};

int main() {
    struct rule rules[10];
    int num_rules = 0;
    char input[100];

    printf("Enter firewall rules:\n");
    fgets(input, 100, stdin);

    while (strcmp(input, "exit\n") != 0) {
        if (num_rules >= 10) {
            printf("Sorry, maximum rules reached, cannot add new rule.\n");
            break;
        }

        sscanf(input, "%s %s %s %d %d", rules[num_rules].src_ip, rules[num_rules].dest_ip, 
                                        rules[num_rules].protocol, &rules[num_rules].src_port, &rules[num_rules].dest_port);
        num_rules++;

        fgets(input, 100, stdin);
    }

    char src_ip[16];
    char dest_ip[16];
    char protocol[10];
    int src_port;
    int dest_port;

    printf("Enter packet details:\n");
    scanf("%s %s %s %d %d", src_ip, dest_ip, protocol, &src_port, &dest_port);

    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(src_ip, rules[i].src_ip) == 0 && strcmp(dest_ip, rules[i].dest_ip) == 0 && 
            strcmp(protocol, rules[i].protocol) == 0 && (src_port == rules[i].src_port || rules[i].src_port == 0) && 
            (dest_port == rules[i].dest_port || rules[i].dest_port == 0)) {
            printf("Packet allowed.\n");
            return 0;
        }
    }

    printf("Packet blocked.\n");
    return 0;
}