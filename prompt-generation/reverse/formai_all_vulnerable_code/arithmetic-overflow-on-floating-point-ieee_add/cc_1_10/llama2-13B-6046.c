//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Define a struct to hold the math expression
typedef struct {
    char op[2];  // Operator (e.g. "+" or "-")
    double num1;  // First number
    double num2;  // Second number
} math_expr;

// Define a function to parse the math expression and evaluate it
math_expr parse_expr(char *str) {
    // Tokenize the string into individual characters
    char *token = strtok(str, " ");

    // Create a struct to hold the math expression
    math_expr expr;

    // Parse the operator
    if (strcmp(token, "+") == 0) {
        expr.op[0] = '+';
    } else if (strcmp(token, "-") == 0) {
        expr.op[0] = '-';
    } else if (strcmp(token, "*") == 0) {
        expr.op[0] = '*';
    } else if (strcmp(token, "/") == 0) {
        expr.op[0] = '/';
    } else {
        // Handle invalid operators
        printf("Invalid operator: %s\n", token);
        return expr;
    }

    // Parse the first number
    token = strtok(NULL, " ");
    expr.num1 = atof(token);

    // Parse the second number
    token = strtok(NULL, " ");
    expr.num2 = atof(token);

    return expr;
}

// Define a function to evaluate the math expression
double evaluate(math_expr expr) {
    double result;

    // Handle the different operators
    switch (expr.op[0]) {
        case '+':
            result = expr.num1 + expr.num2;
            break;
        case '-':
            result = expr.num1 - expr.num2;
            break;
        case '*':
            result = expr.num1 * expr.num2;
            break;
        case '/':
            result = expr.num1 / expr.num2;
            break;
        default:
            // Handle invalid operators
            printf("Invalid operator: %c\n", expr.op[0]);
            result = 0;
            break;
    }

    return result;
}

int main() {
    // Get the math expression from the user
    char expr_str[MAX_LENGTH];
    printf("Enter a math expression: ");
    fgets(expr_str, MAX_LENGTH, stdin);

    // Parse the math expression
    math_expr expr = parse_expr(expr_str);

    // Evaluate the math expression
    double result = evaluate(expr);

    // Print the result
    printf("Result: %f\n", result);

    return 0;
}