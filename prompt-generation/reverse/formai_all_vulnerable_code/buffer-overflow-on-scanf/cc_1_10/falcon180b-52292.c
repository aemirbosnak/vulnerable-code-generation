//Falcon-180B DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char source_ip[16];
    char dest_ip[16];
    char action;
};

void add_rule(struct rule *rules, int num_rules, char *source_ip, char *dest_ip, char action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        exit(1);
    }

    strcpy(rules[num_rules].source_ip, source_ip);
    strcpy(rules[num_rules].dest_ip, dest_ip);
    rules[num_rules].action = action;

    num_rules++;
}

int match_rule(struct rule *rules, int num_rules, char *source_ip, char *dest_ip) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].dest_ip, dest_ip) == 0) {
            return rules[i].action;
        }
    }

    return -1;
}

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];

    add_rule(rules, num_rules, "192.168.1.1", "192.168.1.2", 'A');
    add_rule(rules, num_rules, "192.168.1.3", "192.168.1.4", 'D');

    char source_ip[16];
    char dest_ip[16];

    printf("Enter source IP: ");
    scanf("%s", source_ip);

    printf("Enter destination IP: ");
    scanf("%s", dest_ip);

    int action = match_rule(rules, num_rules, source_ip, dest_ip);

    if (action == 'A') {
        printf("Access granted.\n");
    } else if (action == 'D') {
        printf("Access denied.\n");
    } else {
        printf("No rule found.\n");
    }

    return 0;
}