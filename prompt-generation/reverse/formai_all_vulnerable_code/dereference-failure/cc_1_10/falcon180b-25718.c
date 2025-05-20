//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *token;
    int value;
} token_t;

int num_tokens = 0;
token_t tokens[MAX_TOKENS];

void add_token(char *token, int value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    tokens[num_tokens].token = strdup(token);
    tokens[num_tokens].value = value;
    num_tokens++;
}

void parse_token(char *token) {
    if (strlen(token) > MAX_TOKEN_LENGTH) {
        printf("Error: Token is too long.\n");
        exit(1);
    }
    add_token(token, 0);
}

void parse_number(char *token) {
    add_token(token, atoi(token));
}

int main() {
    char line[1000];
    char *word;
    int i;

    printf("Enter a program:\n");
    fgets(line, sizeof(line), stdin);

    word = strtok(line, " ");
    while (word!= NULL) {
        if (isdigit(word[0])) {
            parse_number(word);
        } else {
            parse_token(word);
        }
        word = strtok(NULL, " ");
    }

    printf("Number of tokens: %d\n", num_tokens);
    for (i = 0; i < num_tokens; i++) {
        printf("%s = %d\n", tokens[i].token, tokens[i].value);
    }

    return 0;
}