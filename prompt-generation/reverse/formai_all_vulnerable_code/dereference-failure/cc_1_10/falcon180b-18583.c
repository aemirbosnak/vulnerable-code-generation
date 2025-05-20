//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *value;
    int is_keyword;
} token_t;

typedef struct {
    token_t *tokens;
    int num_tokens;
} token_list_t;

void tokenize(char *input, token_list_t *tokens) {
    char *line = strdup(input);
    char *token = strtok(line, " \n\t\r");
    int num_tokens = 0;

    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }

        token_t *new_token = (token_t *) malloc(sizeof(token_t));
        new_token->value = strdup(token);
        new_token->is_keyword = is_keyword(token);

        tokens->tokens[num_tokens] = *new_token;
        num_tokens++;

        token = strtok(NULL, " \n\t\r");
    }

    tokens->num_tokens = num_tokens;
}

int is_keyword(char *token) {
    if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0 || strcmp(token, "while") == 0 || strcmp(token, "for") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void generate_code(token_list_t *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        token_t *token = &tokens->tokens[i];

        if (token->is_keyword) {
            printf("%s ", token->value);
        } else {
            printf("\"%s\" ", token->value);
        }
    }
}

int main() {
    char input[MAX_TOKEN_LENGTH];
    token_list_t tokens;

    printf("Enter C code:\n");
    fgets(input, MAX_TOKEN_LENGTH, stdin);

    tokenize(input, &tokens);
    generate_code(&tokens);

    return 0;
}