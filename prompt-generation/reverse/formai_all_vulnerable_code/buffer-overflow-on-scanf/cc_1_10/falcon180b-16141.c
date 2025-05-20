//Falcon-180B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char *src_ip;
    char *dst_ip;
    char *protocol;
    int src_port;
    int dst_port;
    int action;
};

void add_rule(struct rule *rules, int count, char *line) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token!= NULL && i < MAX_RULE_LENGTH) {
        if (i == 0) {
            rules[count].src_ip = token;
        } else if (i == 1) {
            rules[count].dst_ip = token;
        } else if (i == 2) {
            rules[count].protocol = token;
        } else if (i == 3) {
            rules[count].src_port = atoi(token);
        } else if (i == 4) {
            rules[count].dst_port = atoi(token);
        } else if (i == 5) {
            rules[count].action = atoi(token);
        }

        token = strtok(NULL, " ");
        i++;
    }

    if (i!= MAX_RULE_LENGTH) {
        printf("Invalid rule format: %s\n", line);
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char line[256];
    int count = 0;

    printf("Enter the name of the rules file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct rule rules[MAX_RULES];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_RULES) {
            printf("Maximum number of rules exceeded\n");
            break;
        }

        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        add_rule(rules, count, line);
        count++;
    }

    fclose(fp);

    printf("Firewall rules loaded:\n");

    for (int i = 0; i < count; i++) {
        printf("Rule %d: %s -> %s (%s) %d:%d -> %d:%d Action: %d\n", i+1, rules[i].src_ip, rules[i].dst_ip, rules[i].protocol, rules[i].src_port, rules[i].dst_port, rules[i].action);
    }

    return 0;
}