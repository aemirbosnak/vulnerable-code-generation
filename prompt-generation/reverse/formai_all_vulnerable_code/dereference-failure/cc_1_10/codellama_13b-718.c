//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: scalable
/*
 * A scalable C syntax parsing example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
    char type;
    char value[100];
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char type, char *value) {
    tokens[num_tokens].type = type;
    strcpy(tokens[num_tokens].value, value);
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%c: %s\n", tokens[i].type, tokens[i].value);
    }
}

int main() {
    char *code = "int x = 5; int y = 10; x = x + y;";
    char *token;
    char *next_token;

    token = strtok(code, " \n\t");
    while (token != NULL) {
        next_token = strtok(NULL, " \n\t");
        if (next_token != NULL) {
            add_token(token[0], next_token);
        } else {
            add_token(token[0], "");
        }
        token = next_token;
    }

    print_tokens();

    return 0;
}