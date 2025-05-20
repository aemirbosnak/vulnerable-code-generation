//FormAI DATASET v1.0 Category: Firewall ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 20
#define MAX_RULES 100

typedef struct _fw_rule {
    char ip[MAX_IP_LEN];
    char action[10];
} fw_rule;

fw_rule rules[MAX_RULES];
int num_rules = 0;

void add_rule(char* ip, char* action) {
    if (num_rules == MAX_RULES) {
        printf("Cannot add rule. Firewall rules limit reached.\n");
        return;
    }
    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].action, action);
    num_rules++;
}

void list_rules() {
    if (num_rules == 0) {
        printf("No firewall rules found.\n");
        return;
    }
    printf("Firewall Rules:\n");
    for (int i=0; i<num_rules; i++) {
        printf("%s %s\n", rules[i].ip, rules[i].action);
    }
}

int check_rule(char* ip) {
    for (int i=0; i<num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            if (strcmp(rules[i].action, "ALLOW") == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char ip[MAX_IP_LEN];
    char action[10];
    int choice;

    while(1) {
        printf("1. Add Rule\n2. List Rules\n3. Check IP\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter IP: ");
                scanf("%s", ip);
                printf("Enter action (ALLOW/DENY): ");
                scanf("%s", action);
                add_rule(ip, action);
                break;
            case 2:
                list_rules();
                break;
            case 3:
                printf("Enter IP: ");
                scanf("%s", ip);
                if (check_rule(ip)) {
                    printf("IP Allowed.\n");
                } else {
                    printf("IP Blocked.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}