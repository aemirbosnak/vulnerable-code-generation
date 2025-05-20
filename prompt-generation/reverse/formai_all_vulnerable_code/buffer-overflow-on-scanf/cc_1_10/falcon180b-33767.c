//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_RULES 100
#define MAX_RULE_LENGTH 256

typedef struct {
    char *pattern;
    char *replacement;
} Rule;

int num_rules = 0;
Rule rules[MAX_NUM_RULES];

void add_rule(char *pattern, char *replacement) {
    if (num_rules >= MAX_NUM_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }

    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].replacement = strdup(replacement);

    num_rules++;
}

void apply_rules(char *line) {
    int i;

    for (i = 0; i < num_rules; i++) {
        char *pos = strstr(line, rules[i].pattern);

        while (pos!= NULL) {
            *pos = '\0';
            strcat(line, rules[i].replacement);
            pos += strlen(rules[i].replacement);
            pos = strstr(pos, rules[i].pattern);
        }
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char filename[MAX_LINE_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        apply_rules(line);
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}