//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define RULE_LEN 16

typedef struct {
    char src_ip[RULE_LEN];
    char dst_ip[RULE_LEN];
    int action; // 0 = allow, 1 = deny
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void add_rule(const char *src_ip, const char *dst_ip, int action) {
    if (rule_count < MAX_RULES) {
        strncpy(rules[rule_count].src_ip, src_ip, RULE_LEN);
        strncpy(rules[rule_count].dst_ip, dst_ip, RULE_LEN);
        rules[rule_count].action = action;
        rule_count++;
        printf("Rule added: %s -> %s %s\n", src_ip, dst_ip, action == 0 ? "ALLOW" : "DENY");
    } else {
        printf("Maximum rule limit reached!\n");
    }
}

int check_packet(const char *src_ip, const char *dst_ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].src_ip, src_ip) == 0 && strcmp(rules[i].dst_ip, dst_ip) == 0) {
            return rules[i].action;
        }
    }
    return 0; // Default action is allow
}

void list_rules() {
    printf("\nCurrent Firewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("Rule %d: %s -> %s %s\n", i + 1, rules[i].src_ip, rules[i].dst_ip, 
               rules[i].action == 0 ? "ALLOW" : "DENY");
    }
}

void clear_rules() {
    rule_count = 0;
    printf("All rules cleared!\n");
}

int main() {
    int option;
    char src[RULE_LEN], dst[RULE_LEN];

    while (1) {
        printf("\n==== Simple C Firewall ====\n");
        printf("1. Add Rule\n");
        printf("2. Check Packet\n");
        printf("3. List Rules\n");
        printf("4. Clear Rules\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter source IP: ");
                scanf("%s", src);
                printf("Enter destination IP: ");
                scanf("%s", dst);
                printf("Enter action (0 for ALLOW, 1 for DENY): ");
                int action;
                scanf("%d", &action);
                add_rule(src, dst, action);
                break;
            case 2:
                printf("Enter source IP to check: ");
                scanf("%s", src);
                printf("Enter destination IP to check: ");
                scanf("%s", dst);
                int result = check_packet(src, dst);
                printf("Packet from %s to %s will be %s\n", src, dst, 
                       result == 0 ? "ALLOWED" : "DENIED");
                break;
            case 3:
                list_rules();
                break;
            case 4:
                clear_rules();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}