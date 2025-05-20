//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *string;
    int length;
} Token;

void tokenize(char *string, Token *tokens) {
    int i = 0;
    char *token = strtok(string, " ");

    while (token!= NULL) {
        if (i >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }

        tokens[i].string = malloc(MAX_TOKEN_LEN);
        strncpy(tokens[i].string, token, MAX_TOKEN_LEN - 1);
        tokens[i].string[MAX_TOKEN_LEN - 1] = '\0';
        tokens[i].length = strlen(token);

        i++;
        token = strtok(NULL, " ");
    }
}

void reverse_tokens(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens / 2; i++) {
        Token temp = tokens[i];
        tokens[i] = tokens[num_tokens - i - 1];
        tokens[num_tokens - i - 1] = temp;
    }
}

void capitalize_tokens(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        if (isalpha(tokens[i].string[0])) {
            tokens[i].string[0] = toupper(tokens[i].string[0]);
        }
    }
}

int main() {
    char input[1000];
    Token tokens[MAX_TOKENS];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    tokenize(input, tokens);

    reverse_tokens(tokens, strlen(input));

    capitalize_tokens(tokens, strlen(input));

    printf("Reversed and capitalized tokens:\n");
    for (int i = 0; i < strlen(input); i++) {
        printf("%s ", tokens[i].string);
    }

    return 0;
}