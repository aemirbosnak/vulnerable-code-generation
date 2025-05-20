//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *token;
    int token_len;
    int line_num;
} Token;

void read_file(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    int line_num = 1;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        printf("Line %d: %s", line_num, line);
        line_num++;
    }
}

void tokenize_line(char *line, Token *tokens, int *num_tokens) {
    char *token = strtok(line, " \t\n\r\f\v");
    int i = 0;

    while (token!= NULL && i < MAX_TOKENS - 1) {
        if (strlen(token) > 0) {
            tokens[i].token = token;
            tokens[i].token_len = strlen(token);
            tokens[i].line_num = 1;
            i++;
        }

        token = strtok(NULL, " \t\n\r\f\v");
    }

    *num_tokens = i;
}

void print_tokens(Token *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i].token);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[MAX_LINE_LEN];
    char line[MAX_LINE_LEN];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(fp, filename);

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        tokenize_line(line, tokens, &num_tokens);
        print_tokens(tokens, num_tokens);
    }

    fclose(fp);
    return 0;
}