//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

void parse_line(char *line, Token tokens[], int *token_count) {
    char *token = strtok(line, " \t\n\r\f\v\"");
    while (token!= NULL) {
        if (*token_count >= MAX_TOKENS) {
            printf("Error: Too many tokens in line.\n");
            exit(1);
        }
        tokens[*token_count] = (Token) {.name = strdup(token),.value = NULL };
        (*token_count)++;
        token = strtok(NULL, " \t\n\r\f\v\"");
    }
}

void print_tokens(Token tokens[], int token_count) {
    for (int i = 0; i < token_count; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    char input_file[MAX_LINE_LENGTH];
    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    Token tokens[MAX_TOKENS];
    int token_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_number++;
        parse_line(line, tokens, &token_count);
    }

    fclose(fp);

    printf("Line %d:\n", line_number);
    print_tokens(tokens, token_count);

    return 0;
}