//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 100

typedef struct {
    char *token;
    int token_size;
} Token;

Token *tokens = NULL;
int num_tokens = 0;

void add_token(char *token, int token_size) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum tokens reached.\n");
        exit(1);
    }

    Token *new_token = malloc(sizeof(Token));
    if (new_token == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    new_token->token = malloc(token_size + 1);
    if (new_token->token == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    strncpy(new_token->token, token, token_size);
    new_token->token[token_size] = '\0';
    new_token->token_size = token_size;

    tokens[num_tokens++] = *new_token;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].token);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_TOKEN_SIZE];
    while (fgets(line, MAX_TOKEN_SIZE, fp)!= NULL) {
        int line_size = strlen(line);

        char *cursor = line;
        while (*cursor!= '\0') {
            if (isspace(*cursor)) {
                *cursor = '\0';
                add_token(line, line_size);
                line_size = 0;
            } else {
                cursor++;
            }
        }

        if (line_size > 0) {
            add_token(line, line_size);
        }
    }

    fclose(fp);

    print_tokens();

    return 0;
}