//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LINE_LEN 1024
#define MAX_RULE_LEN 256

typedef struct {
    char *pattern;
    int action;
} rule_t;

void load_rules(rule_t *rules) {
    char line[MAX_LINE_LEN];
    FILE *fp = fopen("rules.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open rules file.\n");
        exit(1);
    }

    int rule_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));

        if (rule_count >= MAX_RULES) {
            printf("Error: Too many rules.\n");
            exit(1);
        }

        rules[rule_count].pattern = strdup(pattern);
        rules[rule_count].action = action;
        rule_count++;
    }

    fclose(fp);
}

int match_rule(char *data, rule_t *rule) {
    return strstr(data, rule->pattern)!= NULL;
}

void handle_packet(char *data, rule_t *rules) {
    int rule_matched = 0;
    int i;

    for (i = 0; i < MAX_RULES; i++) {
        if (rules[i].pattern!= NULL && match_rule(data, &rules[i])) {
            printf("Rule %d matched: %s\n", i, rules[i].pattern);
            rule_matched = 1;
            break;
        }
    }

    if (!rule_matched) {
        printf("No rules matched.\n");
    }
}

int main() {
    rule_t rules[MAX_RULES];
    load_rules(rules);

    char packet[MAX_LINE_LEN];
    while (fgets(packet, MAX_LINE_LEN, stdin)!= NULL) {
        handle_packet(packet, rules);
    }

    return 0;
}