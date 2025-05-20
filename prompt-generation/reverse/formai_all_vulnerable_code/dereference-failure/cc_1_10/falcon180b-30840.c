//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *value;
    int length;
} token_t;

void tokenize(char *input, token_t *tokens, int max_tokens) {
    int i = 0;
    char *token = strtok(input, ",\n");

    while (token!= NULL && i < max_tokens) {
        if (strlen(token) > MAX_TOKEN_LENGTH) {
            printf("Error: token too long\n");
            exit(1);
        }

        tokens[i].value = malloc(strlen(token) + 1);
        strcpy(tokens[i].value, token);
        tokens[i].length = strlen(token);

        token = strtok(NULL, ",\n");
        i++;
    }

    if (i == max_tokens) {
        printf("Error: too many tokens\n");
        exit(1);
    }
}

void print_tokens(token_t *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].value, tokens[i].length);
    }
}

int main() {
    char input[1000];
    token_t tokens[MAX_TOKENS];

    printf("Enter a string to tokenize:\n");
    fgets(input, sizeof(input), stdin);

    tokenize(input, tokens, MAX_TOKENS);
    print_tokens(tokens, MAX_TOKENS);

    return 0;
}