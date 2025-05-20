//Falcon-180B DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char action;
    char protocol[10];
    char src_ip[16];
    char dst_ip[16];
    char src_port[6];
    char dst_port[6];
};

void add_rule(struct rule *rules, int num_rules) {
    printf("Enter action (A/D): ");
    char action;
    scanf("%c", &action);

    printf("Enter protocol (tcp/udp): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter source IP: ");
    scanf("%s", rules[num_rules].src_ip);

    printf("Enter destination IP: ");
    scanf("%s", rules[num_rules].dst_ip);

    printf("Enter source port: ");
    scanf("%s", rules[num_rules].src_port);

    printf("Enter destination port: ");
    scanf("%s", rules[num_rules].dst_port);

    rules[num_rules].action = action;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    while (num_rules < MAX_RULES) {
        add_rule(rules, num_rules);
        num_rules++;
    }

    char input_buffer[1024];
    while (1) {
        memset(input_buffer, 0, sizeof(input_buffer));
        fgets(input_buffer, sizeof(input_buffer), stdin);

        char *token = strtok(input_buffer, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "tcp") == 0 || strcmp(token, "udp") == 0) {
            int i;
            for (i = 0; i < num_rules; i++) {
                if (strcmp(rules[i].protocol, token) == 0) {
                    if (rules[i].action == 'A') {
                        printf("Allow\n");
                    } else {
                        printf("Deny\n");
                    }
                    break;
                }
            }
        }
    }

    return 0;
}