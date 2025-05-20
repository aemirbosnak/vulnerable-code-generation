//Falcon-180B DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_ALLOWED_IPS 100

typedef struct {
    char ip[16];
    char action[10];
} rule_t;

typedef struct {
    rule_t rules[MAX_RULES];
    int num_rules;
} firewall_t;

void init_firewall(firewall_t* fw) {
    fw->num_rules = 0;
}

int add_rule(firewall_t* fw, char* ip, char* action) {
    if (fw->num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return -1;
    }

    strcpy(fw->rules[fw->num_rules].ip, ip);
    strcpy(fw->rules[fw->num_rules].action, action);

    fw->num_rules++;

    return 0;
}

int remove_rule(firewall_t* fw, int index) {
    if (index < 0 || index >= fw->num_rules) {
        printf("Error: Invalid rule index.\n");
        return -1;
    }

    fw->num_rules--;

    return 0;
}

int check_ip(firewall_t* fw, char* ip) {
    int i;

    for (i = 0; i < fw->num_rules; i++) {
        if (strcmp(fw->rules[i].ip, ip) == 0) {
            printf("Access granted.\n");
            return 0;
        }
    }

    printf("Access denied.\n");
    return -1;
}

int main() {
    firewall_t fw;
    char ip[16];

    init_firewall(&fw);

    while (1) {
        printf("Enter IP address: ");
        scanf("%s", ip);

        if (check_ip(&fw, ip) == 0) {
            break;
        }
    }

    return 0;
}