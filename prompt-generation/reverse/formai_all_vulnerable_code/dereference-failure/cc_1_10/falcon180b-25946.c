//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int count;
} Token;

void tokenize(char *message, Token *tokens, int num_tokens) {
    char *ptr = strtok(message, " \t\n\r");
    int i = 0;

    while (ptr!= NULL && i < num_tokens) {
        tokens[i].token = strdup(ptr);
        tokens[i].count = 1;
        i++;
        ptr = strtok(NULL, " \t\n\r");
    }
}

int is_spam(Token *tokens, int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[1024];
    Token tokens[MAX_TOKENS];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    tokenize(message, tokens, MAX_TOKENS);

    int num_tokens = 0;
    while (tokens[num_tokens].token!= NULL) {
        num_tokens++;
    }

    if (is_spam(tokens, num_tokens)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}