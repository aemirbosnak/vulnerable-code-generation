//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 64

typedef struct {
    char *token;
    int freq;
} Token;

void tokenize(char *text, Token *tokens) {
    char *delimiters = " \t\n\r\f\v\a\b\0";
    char *token = strtok(text, delimiters);

    int num_tokens = 0;
    while (token!= NULL && num_tokens < MAX_TOKENS) {
        if (strlen(token) >= MAX_TOKEN_LEN) {
            printf("Error: token too long\n");
            exit(1);
        }
        tokens[num_tokens].token = strdup(token);
        tokens[num_tokens].freq = 1;
        num_tokens++;
        token = strtok(NULL, delimiters);
    }
}

void count_words(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (strcmp(tokens[i].token, tokens[j].token) == 0) {
                tokens[i].freq += tokens[j].freq;
                tokens[j].freq = 0;
            }
        }
    }
}

void print_tokens(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        if (tokens[i].freq > 0) {
            printf("%s: %d\n", tokens[i].token, tokens[i].freq);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }

    char *text = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&text, &len, fp))!= -1) {
        text[read - 1] = '\0';
        Token tokens[MAX_TOKENS];
        tokenize(text, tokens);
        count_words(tokens, read - 1);
        print_tokens(tokens, read - 1);
    }

    free(text);
    fclose(fp);

    return 0;
}