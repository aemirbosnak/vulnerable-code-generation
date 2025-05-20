//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function prototypes */
void parse_expression();
void parse_term();
void parse_factor();
int next_token();
void error(const char*);

/* Global variables */
int current_token;
char* input;

int main() {
    input = malloc(100 * sizeof(char));  // Allocate memory for input
    printf("Enter expression: ");
    scanf("%s", input);  // Read input from user

    current_token = next_token();  // Get first token
    parse_expression();  // Start parsing

    if (current_token != EOF) {  // Check if there are any extra tokens
        error("Unexpected token");
    }

    free(input);  // Free allocated memory
    return 0;
}

/* Parse an expression */
void parse_expression() {
    parse_term();  // Parse first term

    while (current_token == '+' || current_token == '-') {  // Loop while there are still terms to add/subtract
        current_token = next_token();  // Get next token
        parse_term();  // Parse next term
    }
}

/* Parse a term */
void parse_term() {
    parse_factor();  // Parse first factor

    while (current_token == '*' || current_token == '/') {  // Loop while there are still factors to multiply/divide
        current_token = next_token();  // Get next token
        parse_factor();  // Parse next factor
    }
}

/* Parse a factor */
void parse_factor() {
    if (current_token == '(') {  // Expression in parentheses
        current_token = next_token();  // Get next token
        parse_expression();  // Parse expression inside parentheses

        if (current_token != ')') {  // Check if parentheses are closed
            error("Expected closing parentheses");
        }

        current_token = next_token();  // Get next token
    } else if (isdigit(current_token)) {  // Number
        current_token = next_token();  // Get next token
    } else {  // Invalid token
        error("Invalid token");
    }
}

/* Get next token */
int next_token() {
    static int i = 0;

    while (isspace(input[i])) {  // Skip whitespace
        i++;
    }

    if (input[i] == '\0') {  // End of input
        return EOF;
    }

    int token = input[i++];

    if (!isdigit(token) && token != '+' && token != '-' && token != '*' && token != '/' && token != '(' && token != ')') {
        error("Invalid character");
    }

    return token;
}

/* Handle errors */
void error(const char* message) {
    printf("Error: %s\n", message);
    exit(1);
}