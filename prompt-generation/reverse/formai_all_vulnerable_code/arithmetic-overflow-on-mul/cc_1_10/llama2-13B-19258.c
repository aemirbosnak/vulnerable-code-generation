//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024
#define TOKEN_COUNT 10

typedef enum {
    TOKEN_TYPE_INT,
    TOKEN_TYPE_DOUBLE,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LEFT_PAREN,
    TOKEN_TYPE_RIGHT_PAREN,
    TOKEN_TYPE_LEFT_BRACE,
    TOKEN_TYPE_RIGHT_BRACE,
    TOKEN_TYPE_EOF
} TokenType;

typedef struct {
    TokenType type;
    int line;
    int col;
    union {
        int iValue;
        double dValue;
        char *sValue;
    } value;
} Token;

void lexer(const char *src, Token *tokens, int *tokenCount) {
    int i = 0;
    int len = strlen(src);
    int line = 1;
    int col = 1;

    while (i < len) {
        char c = src[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (c == '{') {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_LEFT_BRACE,
                .line = line,
                .col = col,
            };
            line++;
            col = 1;
        } else if (c == '}') {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_RIGHT_BRACE,
                .line = line,
                .col = col,
            };
            line--;
            col = strcspn(src + i, " \t\r\n") + 1;
        } else if (c == '(') {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_LEFT_PAREN,
                .line = line,
                .col = col,
            };
            line++;
            col = 1;
        } else if (c == ')') {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_RIGHT_PAREN,
                .line = line,
                .col = col,
            };
            line--;
            col = strcspn(src + i, " \t\r\n") + 1;
        } else if (c == '-' || c == '+') {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_OPERATOR,
                .line = line,
                .col = col,
                .value.iValue = 0,
            };
            line++;
            col = 1;
        } else if (isdigit(c)) {
            int j = 0;
            int value = 0;

            while (isdigit(c) && j < MAX_LENGTH) {
                value *= 10;
                value += (c - '0');
                j++;
                i++;
            }

            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_INT,
                .line = line,
                .col = col,
                .value.iValue = value,
            };
            line++;
            col = j;
        } else if (iscntrl(c)) {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_KEYWORD,
                .line = line,
                .col = col,
                .value.sValue = src + i,
            };
            line++;
            col = strcspn(src + i, " \t\r\n") + 1;
        } else {
            tokens[(*tokenCount)++] = (Token) {
                .type = TOKEN_TYPE_STRING,
                .line = line,
                .col = col,
                .value.sValue = src + i,
            };
            line++;
            col = strcspn(src + i, " \t\r\n") + 1;
        }

        i++;
    }
}

int main() {
    const char src[] = "int x = 42; double y = 3.14;";
    Token tokens[TOKEN_COUNT];
    int tokenCount = 0;

    lexer(src, tokens, &tokenCount);

    for (int i = 0; i < tokenCount; i++) {
        printf("Token %d: %s (%d, %d)\n", i, tokens[i].value.sValue, tokens[i].line, tokens[i].col);
    }

    return 0;
}