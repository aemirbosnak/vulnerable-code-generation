//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *data;
    int length;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

TokenList *parse_resume(char *input) {
    TokenList *tokens = malloc(sizeof(TokenList));
    tokens->num_tokens = 0;

    char *word_start = input;
    char *word_end = strtok(input, " \n\t\r\f\v");
    while (word_end!= NULL) {
        if (tokens->num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }

        int word_length = strlen(word_end);
        if (word_length > MAX_TOKEN_LENGTH) {
            printf("Error: Token too long\n");
            exit(1);
        }

        Token *token = malloc(sizeof(Token));
        token->data = word_end;
        token->length = word_length;

        tokens->tokens[tokens->num_tokens++] = *token;

        word_start = word_end + 1;
        word_end = strtok(NULL, " \n\t\r\f\v");
    }

    if (tokens->num_tokens == 0) {
        printf("Error: Empty resume\n");
        exit(1);
    }

    return tokens;
}

void print_tokens(TokenList *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        printf("%s ", tokens->tokens[i].data);
    }
    printf("\n");
}

int main() {
    char *input = "John Doe\n123 Main St\nAnytown, USA\n555-1234\n";
    TokenList *tokens = parse_resume(input);
    print_tokens(tokens);

    free(tokens->tokens[0].data);
    free(tokens->tokens[1].data);
    free(tokens->tokens[2].data);
    free(tokens->tokens[3].data);
    free(tokens);

    return 0;
}