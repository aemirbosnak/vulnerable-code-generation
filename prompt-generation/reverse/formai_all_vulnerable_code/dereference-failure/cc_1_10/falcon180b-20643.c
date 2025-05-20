//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 50

typedef struct {
    char *name;
    char *value;
} token_t;

token_t *tokens = NULL;
int num_tokens = 0;

void add_token(char *name, char *value) {
    token_t *new_token = (token_t *)malloc(sizeof(token_t));
    new_token->name = strdup(name);
    new_token->value = strdup(value);
    tokens = realloc(tokens, sizeof(token_t) * (num_tokens + 1));
    tokens[num_tokens++] = *new_token;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

void free_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    free(tokens);
    tokens = NULL;
    num_tokens = 0;
}

int main() {
    char line[MAX_LINE_SIZE];
    char *name = NULL;
    char *value = NULL;
    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        char *p = line;
        while (*p!= '\0' && isspace(*p)) {
            p++;
        }
        if (*p == '\0') {
            continue;
        }
        name = p;
        while (*p!= '\0' &&!isspace(*p)) {
            p++;
        }
        if (*p == '\0') {
            printf("Error: Missing value for %s\n", name);
            continue;
        }
        *p = '\0';
        value = p + 1;
        add_token(name, value);
    }
    print_tokens();
    free_tokens();
    return 0;
}