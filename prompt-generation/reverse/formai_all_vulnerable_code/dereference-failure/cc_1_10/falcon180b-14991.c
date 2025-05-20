//Falcon-180B DATASET v1.0 Category: Firewall ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RULES 100
#define MAX_RULE_LENGTH 64

typedef struct {
    char *keyword;
    int action;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

int add_rule(char *keyword, int action) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return -1;
    }

    strcpy(rules[num_rules].keyword, keyword);
    rules[num_rules].action = action;
    num_rules++;

    return 0;
}

int match_rule(char *line, int line_length) {
    int i;
    for (i = 0; i < num_rules; i++) {
        int j;
        for (j = 0; j < line_length && j < MAX_RULE_LENGTH; j++) {
            if (tolower(line[j])!= tolower(rules[i].keyword[j])) {
                break;
            }
        }
        if (j == MAX_RULE_LENGTH) {
            return rules[i].action;
        }
    }

    return 0;
}

void process_line(char *line, int line_length) {
    int action = match_rule(line, line_length);

    if (action == 0) {
        printf("Allow: %s\n", line);
    } else if (action == 1) {
        printf("Deny: %s\n", line);
    } else {
        printf("Error: Invalid rule.\n");
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_length;

    add_rule("hello", 0);
    add_rule("world", 1);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }

        process_line(line, line_length);
    }

    return 0;
}