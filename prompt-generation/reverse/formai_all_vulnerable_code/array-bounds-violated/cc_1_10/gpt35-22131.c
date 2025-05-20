//FormAI DATASET v1.0 Category: Syntax parsing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100
#define MAX_STRING_LENGTH 1000

// Function to check if character is alpha or not
int isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

// Function to check if character is a digit or not
int isDigit(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

// Function to check if character is whitespace or not
int isWhitespace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        return 1;
    else
        return 0;
}

// Token struct
typedef struct Token {
    char type[MAX_TOKEN_SIZE];
    char lexeme[MAX_TOKEN_SIZE];
} Token;

// Function to parse Tokens from input string
void parseTokens(char* input, Token* tokens, int* numTokens) {
    memset(tokens, 0, sizeof(Token) * MAX_STRING_LENGTH);
    *numTokens = 0;

    int i = 0;
    while (input[i] != '\0') {
        if (isWhitespace(input[i])) {
            i++;
            continue;
        }

        if (isAlpha(input[i])) {
            int j = 0;
            while (isAlpha(input[i]) || isDigit(input[i])) {
                tokens[*numTokens].lexeme[j] = input[i];
                i++;
                j++;
            }
            strcpy(tokens[*numTokens].type, "Identifier");
            (*numTokens)++;
            continue;
        }

        if (isDigit(input[i])) {
            int j = 0;
            while (isDigit(input[i])) {
                tokens[*numTokens].lexeme[j] = input[i];
                i++;
                j++;
            }
            strcpy(tokens[*numTokens].type, "Integer");
            (*numTokens)++;
            continue;
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            tokens[*numTokens].lexeme[0] = input[i];
            strcpy(tokens[*numTokens].type, "Operator");
            (*numTokens)++;
            i++;
            continue;
        }

        if (input[i] == '(' || input[i] == ')') {
            tokens[*numTokens].lexeme[0] = input[i];
            strcpy(tokens[*numTokens].type, "Delimiter");
            (*numTokens)++;
            i++;
            continue;
        }
        
        // Invalid character
        printf("Invalid character: %c\n", input[i]);
        exit(0);
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    Token tokens[MAX_STRING_LENGTH];
    int numTokens = 0;

    printf("Enter a string:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character

    // Parse tokens
    parseTokens(input, tokens, &numTokens);

    // Print tokens
    printf("Tokens:\n");
    for (int i = 0; i < numTokens; i++) {
        printf("%s: %s\n", tokens[i].type, tokens[i].lexeme);
    }

    return 0;
}