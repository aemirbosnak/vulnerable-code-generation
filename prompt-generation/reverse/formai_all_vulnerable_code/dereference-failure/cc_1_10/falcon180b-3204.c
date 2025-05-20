//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_TOKENS 50
#define MAX_TOKEN_SIZE 64

typedef struct {
    char *token;
    int token_size;
    int line_number;
} Token;

Token *tokens;
int num_tokens;
char *line;
int line_number;

void init() {
    tokens = (Token *) malloc(MAX_TOKENS * sizeof(Token));
    num_tokens = 0;
    line = (char *) malloc(MAX_LINE_SIZE);
    line_number = 0;
}

void add_token(char *token, int size, int line_num) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    Token *new_token = (Token *) malloc(sizeof(Token));
    new_token->token = (char *) malloc(size * sizeof(char));
    strcpy(new_token->token, token);
    new_token->token_size = size;
    new_token->line_number = line_num;
    tokens[num_tokens++] = *new_token;
}

void parse_line(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        add_token(token, strlen(token), line_number);
        token = strtok(NULL, " ");
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %s\n", tokens[i].line_number, tokens[i].token);
    }
}

int main() {
    init();
    FILE *fp;
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        parse_line(line);
        line_number++;
    }
    fclose(fp);
    print_tokens();
    return 0;
}