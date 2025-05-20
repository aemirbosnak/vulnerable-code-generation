//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_STR_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char *pattern;
    int action;
} Rule;

void load_rules(Rule rules[]);
int match_rule(char *str, Rule rule);

int main() {
    Rule rules[MAX_RULES];
    load_rules(rules);

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        int matched = 0;
        for (int i = 0; i < MAX_RULES; i++) {
            if (match_rule(line, rules[i])) {
                matched = 1;
                break;
            }
        }
        if (!matched) {
            printf("Possible intrusion detected: %s\n", line);
        }
    }

    return 0;
}

void load_rules(Rule rules[]) {
    FILE *fp = fopen("rules.txt", "r");
    if (fp == NULL) {
        printf("Error opening rules file.\n");
        exit(1);
    }

    int num_rules = 0;
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *pattern = strtok(line, " ");
        int action = atoi(strtok(NULL, " "));

        if (num_rules >= MAX_RULES) {
            printf("Maximum number of rules exceeded.\n");
            exit(1);
        }

        rules[num_rules].pattern = strdup(pattern);
        rules[num_rules].action = action;
        num_rules++;
    }

    fclose(fp);
}

int match_rule(char *str, Rule rule) {
    return strstr(str, rule.pattern)!= NULL;
}