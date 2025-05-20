//Falcon-180B DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_LENGTH 100

struct rule {
    char action;
    char source[MAX_LENGTH];
    char destination[MAX_LENGTH];
    char protocol[MAX_LENGTH];
    char port[MAX_LENGTH];
};

void add_rule(struct rule *rules, int count, char action, char *source, char *destination, char *protocol, char *port) {
    strcpy(rules[count].source, source);
    strcpy(rules[count].destination, destination);
    strcpy(rules[count].protocol, protocol);
    strcpy(rules[count].port, port);
    rules[count].action = action;
}

int main() {
    FILE *file;
    char line[MAX_LENGTH];
    char action;
    char source[MAX_LENGTH];
    char destination[MAX_LENGTH];
    char protocol[MAX_LENGTH];
    char port[MAX_LENGTH];
    int count = 0;

    struct rule rules[MAX_RULES];

    file = fopen("firewall.conf", "r");

    if (file == NULL) {
        printf("Error: could not open firewall.conf\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, file)!= NULL) {
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        action = line[0];

        if (action!= 'A' && action!= 'D') {
            printf("Error: invalid action '%c'\n", action);
            exit(1);
        }

        sscanf(line, "%c %[^ ] %[^ ] %[^ ] %[^ ]", &action, source, destination, protocol, port);

        add_rule(rules, count, action, source, destination, protocol, port);

        count++;
    }

    fclose(file);

    printf("Firewall rules:\n");

    for (int i = 0; i < count; i++) {
        printf("Rule %d: %c %s -> %s %s:%s\n", i+1, rules[i].action, rules[i].source, rules[i].destination, rules[i].protocol, rules[i].port);
    }

    return 0;
}