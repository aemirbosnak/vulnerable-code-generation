//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *text;
    int length;
} Token;

int token_count = 0;

Token tokens[MAX_TOKENS];

void add_token(char *text, int length) {
    if (token_count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[token_count].text = malloc(length + 1);
    strncpy(tokens[token_count].text, text, length);
    tokens[token_count].length = length;
    token_count++;
}

void print_tokens() {
    int i;
    for (i = 0; i < token_count; i++) {
        printf("%d: %.*s\n", i, tokens[i].length, tokens[i].text);
    }
}

int main() {
    char input_text[MAX_TOKEN_LENGTH];
    while (1) {
        printf("Enter input text: ");
        fgets(input_text, MAX_TOKEN_LENGTH, stdin);
        int input_length = strlen(input_text);
        if (input_text[input_length - 1] == '\n') {
            input_text[--input_length] = '\0';
        }
        char *token_text = strtok(input_text, " ");
        while (token_text!= NULL) {
            int token_length = strlen(token_text);
            add_token(token_text, token_length);
            token_text = strtok(NULL, " ");
        }
        if (token_count == 0) {
            printf("Error: No tokens found\n");
            exit(1);
        }
        break;
    }
    print_tokens();
    return 0;
}