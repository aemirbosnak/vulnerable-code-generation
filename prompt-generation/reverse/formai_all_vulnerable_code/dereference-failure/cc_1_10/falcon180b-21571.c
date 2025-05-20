//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *name;
    char *value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached\n");
        exit(1);
    }

    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);

    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token_name = NULL;
    char *token_value = NULL;
    char *saveptr = NULL;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token_name = strtok_r(line, ":", &saveptr);
        if (token_name == NULL) {
            printf("Error: Invalid line format\n");
            continue;
        }

        token_value = strtok_r(NULL, "\n", &saveptr);
        if (token_value == NULL) {
            printf("Error: Invalid line format\n");
            continue;
        }

        add_token(token_name, token_value);
    }

    print_tokens();

    return 0;
}