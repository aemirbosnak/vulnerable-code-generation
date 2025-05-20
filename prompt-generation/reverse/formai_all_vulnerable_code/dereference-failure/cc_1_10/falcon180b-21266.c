//Falcon-180B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char *source_ip;
    char *destination_ip;
    char *protocol;
    int action;
};

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;

    FILE *file = fopen("firewall.conf", "r");
    if (file == NULL) {
        printf("Error: Could not open firewall configuration file.\n");
        return 1;
    }

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, file)!= NULL) {
        if (num_rules >= MAX_RULES) {
            printf("Error: Maximum number of rules exceeded.\n");
            return 1;
        }

        char *token = strtok(line, " ");
        rules[num_rules].source_ip = strdup(token);

        token = strtok(NULL, " ");
        rules[num_rules].destination_ip = strdup(token);

        token = strtok(NULL, " ");
        rules[num_rules].protocol = strdup(token);

        token = strtok(NULL, " ");
        rules[num_rules].action = atoi(token);

        num_rules++;
    }

    fclose(file);

    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("Rule %d: %s -> %s (%s) -> %d\n", i+1, rules[i].source_ip, rules[i].destination_ip, rules[i].protocol, rules[i].action);
    }

    return 0;
}