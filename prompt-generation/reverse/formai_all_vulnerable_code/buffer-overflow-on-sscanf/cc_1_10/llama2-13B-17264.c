//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

// Define a struct to hold the math expressions and their results
typedef struct {
    char *expr;
    double result;
} math_expr_t;

// Define a function to parse the math expressions and evaluate them
double evaluate_expression(math_expr_t *expr) {
    double result = 0;
    // Parse the expression and evaluate it
    if (sscanf(expr->expr, "%lf", &result) == 1) {
        return result;
    } else {
        // If the expression is not a number, try to evaluate it as an expression
        if (strchr(expr->expr, '+') || strchr(expr->expr, '-') || strchr(expr->expr, '*') || strchr(expr->expr, '/')) {
            // Tokenize the expression into operands and operators
            char *token = strtok(expr->expr, " ");
            math_expr_t operand1, operand2;
            operand1.expr = token;
            operand2.expr = NULL;
            while ((token = strtok(NULL, " ")) != NULL) {
                if (strchr(token, '+') || strchr(token, '-') || strchr(token, '*') || strchr(token, '/')) {
                    operand2.expr = token;
                    break;
                } else {
                    operand2.expr = NULL;
                }
            }
            // Evaluate the expression
            if (operand2.expr == NULL) {
                // If there is only one operand, return its value
                return atof(operand1.expr);
            } else {
                // Evaluate the operands and perform the operation
                double op1 = atof(operand1.expr);
                double op2 = atof(operand2.expr);
                if (strchr(token, '+')) {
                    result = op1 + op2;
                } else if (strchr(token, '-')) {
                    result = op1 - op2;
                } else if (strchr(token, '*')) {
                    result = op1 * op2;
                } else if (strchr(token, '/')) {
                    result = op1 / op2;
                }
                return result;
            }
        } else {
            // If the expression is not a valid math expression, return 0
            return 0;
        }
    }
}

// Define a function to generate random math expressions
void generate_expression(math_expr_t *expr) {
    // Generate a random integer between 1 and 10
    int num1 = rand() % 10 + 1;
    // Generate a random operator ( Plus, Minus, Times, or Divide)
    char op = '+';
    switch (rand() % 4) {
        case 0:
            op = '+';
            break;
        case 1:
            op = '-';
            break;
        case 2:
            op = '*';
            break;
        case 3:
            op = '/';
            break;
    }
    // Generate a random integer between 1 and 10
    int num2 = rand() % 10 + 1;
    // Build the expression
    sprintf(expr->expr, "%d %c %d", num1, op, num2);
}

int main() {
    // Create a struct to hold the math expressions and their results
    math_expr_t expr;
    // Initialize the expression to a random value
    generate_expression(&expr);
    // Evaluate the expression and print the result
    double result = evaluate_expression(&expr);
    printf("The result of %s is %f\n", expr.expr, result);
    return 0;
}