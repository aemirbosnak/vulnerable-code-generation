//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    NUMBER,
    OPERATOR,
    END
} TokenType;

typedef struct {
    TokenType type;
    union {
        double value;
        char operator;
    } data;
} Token;

const char *input;
Token currentToken;

void nextToken() {
    while (isspace(*input)) input++; // Skip whitespace

    if (*input == '\0') {
        currentToken.type = END;
    } else if (isdigit(*input) || *input == '.') {
        currentToken.type = NUMBER;
        char *end;
        currentToken.data.value = strtod(input, &end);
        input = end;
    } else {
        currentToken.type = OPERATOR;
        currentToken.data.operator = *input++;
    }
}

double parseFactor();
double parseTerm();
double parseExpression();

double parseFactor() {
    nextToken(); // Get the next token
    
    if (currentToken.type == NUMBER) {
        return currentToken.data.value; 
    } else if (currentToken.data.operator == '(') {
        double result = parseExpression();
        nextToken(); // Consume closing parenthesis
        return result;
    }
    
    fprintf(stderr, "Error: Invalid factor\n");
    exit(EXIT_FAILURE);
}

double parseTerm() {
    double result = parseFactor(); // Start with the first factor

    while (1) {
        nextToken();
        if (currentToken.type == OPERATOR && (currentToken.data.operator == '*' || currentToken.data.operator == '/')) {
            char op = currentToken.data.operator;
            double nextFactor = parseFactor();
            if (op == '*') {
                result *= nextFactor;
            } else {
                if (nextFactor == 0) {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                result /= nextFactor;
            }
        } else {
            // Go back for the next token
            input--;
            break;
        }
    }

    return result;
}

double parseExpression() {
    double result = parseTerm(); // Start with the first term

    while (1) {
        nextToken();
        if (currentToken.type == OPERATOR && (currentToken.data.operator == '+' || currentToken.data.operator == '-')) {
            char op = currentToken.data.operator;
            double nextTerm = parseTerm();
            if (op == '+') {
                result += nextTerm;
            } else {
                result -= nextTerm;
            }
        } else {
            // Go back for the next token
            input--;
            break;
        }
    }

    return result;
}

int main() {
    char expression[256];
    printf("Enter an expression to evaluate (e.g., 3 + 4 * 2 / (1 - 5)):\n");
    
    while (1) {
        printf("> ");
        if (!fgets(expression, sizeof(expression), stdin)) {
            break; // Exit on EOF
        }

        input = expression;
        nextToken(); // Initialize tokenization
        
        if (currentToken.type == END) {
            break; // Exit on empty input
        }

        double result = parseExpression();
        printf("Result: %lf\n", result);
    }

    return 0;
}