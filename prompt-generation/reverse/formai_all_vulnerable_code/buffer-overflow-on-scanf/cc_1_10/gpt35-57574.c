//FormAI DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50

struct rule {
    char src_ip[16];
    char dst_ip[16];
    char protocol[10];
    int src_port;
    int dst_port;
    int action; // 1 = ALLOW, 0 = DENY
};

void add_rule(struct rule rules[], int *count) {
    if (*count >= MAX_RULES) {
        printf("Max rules reached\n");
        return;
    }
    struct rule r;
    printf("Enter rule details (src_ip dst_ip protocol src_port dst_port action):\n");
    scanf("%s %s %s %d %d %d", r.src_ip, r.dst_ip, r.protocol, &r.src_port, &r.dst_port, &r.action);
    rules[*count] = r;
    (*count)++;
    printf("Rule added successfully\n");
}

void list_rules(struct rule rules[], int count) {
    printf("RULES:\n");
    for (int i = 0; i < count; i++) {
        printf("Rule %d: %s %s %s %d %d %s\n", i+1, rules[i].src_ip, rules[i].dst_ip, 
            rules[i].protocol, rules[i].src_port, rules[i].dst_port, (rules[i].action ? "ALLOW" : "DENY"));
    }
}

int check_rule(struct rule r, char src_ip[], char dst_ip[], char protocol[], int src_port, int dst_port) {
    if (strcmp(r.src_ip, src_ip) != 0 && strcmp(r.src_ip, "*") != 0) {
        return 0;
    }
    if (strcmp(r.dst_ip, dst_ip) != 0 && strcmp(r.dst_ip, "*") != 0) {
        return 0;
    }
    if (strcmp(r.protocol, protocol) != 0 && strcmp(r.protocol, "*") != 0) {
        return 0;
    }
    if (r.src_port != src_port && r.src_port != 0) {
        return 0;
    }
    if (r.dst_port != dst_port && r.dst_port != 0) {
        return 0;
    }
    return r.action;
}

int main() {
    struct rule rules[MAX_RULES];
    int rule_count = 0;
    int choice;
    do {
        printf("1. Add rule\n2. List rules\n3. Filter packet\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_rule(rules, &rule_count);
                break;
            case 2:
                list_rules(rules, rule_count);
                break;
            case 3: {
                char src_ip[16], dst_ip[16], protocol[10];
                int src_port, dst_port;
                printf("Enter packet details (src_ip dst_ip protocol src_port dst_port):\n");
                scanf("%s %s %s %d %d", src_ip, dst_ip, protocol, &src_port, &dst_port);
                int action_taken = 0;
                for (int i = 0; i < rule_count; i++) {
                    int action = check_rule(rules[i], src_ip, dst_ip, protocol, src_port, dst_port);
                    if (action == 1) {
                        printf("ALLOWED\n");
                        action_taken = 1;
                        break;
                    } else if (action == 0) {
                        printf("DENIED\n");
                        action_taken = 1;
                        break;
                    }
                }
                if (!action_taken) {
                    printf("ALLOWED (default action)\n");
                }
                break;
            }
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}