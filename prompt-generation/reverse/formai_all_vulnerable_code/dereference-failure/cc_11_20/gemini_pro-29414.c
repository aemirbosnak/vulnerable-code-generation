//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: calm
// A serene journey through C syntax parsing

// Let's begin with some tranquility, shall we?
#include <stdio.h>
#include <stdlib.h>

// Our guide through the syntactical realm: a custom lexer
typedef struct Token {
    char* text;
    int type;
} Token;

// The types of tokens we encounter along the way
enum TokenType {
    TOKEN_EOF,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD
};

// A gentle breeze to tokenize our input
Token* tokenize(char* input) {
    Token* tokens = malloc(sizeof(Token) * 100);
    int tokenCount = 0;
    char* current = input;

    while (*current != '\0') {
        // Skip whitespace
        while (*current == ' ' || *current == '\n' || *current == '\t') {
            current++;
        }

        // Identify integers
        if (*current >= '0' && *current <= '9') {
            char* start = current;
            while (*current >= '0' && *current <= '9') {
                current++;
            }
            char* end = current;

            tokens[tokenCount].text = malloc(end - start + 1);
            memcpy(tokens[tokenCount].text, start, end - start);
            tokens[tokenCount].text[end - start] = '\0';
            tokens[tokenCount].type = TOKEN_INT;
            tokenCount++;
        }

        // Identify floats
        else if (*current == '.') {
            char* start = current;
            current++;
            while (*current >= '0' && *current <= '9') {
                current++;
            }
            char* end = current;

            tokens[tokenCount].text = malloc(end - start + 1);
            memcpy(tokens[tokenCount].text, start, end - start);
            tokens[tokenCount].text[end - start] = '\0';
            tokens[tokenCount].type = TOKEN_FLOAT;
            tokenCount++;
        }

        // Identify strings
        else if (*current == '\"') {
            char* start = current + 1;
            while (*current != '\"') {
                current++;
            }
            char* end = current;

            tokens[tokenCount].text = malloc(end - start + 1);
            memcpy(tokens[tokenCount].text, start, end - start);
            tokens[tokenCount].text[end - start] = '\0';
            tokens[tokenCount].type = TOKEN_STRING;
            tokenCount++;
        }

        // Identify identifiers
        else if (*current >= 'a' && *current <= 'z') {
            char* start = current;
            while (*current >= 'a' && *current <= 'z') {
                current++;
            }
            char* end = current;

            tokens[tokenCount].text = malloc(end - start + 1);
            memcpy(tokens[tokenCount].text, start, end - start);
            tokens[tokenCount].text[end - start] = '\0';
            tokens[tokenCount].type = TOKEN_IDENTIFIER;
            tokenCount++;
        }

        // Identify operators
        else if (*current == '+' || *current == '-' || *current == '*' || *current == '/' || *current == '%') {
            tokens[tokenCount].text = malloc(2);
            tokens[tokenCount].text[0] = *current;
            tokens[tokenCount].text[1] = '\0';
            tokens[tokenCount].type = TOKEN_OPERATOR;
            tokenCount++;
            current++;
        }

        // Identify keywords
        else if (*current == 'i' && *(current + 1) == 'f') {
            tokens[tokenCount].text = malloc(3);
            memcpy(tokens[tokenCount].text, "if", 3);
            tokens[tokenCount].text[3] = '\0';
            tokens[tokenCount].type = TOKEN_KEYWORD;
            tokenCount++;
            current += 2;
        }

        // Identify end of file
        else if (*current == '\0') {
            tokens[tokenCount].text = malloc(3);
            memcpy(tokens[tokenCount].text, "EOF", 3);
            tokens[tokenCount].text[3] = '\0';
            tokens[tokenCount].type = TOKEN_EOF;
            tokenCount++;
            break;
        }

        // Unrecognized character
        else {
            printf("Error: Unrecognized character '%c'\n", *current);
            free(tokens);
            return NULL;
        }
    }

    // Mark the end of the token stream
    tokens[tokenCount].type = TOKEN_EOF;

    return tokens;
}

// A tranquil meditation on the parsed tokens
void parse(Token* tokens) {
    int i = 0;
    while (tokens[i].type != TOKEN_EOF) {
        switch (tokens[i].type) {
            case TOKEN_INT:
                printf("Integer: %s\n", tokens[i].text);
                break;
            case TOKEN_FLOAT:
                printf("Float: %s\n", tokens[i].text);
                break;
            case TOKEN_STRING:
                printf("String: %s\n", tokens[i].text);
                break;
            case TOKEN_IDENTIFIER:
                printf("Identifier: %s\n", tokens[i].text);
                break;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", tokens[i].text);
                break;
            case TOKEN_KEYWORD:
                printf("Keyword: %s\n", tokens[i].text);
                break;
            default:
                printf("Error: Unknown token type\n");
                break;
        }
        i++;
    }
}

// A serene invocation of our parsing journey
int main() {
    char* input = "123 45.6 \"hello world\" if";
    Token* tokens = tokenize(input);
    parse(tokens);

    // Release the tokens, free from our parsing reverie
    free(tokens);

    return 0;
}