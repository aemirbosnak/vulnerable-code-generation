//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TOKEN_ERROR,
    TOKEN_EOF,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER
} token_type;

typedef struct {
    token_type type;
    char *text;
} token;

token get_token(char *input) {
    static char *current = NULL;
    if (current == NULL) {
        current = input;
    }

    token result;
    result.type = TOKEN_ERROR;
    result.text = NULL;

    if (*current == '\0') {
        result.type = TOKEN_EOF;
        return result;
    }

    while (*current == ' ') {
        current++;
    }

    if (*current >= '0' && *current <= '9') {
        result.type = TOKEN_NUMBER;
        result.text = current;
        while (*current >= '0' && *current <= '9') {
            current++;
        }
        *current = '\0';
        return result;
    }

    if (*current == '+' || *current == '-' || *current == '*' || *current == '/') {
        result.type = TOKEN_OPERATOR;
        result.text = current;
        current++;
        *current = '\0';
        return result;
    }

    if (*current >= 'a' && *current <= 'z') {
        result.type = TOKEN_IDENTIFIER;
        result.text = current;
        while (*current >= 'a' && *current <= 'z') {
            current++;
        }
        *current = '\0';
        return result;
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    token token;
    do {
        token = get_token(input);
        switch (token.type) {
            case TOKEN_ERROR:
                printf("Error: Invalid token '%s'\n", token.text);
                return 1;
            case TOKEN_EOF:
                printf("End of input\n");
                break;
            case TOKEN_NUMBER:
                printf("Number: %s\n", token.text);
                break;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", token.text);
                break;
            case TOKEN_IDENTIFIER:
                printf("Identifier: %s\n", token.text);
                break;
        }
        input = token.text + strlen(token.text);
    } while (token.type != TOKEN_EOF);

    return 0;
}