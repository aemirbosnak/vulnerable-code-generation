//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
// Scientific Calculator in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for mathematical operations
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define POW 5

// Define a structure for a token
typedef struct {
    int type; // Type of the token (e.g. ADD, SUB, etc.)
    double value; // Value of the token (e.g. 1.0, 2.0, etc.)
} token_t;

// Define a structure for a mathematical expression
typedef struct {
    token_t *tokens; // Array of tokens
    int num_tokens; // Number of tokens in the expression
} expr_t;

// Define a function to evaluate a mathematical expression
double evaluate(expr_t *expr) {
    double result = 0.0;
    for (int i = 0; i < expr->num_tokens; i++) {
        token_t *token = &expr->tokens[i];
        switch (token->type) {
            case ADD:
                result += token->value;
                break;
            case SUB:
                result -= token->value;
                break;
            case MUL:
                result *= token->value;
                break;
            case DIV:
                result /= token->value;
                break;
            case POW:
                result = pow(result, token->value);
                break;
            default:
                printf("Error: Invalid token type\n");
                return NAN;
        }
    }
    return result;
}

// Define a function to parse a mathematical expression
expr_t *parse(char *expr) {
    expr_t *result = malloc(sizeof(expr_t));
    result->num_tokens = 0;
    result->tokens = malloc(sizeof(token_t));
    char *token;
    double value;
    while ((token = strtok(expr, " ")) != NULL) {
        value = atof(token);
        token_t *new_token = malloc(sizeof(token_t));
        new_token->type = (value == 0.0) ? (int)value : ADD;
        new_token->value = value;
        result->tokens = realloc(result->tokens, (result->num_tokens + 1) * sizeof(token_t));
        result->tokens[result->num_tokens] = *new_token;
        result->num_tokens++;
        expr = NULL;
    }
    return result;
}

// Define a function to print the result of a mathematical expression
void print_result(expr_t *expr) {
    printf("Result: %f\n", evaluate(expr));
}

// Main function
int main() {
    char *expr = "1.0 + 2.0 * 3.0 - 4.0 / 5.0";
    expr_t *parsed_expr = parse(expr);
    print_result(parsed_expr);
    return 0;
}