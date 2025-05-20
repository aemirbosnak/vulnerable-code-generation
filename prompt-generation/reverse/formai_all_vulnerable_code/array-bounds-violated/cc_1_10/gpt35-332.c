//FormAI DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

// Token types
typedef enum {
    INT, OP, LPAREN, RPAREN, END
} Token_Type;

// Token structure
typedef struct {
    Token_Type type;
    int value;
} Token;

// Function prototypes
void error(char*);
int get_next_token(char *, int);
int parse_expression(char *);
int parse_term(char *);
int parse_factor(char *);

// Global variables
Token current_token;
char input[MAX_LENGTH];
int input_length;
int position = 0;

// Main function
int main() {
    printf("Enter expression: ");
    fgets(input, MAX_LENGTH, stdin);
    input_length = strlen(input);
    input[input_length - 1] = '\0';
    input_length--;

    // Parsing expression
    int result = parse_expression(input);

    if (current_token.type != END) {
        error("Invalid expression.");
    }

    printf("Result: %d\n", result);

    return 0;
}

// Error function
void error(char *message) {
    printf("%s\n", message);
    exit(1);
}

// Get next token function
int get_next_token(char *input, int position) {
    int value = 0;
    char ch = input[position];

    while (isspace(ch) && position < input_length) {
        ch = input[++position];
    }

    if (isdigit(ch)) {
        while (isdigit(ch) && position < input_length) {
            value = (value * 10) + (ch - '0');
            ch = input[++position];
        }

        current_token.type = INT;
        current_token.value = value;
    } else if (ch == '+') {
        current_token.type = OP;
        current_token.value = '+';
        position++;
    } else if (ch == '-') {
        current_token.type = OP;
        current_token.value = '-';
        position++;
    } else if (ch == '(') {
        current_token.type = LPAREN;
        current_token.value = '(';
        position++;
    } else if (ch == ')') {
        current_token.type = RPAREN;
        current_token.value = ')';
        position++;
    } else {
        error("Invalid character.");
    }

    return position;
}

// Parse expression function
int parse_expression(char *input) {
    int result = parse_term(input);

    while (current_token.type == OP && (current_token.value == '+' || current_token.value == '-')) {
        int op = current_token.value;

        position = get_next_token(input, position);
        int term = parse_term(input);

        if (op == '+') {
            result += term;
        } else if (op == '-') {
            result -= term;
        }
    }

    return result;
}

// Parse term function
int parse_term(char *input) {
    int result = parse_factor(input);

    while (current_token.type == OP && (current_token.value == '*' || current_token.value == '/')) {
        int op = current_token.value;

        position = get_next_token(input, position);
        int factor = parse_factor(input);

        if (op == '*') {
            result *= factor;
        } else if (op == '/') {
            if (factor == 0) {
                error("Division by zero.");
            }

            result /= factor;
        }
    }

    return result;
}

// Parse factor function
int parse_factor(char *input) {
    int result;

    if (current_token.type == INT) {
        result = current_token.value;
        position = get_next_token(input, position);
    } else if (current_token.type == LPAREN) {
        position = get_next_token(input, position);
        result = parse_expression(input);

        if (current_token.type != RPAREN) {
            error("Missing right parenthesis.");
        }

        position = get_next_token(input, position);
    } else {
        error("Invalid factor.");
    }

    return result;
}