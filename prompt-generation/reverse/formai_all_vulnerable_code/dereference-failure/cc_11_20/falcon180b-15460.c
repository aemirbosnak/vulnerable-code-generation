//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 1000

typedef struct {
    char *keyword;
    char *value;
    int action;
} rule_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <rules_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open rules file.\n");
        exit(1);
    }

    rule_t rules[MAX_RULES];
    int num_rules = 0;

    char line[MAX_RULE_LENGTH];
    while (fgets(line, MAX_RULE_LENGTH, fp)!= NULL) {
        char *keyword = strtok(line, " ");
        char *value = strtok(NULL, " ");
        int action = atoi(strtok(NULL, " "));

        if (num_rules >= MAX_RULES) {
            printf("Error: Maximum number of rules exceeded.\n");
            exit(1);
        }

        rules[num_rules].keyword = strdup(keyword);
        rules[num_rules].value = strdup(value);
        rules[num_rules].action = action;

        num_rules++;
    }

    fclose(fp);

    char *input = NULL;
    size_t input_size = 0;
    while ((input_size = getline(&input, &input_size, stdin)) > 0) {
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_rules; i++) {
                if (strcasecmp(token, rules[i].keyword) == 0) {
                    if (rules[i].action == 1) {
                        printf("Blocked keyword: %s\n", token);
                        exit(1);
                    } else {
                        printf("Allowed keyword: %s\n", token);
                    }
                    break;
                }
            }
            if (i == num_rules) {
                printf("Unknown keyword: %s\n", token);
                exit(1);
            }
            token = strtok(NULL, " ");
        }
    }

    free(input);
    return 0;
}