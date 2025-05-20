//Falcon-180B DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

struct rule {
    char *pattern;
    char *replacement;
};

struct rule rules[MAX_RULES];
int num_rules;

void add_rule(char *pattern, char *replacement) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Too many rules\n");
        return;
    }
    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].replacement = strdup(replacement);
    num_rules++;
}

void apply_rules(char *input) {
    int i;
    char *output = malloc(strlen(input) + 1);
    strcpy(output, input);
    for (i = 0; i < num_rules; i++) {
        int j;
        char *pos = strstr(output, rules[i].pattern);
        while (pos!= NULL) {
            int len = strlen(rules[i].replacement);
            int k;
            for (k = 0; k < len && isalnum(pos[k]); k++) {
                output[pos - output] = rules[i].replacement[k];
            }
            pos += len;
            while (isspace(pos[0])) {
                pos++;
            }
        }
    }
    printf("%s\n", output);
    free(output);
}

int main() {
    char input[1024];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        apply_rules(input);
    }
    return 0;
}