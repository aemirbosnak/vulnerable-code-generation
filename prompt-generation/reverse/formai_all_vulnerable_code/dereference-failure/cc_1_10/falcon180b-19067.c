//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int length;
    int line_num;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *token, int length, int line_num) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].token = malloc(length + 1);
    strncpy(tokens[num_tokens].token, token, length);
    tokens[num_tokens].length = length;
    tokens[num_tokens].line_num = line_num;
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %.*s\n", tokens[i].line_num, tokens[i].length, tokens[i].token);
    }
}

char *read_line(FILE *fp) {
    char ch;
    int len = 0;
    char *line = malloc(MAX_TOKEN_LEN);
    while ((ch = fgetc(fp))!= EOF && ch!= '\n') {
        if (len >= MAX_TOKEN_LEN - 2) {
            printf("Error: Line too long\n");
            exit(1);
        }
        line[len++] = ch;
    }
    line[len] = '\0';
    return line;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    int line_num = 1;
    char *line;
    while ((line = read_line(fp))!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                add_token(line, i + 1, line_num);
                i += strlen(line) - 1;
            }
        }
        line_num++;
    }
    fclose(fp);
    print_tokens();
    return 0;
}