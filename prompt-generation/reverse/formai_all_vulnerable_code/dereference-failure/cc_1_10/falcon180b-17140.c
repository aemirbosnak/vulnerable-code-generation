//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t *tokens = NULL;
int num_tokens = 0;

void add_token(char *name, char *value) {
    token_t *new_token = malloc(sizeof(token_t));
    new_token->name = strdup(name);
    new_token->value = strdup(value);
    tokens = realloc(tokens, sizeof(token_t) * ++num_tokens);
    tokens[num_tokens - 1] = *new_token;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    char line[MAX_LINE_LEN];
    char *token_name, *token_value;

    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        token_name = strtok(line, ":");
        token_value = strtok(NULL, "\n");
        if (token_name == NULL || token_value == NULL) {
            printf("Error: Invalid line format\n");
            continue;
        }
        add_token(token_name, token_value);
    }

    print_tokens();

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    free(tokens);
    return 0;
}