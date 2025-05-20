//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *token;
    int length;
} Token;

void tokenize(char *input, Token *tokens) {
    int i = 0;
    char *current_token = input;
    while (i < MAX_TOKENS - 1) {
        while (isspace(*current_token)) {
            current_token++;
        }
        if (*current_token == '\0') {
            break;
        }
        Token token;
        token.token = current_token;
        int j = 0;
        while (!isspace(*current_token) && j < MAX_TOKEN_LENGTH - 1) {
            token.length++;
            current_token++;
            j++;
        }
        token.token[token.length] = '\0';
        tokens[i++] = token;
        while (isspace(*current_token)) {
            current_token++;
        }
    }
    tokens[i].token = NULL;
    tokens[i].length = 0;
}

int is_number(char *token) {
    int i = 0;
    while (token[i]!= '\0') {
        if (!isdigit(token[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char *input = "John Doe\n123 Main St.\nAnytown, USA 12345\n(123) 456-7890\n";
    Token tokens[MAX_TOKENS];
    tokenize(input, tokens);
    for (int i = 0; tokens[i].token!= NULL; i++) {
        if (is_number(tokens[i].token)) {
            printf("%s\n", tokens[i].token);
        }
    }
    return 0;
}