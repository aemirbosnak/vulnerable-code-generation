//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000
#define MAX_IDENTIFIER_LENGTH 100

enum token_type {
    TOKEN_INVALID = 0,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_SEPARATOR,
    TOKEN_EOF
};

struct token {
    enum token_type type;
    char *value;
};

struct token *tokens[MAX_TOKENS];
int num_tokens;

enum token_type get_token_type(char *str) {
    if (strcmp(str, "int") == 0) {
        return TOKEN_KEYWORD;
    } else if (isalpha(str[0])) {
        return TOKEN_IDENTIFIER;
    } else if (isdigit(str[0])) {
        return TOKEN_NUMBER;
    } else if (str[0] == '\"') {
        return TOKEN_STRING;
    } else {
        return TOKEN_OPERATOR;
    }
}

void add_token(enum token_type type, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens] = malloc(sizeof(struct token));
    tokens[num_tokens]->type = type;
    tokens[num_tokens]->value = strdup(value);
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]->value);
    }
    printf("\n");
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *ptr;
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        ptr = line;
        while (*ptr!= '\0') {
            char *word = strtok(ptr, " \t\n\r\f\v");
            if (word == NULL) {
                break;
            }
            add_token(get_token_type(word), word);
            ptr = NULL;
        }
        if (num_tokens == 0) {
            printf("Error: Empty line %d\n", line_num);
        }
        line_num++;
    }
    print_tokens();
    return 0;
}