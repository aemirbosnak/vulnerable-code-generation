//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80
#define ALLOW 1
#define DENY 0

struct rule {
    char *ip;
    char *port;
    int action;
};

int read_rules(struct rule *rules) {
    FILE *file;
    char line[MAX_RULE_LENGTH];
    int count = 0;

    file = fopen("firewall.rules", "r");
    if (file == NULL) {
        printf("Error: could not open rules file\n");
        return -1;
    }

    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        if (count >= MAX_RULES) {
            printf("Error: too many rules\n");
            fclose(file);
            return -1;
        }

        char *ip = strtok(line, " ");
        char *port = strtok(NULL, " ");
        int action = (strcmp(port, "allow") == 0)? ALLOW : DENY;

        rules[count].ip = strdup(ip);
        rules[count].port = strdup(port);
        rules[count].action = action;

        count++;
    }

    fclose(file);
    return count;
}

int is_allowed(struct rule *rules, int count, char *ip, char *port) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(rules[i].ip, ip) == 0 && strcmp(rules[i].port, port) == 0) {
            if (rules[i].action == ALLOW) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    return 0;
}

int main() {
    struct rule rules[MAX_RULES];
    int count = read_rules(rules);

    if (count <= 0) {
        return 1;
    }

    char ip[16];
    char port[6];

    while (1) {
        printf("Enter IP address: ");
        scanf("%15s", ip);

        printf("Enter port number: ");
        scanf("%5s", port);

        if (is_allowed(rules, count, ip, port)) {
            printf("Access allowed\n");
        } else {
            printf("Access denied\n");
        }
    }

    return 0;
}