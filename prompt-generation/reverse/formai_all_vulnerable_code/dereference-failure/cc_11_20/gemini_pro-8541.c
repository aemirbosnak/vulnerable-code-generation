//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
#define TOKEN_EOF -1
#define TOKEN_IDENTIFIER 0
#define TOKEN_NUMBER 1
#define TOKEN_STRING 2
#define TOKEN_KEYWORD 3
#define TOKEN_SYMBOL 4
#define TOKEN_ERROR 5

// Keywords
static char *keywords[] = {"int", "float", "double", "char", "void", "return"};

// Symbols
static char *symbols[] = {"+", "-", "*", "/", "%", "=", "==", "!=", "<", "<=", ">", ">=", "&&", "||", "!", "(", ")", "{", "}", "[", "]", ";", ","};

// Token structure
typedef struct {
    int type;
    char *value;
} Token;

// Lexer function
static Token *lexer(char *input) {
    int i, j, k;
    Token *tokens;
    char *token;

    // Allocate memory for tokens
    tokens = malloc(sizeof(Token) * 100);

    // Initialize tokens
    for (i = 0; i < 100; i++) {
        tokens[i].type = TOKEN_EOF;
        tokens[i].value = NULL;
    }

    // Tokenize the input
    i = 0;
    j = 0;
    while (input[i] != '\0') {
        // Skip whitespace
        while (isspace(input[i])) {
            i++;
        }

        // Check for end of file
        if (input[i] == '\0') {
            break;
        }

        // Check for identifier
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                j++;
                i++;
            }
            i--;
            token = malloc(j + 1);
            strncpy(token, input + i - j, j);
            token[j] = '\0';

            // Check for keyword
            for (k = 0; k < 6; k++) {
                if (strcmp(token, keywords[k]) == 0) {
                    tokens[j].type = TOKEN_KEYWORD;
                    break;
                }
            }

            // Check for identifier
            if (tokens[j].type == TOKEN_EOF) {
                tokens[j].type = TOKEN_IDENTIFIER;
            }

            tokens[j].value = token;
            j++;
        }

        // Check for number
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                j++;
                i++;
            }
            if (input[i] == '.') {
                j++;
                i++;
                while (isdigit(input[i])) {
                    j++;
                    i++;
                }
            }
            i--;
            token = malloc(j + 1);
            strncpy(token, input + i - j, j);
            token[j] = '\0';
            tokens[j].type = TOKEN_NUMBER;
            tokens[j].value = token;
            j++;
        }

        // Check for string
        else if (input[i] == '"') {
            j = 0;
            i++;
            while (input[i] != '"' && input[i] != '\0') {
                j++;
                i++;
            }
            if (input[i] == '\0') {
                printf("Error: Unterminated string\n");
                exit(1);
            }
            token = malloc(j + 1);
            strncpy(token, input + i - j, j);
            token[j] = '\0';
            tokens[j].type = TOKEN_STRING;
            tokens[j].value = token;
            j++;
            i++;
        }

        // Check for symbol
        else if (input[i] == '`') {
            j = 0;
            i++;
            while (input[i] != '`' && input[i] != '\0') {
                j++;
                i++;
            }
            if (input[i] == '\0') {
                printf("Error: Unterminated symbol\n");
                exit(1);
            }
            token = malloc(j + 1);
            strncpy(token, input + i - j, j);
            token[j] = '\0';
            tokens[j].type = TOKEN_SYMBOL;
            tokens[j].value = token;
            j++;
            i++;
        }

        // Check for error
        else {
            printf("Error: Invalid character '%c'\n", input[i]);
            exit(1);
        }

        i++;
    }

    // Return tokens
    return tokens;
}

// Parser function
static void parser(Token *tokens) {
    int i;

    // Parse the tokens
    i = 0;
    while (tokens[i].type != TOKEN_EOF) {
        // Check for identifier
        if (tokens[i].type == TOKEN_IDENTIFIER) {
            printf("Identifier: %s\n", tokens[i].value);
        }

        // Check for number
        else if (tokens[i].type == TOKEN_NUMBER) {
            printf("Number: %s\n", tokens[i].value);
        }

        // Check for string
        else if (tokens[i].type == TOKEN_STRING) {
            printf("String: %s\n", tokens[i].value);
        }

        // Check for keyword
        else if (tokens[i].type == TOKEN_KEYWORD) {
            printf("Keyword: %s\n", tokens[i].value);
        }

        // Check for symbol
        else if (tokens[i].type == TOKEN_SYMBOL) {
            printf("Symbol: %s\n", tokens[i].value);
        }

        // Check for error
        else if (tokens[i].type == TOKEN_ERROR) {
            printf("Error: Invalid token\n");
            exit(1);
        }

        i++;
    }
}

// Main function
int main(int argc, char **argv) {
    Token *tokens;

    // Check for input file
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    // Read input file
    char *input = NULL;
    size_t len = 0;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }
    getline(&input, &len, file);
    fclose(file);

    // Lex the input
    tokens = lexer(input);

    // Parse the tokens
    parser(tokens);

    // Free the tokens
    for (int i = 0; tokens[i].type != TOKEN_EOF; i++) {
        free(tokens[i].value);
    }
    free(tokens);

    return 0;
}