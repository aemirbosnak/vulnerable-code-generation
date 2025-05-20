//Falcon-180B DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 80
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 6

typedef struct {
    char *ip;
    char *port;
    int action;
} rule_t;

typedef struct {
    int num_rules;
    rule_t rules[MAX_RULES];
} firewall_t;

int parse_rule(firewall_t *fw, char *rule_str) {
    char *ip_str, *port_str;
    int action = 0;
    char *token = strtok(rule_str, " ");
    if (token == NULL) {
        return -1;
    }
    if (strcmp(token, "allow") == 0) {
        action = 1;
    } else if (strcmp(token, "deny") == 0) {
        action = 0;
    } else {
        return -1;
    }
    ip_str = strtok(NULL, " ");
    if (ip_str == NULL) {
        return -1;
    }
    port_str = strtok(NULL, " ");
    if (port_str == NULL) {
        return -1;
    }
    fw->rules[fw->num_rules].ip = strdup(ip_str);
    fw->rules[fw->num_rules].port = strdup(port_str);
    fw->rules[fw->num_rules].action = action;
    fw->num_rules++;
    return 0;
}

int evaluate_rule(firewall_t *fw, char *ip, char *port) {
    int i;
    for (i = 0; i < fw->num_rules; i++) {
        if (strcmp(fw->rules[i].ip, ip) == 0 && strcmp(fw->rules[i].port, port) == 0) {
            return fw->rules[i].action;
        }
    }
    return -1;
}

int main() {
    firewall_t fw = {0};
    char *rule_str = "deny 192.168.1.100 80";
    int rc = parse_rule(&fw, rule_str);
    if (rc == 0) {
        char *ip = "192.168.1.100";
        char *port = "80";
        int action = evaluate_rule(&fw, ip, port);
        if (action == 0) {
            printf("Denied\n");
        } else {
            printf("Allowed\n");
        }
    }
    return 0;
}