//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *word;
    int count;
} Token;

void tokenize(char *text, Token *tokens) {
    char *p = strtok(text, ",.?!;:");
    int i = 0;
    while (p!= NULL) {
        if (i >= MAX_TOKENS) {
            printf("Too many tokens!\n");
            exit(1);
        }
        tokens[i].word = p;
        tokens[i].count = 1;
        i++;
        p = strtok(NULL, ",.?!;:");
    }
}

void classify(Token *tokens, int num_tokens) {
    int i, j;
    for (i = 0; i < num_tokens - 1; i++) {
        for (j = i + 1; j < num_tokens; j++) {
            if (strcmp(tokens[i].word, tokens[j].word) == 0) {
                tokens[i].count++;
                tokens[j].count = 0;
            }
        }
    }
}

void print_tokens(Token *tokens, int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 0) {
            printf("%s: %d\n", tokens[i].word, tokens[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }
    Token tokens[MAX_TOKENS];
    tokenize(argv[1], tokens);
    classify(tokens, argc - 1);
    print_tokens(tokens, argc - 1);
    return 0;
}