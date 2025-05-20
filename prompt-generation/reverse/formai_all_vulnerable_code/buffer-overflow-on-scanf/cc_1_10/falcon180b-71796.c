//Falcon-180B DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_RULES 10
#define MAX_RULE_LEN 100

typedef struct {
    char rule[MAX_RULE_LEN];
    int is_allow;
} rule_t;

void add_rule(rule_t* rules, int num_rules, char* rule, int is_allow) {
    if (num_rules >= MAX_RULES) {
        printf("Error: maximum number of rules reached\n");
        exit(1);
    }

    strcpy(rules[num_rules].rule, rule);
    rules[num_rules].is_allow = is_allow;
    num_rules++;
}

int match_rule(rule_t* rules, int num_rules, char* request) {
    for (int i = 0; i < num_rules; i++) {
        if (strstr(request, rules[i].rule)) {
            return rules[i].is_allow;
        }
    }
    return 0;
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules, "GET /admin", 0);
    add_rule(rules, num_rules, "GET /login", 1);
    add_rule(rules, num_rules, "POST /login", 1);
    add_rule(rules, num_rules, "GET /logout", 1);
    add_rule(rules, num_rules, "GET /profile", 1);
    add_rule(rules, num_rules, "POST /profile", 0);
    add_rule(rules, num_rules, "GET /settings", 1);
    add_rule(rules, num_rules, "POST /settings", 1);
    add_rule(rules, num_rules, "GET /admin/settings", 0);
    add_rule(rules, num_rules, "POST /admin/settings", 0);

    char request[MAX_RULE_LEN];
    printf("Enter request:\n");
    scanf("%s", request);

    int is_allowed = match_rule(rules, num_rules, request);

    if (is_allowed) {
        printf("Request allowed\n");
    } else {
        printf("Request denied\n");
    }

    return 0;
}