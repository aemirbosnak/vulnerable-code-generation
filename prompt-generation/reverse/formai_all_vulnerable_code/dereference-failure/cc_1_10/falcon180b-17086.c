//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 10000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int count;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

void tokenize(char *text, TokenList *tokens) {
    char *word = strtok(text, " \t\r\n\f\v,.?!;:");
    while (word!= NULL) {
        Token *token = malloc(sizeof(Token));
        token->token = strdup(word);
        token->count = 1;
        if (tokens->num_tokens >= MAX_TOKENS) {
            printf("Error: maximum number of tokens reached.\n");
            exit(1);
        }
        tokens->tokens[tokens->num_tokens] = *token;
        tokens->num_tokens++;
        word = strtok(NULL, " \t\r\n\f\v,.?!;:");
    }
}

int compare_tokens(const void *a, const void *b) {
    Token *token1 = *(Token **)a;
    Token *token2 = *(Token **)b;
    return strcmp(token1->token, token2->token);
}

void count_tokens(TokenList *tokens) {
    qsort(tokens->tokens, tokens->num_tokens, sizeof(Token), compare_tokens);
    int i;
    for (i = 0; i < tokens->num_tokens; i++) {
        tokens->tokens[i].count = 1;
        while (i < tokens->num_tokens - 1 && strcmp(tokens->tokens[i].token, tokens->tokens[i + 1].token) == 0) {
            tokens->tokens[i].count++;
            i++;
        }
    }
}

int is_spam(TokenList *tokens) {
    int i, total_tokens = 0, spam_tokens = 0;
    for (i = 0; i < tokens->num_tokens; i++) {
        total_tokens += tokens->tokens[i].count;
        if (tokens->tokens[i].count >= 2) {
            spam_tokens++;
        }
    }
    return ((float)spam_tokens / total_tokens) >= 0.1;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];
    TokenList tokens;
    tokens.tokens = malloc(MAX_TOKENS * sizeof(Token));
    tokens.num_tokens = 0;
    tokenize(text, &tokens);
    count_tokens(&tokens);
    if (is_spam(&tokens)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }
    free(tokens.tokens);
    return 0;
}