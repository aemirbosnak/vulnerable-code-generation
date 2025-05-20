//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

Token *create_token(char *str, int len) {
    Token *token = (Token *)malloc(sizeof(Token));
    token->token = (char *)malloc(len + 1);
    strcpy(token->token, str);
    token->token_len = len;
    return token;
}

void add_token(TokenList *list, char *str, int len) {
    if (list->num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        exit(1);
    }
    Token *token = create_token(str, len);
    list->tokens[list->num_tokens++] = *token;
}

void print_tokens(TokenList *list) {
    for (int i = 0; i < list->num_tokens; i++) {
        printf("%s ", list->tokens[i].token);
    }
    printf("\n");
}

int main() {
    char input_buf[1000];
    int input_len = 0;
    TokenList token_list = {NULL, 0};

    printf("Enter resume text:\n");
    fgets(input_buf, 1000, stdin);
    input_len = strlen(input_buf);

    char *token_buf = (char *)malloc(MAX_TOKEN_LEN);
    int token_len = 0;

    for (int i = 0; i < input_len; i++) {
        char c = input_buf[i];
        if (isspace(c)) {
            if (token_len > 0) {
                add_token(&token_list, token_buf, token_len);
                token_len = 0;
            }
        } else {
            strncat(token_buf, &c, 1);
            token_len++;
        }
    }

    if (token_len > 0) {
        add_token(&token_list, token_buf, token_len);
    }

    print_tokens(&token_list);

    return 0;
}