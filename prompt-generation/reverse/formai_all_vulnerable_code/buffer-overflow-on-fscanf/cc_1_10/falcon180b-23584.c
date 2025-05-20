//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RULES 1000
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char action;
} rule_t;

void add_rule(rule_t *rule) {
    FILE *file = fopen("rules.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open rules.txt for writing.\n");
        exit(1);
    }

    fprintf(file, "%s %c\n", rule->ip, rule->action);

    fclose(file);
}

void load_rules(rule_t rules[MAX_RULES]) {
    FILE *file = fopen("rules.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open rules.txt for reading.\n");
        exit(1);
    }

    int num_rules = 0;

    while (fscanf(file, "%s %c\n", rules[num_rules].ip, &rules[num_rules].action) == 2) {
        num_rules++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    rule_t rules[MAX_RULES];
    int num_rules = 0;

    load_rules(rules);

    while (1) {
        char ip[MAX_IP_LENGTH];
        sprintf(ip, "192.168.%d.%d", rand() % 256, rand() % 256);

        int i;
        for (i = 0; i < num_rules; i++) {
            if (strcmp(ip, rules[i].ip) == 0) {
                if (rules[i].action == 'A') {
                    printf("Access granted for IP %s.\n", ip);
                } else if (rules[i].action == 'D') {
                    printf("Access denied for IP %s.\n", ip);
                    return 1;
                }
            }
        }

        add_rule(&(rules[num_rules]));
        num_rules++;
    }

    return 0;
}