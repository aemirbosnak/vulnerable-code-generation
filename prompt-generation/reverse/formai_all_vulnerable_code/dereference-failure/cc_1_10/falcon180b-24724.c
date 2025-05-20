//Falcon-180B DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 80

struct rule {
    char src_ip[16];
    char dst_ip[16];
    char protocol[10];
    char action[10];
};

int main() {
    FILE *fp;
    char line[MAX_RULE_SIZE];
    char *token;
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    fp = fopen("firewall.conf", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening firewall.conf: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_RULE_SIZE, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        strcpy(rules[num_rules].src_ip, token);
        token = strtok(NULL, " ");
        strcpy(rules[num_rules].dst_ip, token);
        token = strtok(NULL, " ");
        strcpy(rules[num_rules].protocol, token);
        token = strtok(NULL, " ");
        strcpy(rules[num_rules].action, token);

        num_rules++;
    }

    fclose(fp);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s -> %s (%s) %s\n", i + 1, rules[i].src_ip, rules[i].dst_ip, rules[i].protocol, rules[i].action);
    }

    return 0;
}