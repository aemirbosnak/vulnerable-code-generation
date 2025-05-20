//Falcon-180B DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define ALLOW 1
#define DENY 0
#define ANY "*"

struct rule {
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
};

int main() {
    int num_rules = 0;
    struct rule rules[MAX_RULES];
    char line[MAX_RULE_LENGTH];

    FILE *file = fopen("firewall.conf", "r");
    if (file == NULL) {
        printf("Error: Could not open firewall.conf\n");
        exit(1);
    }

    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Error: Maximum number of rules exceeded\n");
            exit(1);
        }

        char *ip_str = strtok(line, " \t\r\n");
        char *port_str = strtok(NULL, " \t\r\n");
        char *action_str = strtok(NULL, " \t\r\n");

        if (ip_str == NULL || port_str == NULL || action_str == NULL) {
            printf("Error: Invalid rule format\n");
            exit(1);
        }

        strcpy(rules[num_rules].ip, ip_str);
        strcpy(rules[num_rules].port, port_str);

        if (strcmp(action_str, "allow") == 0) {
            rules[num_rules].action = ALLOW;
        } else if (strcmp(action_str, "deny") == 0) {
            rules[num_rules].action = DENY;
        } else {
            printf("Error: Invalid action\n");
            exit(1);
        }

        num_rules++;
    }

    fclose(file);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s:%s %s\n", rules[i].ip, rules[i].port, rules[i].action == ALLOW? "allow" : "deny");
    }

    return 0;
}