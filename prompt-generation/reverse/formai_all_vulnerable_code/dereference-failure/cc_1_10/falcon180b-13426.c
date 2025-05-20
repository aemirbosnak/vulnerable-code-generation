//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *token;
    int token_len;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

void init_token_list(TokenList *list) {
    list->tokens = (Token *)malloc(MAX_TOKENS * sizeof(Token));
    list->num_tokens = 0;
}

void destroy_token_list(TokenList *list) {
    for (int i = 0; i < list->num_tokens; i++) {
        free(list->tokens[i].token);
    }
    free(list->tokens);
}

void add_token(TokenList *list, char *token, int token_len) {
    if (list->num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        return;
    }
    list->tokens[list->num_tokens].token = (char *)malloc(token_len + 1);
    strncpy(list->tokens[list->num_tokens].token, token, token_len);
    list->tokens[list->num_tokens].token_len = token_len;
    list->num_tokens++;
}

int main() {
    FILE *fp;
    char line[MAX_TOKEN_LEN + 1];
    char *token;
    int token_len;
    TokenList token_list;

    init_token_list(&token_list);

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            token_len = strlen(token);
            add_token(&token_list, token, token_len);
            token = strtok(NULL, " \t\r\n");
        }
    }

    fclose(fp);

    printf("Resume Parsing Results:\n");
    for (int i = 0; i < token_list.num_tokens; i++) {
        printf("%s (%d chars)\n", token_list.tokens[i].token, token_list.tokens[i].token_len);
    }

    destroy_token_list(&token_list);

    return 0;
}