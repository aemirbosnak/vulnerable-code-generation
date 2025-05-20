//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct token {
    char *text;
    int length;
    int score;
} Token;

int tokenize(char *text, Token *tokens) {
    int num_tokens = 0;
    char *p = strtok(text, ",.?!;:");
    while (p!= NULL && num_tokens < MAX_TOKENS) {
        int length = strlen(p);
        if (length > MAX_TOKEN_LEN) {
            length = MAX_TOKEN_LEN;
        }
        Token token = {p, length, 0};
        strcpy(token.text, p);
        tokens[num_tokens++] = token;
        p = strtok(NULL, ",.?!;:");
    }
    return num_tokens;
}

int score_token(Token *token) {
    int score = 0;
    int i = 0;
    while (i < 200 && i < token->length) {
        if (isalpha(token->text[i])) {
            score += token->text[i] - 'a' + 1;
        }
        i++;
    }
    return score;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];
    Token tokens[MAX_TOKENS];
    int num_tokens = tokenize(text, tokens);
    int total_score = 0;
    for (int i = 0; i < num_tokens; i++) {
        int score = score_token(&tokens[i]);
        total_score += score;
        printf("%s (%d)\n", tokens[i].text, score);
    }
    printf("Total score: %d\n", total_score);
    return 0;
}