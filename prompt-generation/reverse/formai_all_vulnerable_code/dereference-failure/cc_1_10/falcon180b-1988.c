//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

typedef struct {
    char action;
    char protocol;
    char source_ip[MAX_IP_LENGTH];
    char dest_ip[MAX_IP_LENGTH];
    char source_port[MAX_PORT_LENGTH];
    char dest_port[MAX_PORT_LENGTH];
} rule_t;

void add_rule(rule_t *rules, int num_rules, char *line) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    char *token = strtok(line, " ");
    strcpy(rules[num_rules].action, token);

    token = strtok(NULL, " ");
    if (strcmp(token, "tcp") && strcmp(token, "udp")) {
        printf("Error: Invalid protocol.\n");
        return;
    }
    strcpy(rules[num_rules].protocol, token);

    token = strtok(NULL, " ");
    strcpy(rules[num_rules].source_ip, token);

    token = strtok(NULL, " ");
    strcpy(rules[num_rules].dest_ip, token);

    token = strtok(NULL, " ");
    strcpy(rules[num_rules].source_port, token);

    token = strtok(NULL, " ");
    strcpy(rules[num_rules].dest_port, token);

    num_rules++;
}

int main() {
    FILE *file;
    char line[MAX_RULE_LENGTH];
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    file = fopen("firewall.conf", "r");
    if (file == NULL) {
        printf("Error: Unable to open firewall.conf.\n");
        return 1;
    }

    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        add_rule(rules, num_rules, line);
    }

    fclose(file);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s %s %s:%s -> %s:%s\n", i + 1, rules[i].action, rules[i].protocol, rules[i].source_ip, rules[i].source_port, rules[i].dest_ip, rules[i].dest_port);
    }

    return 0;
}