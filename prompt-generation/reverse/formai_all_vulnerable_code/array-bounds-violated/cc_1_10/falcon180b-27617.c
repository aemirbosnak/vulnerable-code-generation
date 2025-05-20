//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char* token;
    int len;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char* str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached.\n");
        exit(1);
    }
    tokens[num_tokens++] = (Token) {.token = str,.len = len };
}

int is_operator(char* token) {
    if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
        return 1;
    }
    return 0;
}

int is_keyword(char* token) {
    if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0 || strcmp(token, "while") == 0 || strcmp(token, "for") == 0 || strcmp(token, "return") == 0) {
        return 1;
    }
    return 0;
}

int is_identifier(char* token) {
    if (isalpha(token[0])) {
        for (int i = 1; i < strlen(token); i++) {
            if (!isalnum(token[i])) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int is_integer(char* token) {
    for (int i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i])) {
            return 0;
        }
    }
    return 1;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].len);
    }
}

int main() {
    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, stdin)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        char* token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            add_token(token, strlen(token));
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }
    print_tokens();
    return 0;
}