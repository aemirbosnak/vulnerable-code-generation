//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
};

// Token struct
struct Token {
    enum TokenType type;
    char *lexeme;
};

// Lexer struct
struct Lexer {
    char *input;
    int position;
    int length;
};

// Function to initialize the lexer
struct Lexer *lexer_init(char *input) {
    struct Lexer *lexer = malloc(sizeof(struct Lexer));
    lexer->input = input;
    lexer->position = 0;
    lexer->length = strlen(input);
    return lexer;
}

// Function to get the next token
struct Token *lexer_next_token(struct Lexer *lexer) {
    struct Token *token = malloc(sizeof(struct Token));

    // Skip whitespace
    while (lexer->position < lexer->length && isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }

    // Check if we're at the end of the input
    if (lexer->position >= lexer->length) {
        token->type = TOKEN_EOF;
        token->lexeme = NULL;
        return token;
    }

    // Get the first character of the token
    char c = lexer->input[lexer->position];

    // Check if the token is an identifier
    if (isalpha(c)) {
        int start = lexer->position;
        while (lexer->position < lexer->length && isalnum(lexer->input[lexer->position])) {
            lexer->position++;
        }
        int end = lexer->position;
        token->type = TOKEN_IDENTIFIER;
        token->lexeme = strndup(lexer->input + start, end - start);
        return token;
    }

    // Check if the token is a number
    if (isdigit(c)) {
        int start = lexer->position;
        while (lexer->position < lexer->length && isdigit(lexer->input[lexer->position])) {
            lexer->position++;
        }
        int end = lexer->position;
        token->type = TOKEN_NUMBER;
        token->lexeme = strndup(lexer->input + start, end - start);
        return token;
    }

    // Check if the token is a string
    if (c == '"') {
        int start = lexer->position;
        lexer->position++;
        while (lexer->position < lexer->length && lexer->input[lexer->position] != '"') {
            lexer->position++;
        }
        int end = lexer->position;
        token->type = TOKEN_STRING;
        token->lexeme = strndup(lexer->input + start + 1, end - start - 1);
        lexer->position++;
        return token;
    }

    // Check if the token is a keyword
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z') {
        int start = lexer->position;
        while (lexer->position < lexer->length && (isalpha(lexer->input[lexer->position]) || isdigit(lexer->input[lexer->position]))) {
            lexer->position++;
        }
        int end = lexer->position;
        token->type = TOKEN_KEYWORD;
        token->lexeme = strndup(lexer->input + start, end - start);
        return token;
    }

    // Check if the token is an operator
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
        token->type = TOKEN_OPERATOR;
        token->lexeme = strndup(&c, 1);
        lexer->position++;
        return token;
    }

    // Check if the token is a punctuator
    if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ';') {
        token->type = TOKEN_PUNCTUATOR;
        token->lexeme = strndup(&c, 1);
        lexer->position++;
        return token;
    }

    // Unknown token
    token->type = TOKEN_EOF;
    token->lexeme = NULL;
    return token;
}

// Main function
int main(int argc, char **argv) {
    // Get the input from the command line
    char *input = argv[1];

    // Initialize the lexer
    struct Lexer *lexer = lexer_init(input);

    // Get the first token
    struct Token *token = lexer_next_token(lexer);

    // While we haven't reached the end of the input, print the token
    while (token->type != TOKEN_EOF) {
        printf("%s\n", token->lexeme);
        token = lexer_next_token(lexer);
    }

    // Free the token
    free(token);

    // Free the lexer
    free(lexer);

    return 0;
}