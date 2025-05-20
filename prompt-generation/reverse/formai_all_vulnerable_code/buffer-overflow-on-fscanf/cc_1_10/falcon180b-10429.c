//Falcon-180B DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

struct rule {
    char ip[MAX_IP_LENGTH];
    char action;
};

int load_rules(struct rule* rules) {
    FILE* file = fopen("firewall_rules.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open firewall_rules.txt\n");
        return 1;
    }

    int num_rules = 0;
    while (fscanf(file, "%s %c\n", rules[num_rules].ip, &rules[num_rules].action) == 2) {
        num_rules++;
    }

    fclose(file);
    return num_rules;
}

int match_rule(struct rule* rules, int num_rules, char* ip) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = load_rules(rules);

    char ip[MAX_IP_LENGTH];

    while (1) {
        printf("Enter an IP address: ");
        scanf("%s", ip);

        int action = match_rule(rules, num_rules, ip);

        if (action == 'a') {
            printf("Access allowed.\n");
        } else if (action == 'd') {
            printf("Access denied.\n");
        } else {
            printf("No rule found for IP address.\n");
        }
    }

    return 0;
}