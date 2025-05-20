//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define TOKEN_COUNT 16

typedef enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LPAREN,
    TOKEN_TYPE_RPAREN,
    TOKEN_TYPE_LBRACKET,
    TOKEN_TYPE_RBRACKET,
    TOKEN_TYPE_SEMICOLON,
    TOKEN_TYPE_COMMA,
    TOKEN_TYPE_DOT,
    TOKEN_TYPE_EOF
} token_type;

typedef struct {
    token_type type;
    char *text;
    int line;
    int column;
} token_t;

static token_t tokens[TOKEN_COUNT];
static int tok_count = 0;

void lex(char *src, int len) {
    int i = 0;
    int line = 1;
    int column = 1;

    while (i < len) {
        char c = src[i];

        if (isspace(c)) {
            continue;
        }

        if (c == '(' || c == '[' || c == '{') {
            tokens[tok_count].type = TOKEN_TYPE_LPAREN;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (c == ')' || c == ']' || c == '}') {
            tokens[tok_count].type = TOKEN_TYPE_RPAREN;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (c == '.') {
            tokens[tok_count].type = TOKEN_TYPE_DOT;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (isdigit(c)) {
            int j = 0;
            int num = 0;
            while (isdigit(src[i + j])) {
                num *= 10;
                num += (src[i + j] - '0');
                j++;
            }
            tokens[tok_count].type = TOKEN_TYPE_NUMBER;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (isalpha(c)) {
            int j = 0;
            char buffer[20];
            do {
                buffer[j] = src[i + j];
                j++;
            } while (isalnum(src[i + j]));
            buffer[j] = 0;
            tokens[tok_count].type = TOKEN_TYPE_IDENTIFIER;
            tokens[tok_count].text = buffer;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (c == ';') {
            tokens[tok_count].type = TOKEN_TYPE_SEMICOLON;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        if (c == ',') {
            tokens[tok_count].type = TOKEN_TYPE_COMMA;
            tokens[tok_count].text = src + i;
            tokens[tok_count].line = line;
            tokens[tok_count].column = column;
            tok_count++;
            continue;
        }

        printf("Unsupported character %c at line %d, column %d\n", c, line, column);
        return;
    }

    tokens[tok_count].type = TOKEN_TYPE_EOF;
    tokens[tok_count].text = src;
    tokens[tok_count].line = line;
    tokens[tok_count].column = column;
    tok_count++;
}

int main() {
    char src[] = "int main() { return 42; }";
    lex(src, strlen(src));
    return 0;
}