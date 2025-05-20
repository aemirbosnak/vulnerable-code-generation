//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a mathematical expression
typedef struct {
    char op[2];    // operator (e.g. +, -, x, /)
    double num1, num2; // numbers in the expression
} expr_t;

// Function to parse a mathematical expression from a file
expr_t* parse_expression(FILE* file) {
    // Create a new expression struct
    expr_t* expr = (expr_t*) malloc(sizeof(expr_t));

    // Read the operator from the file
    char op[2];
    fscanf(file, "%c%c", &op[0], &op[1]);
    expr->op[0] = op[0];
    expr->op[1] = op[1];

    // Read the two numbers from the file
    double num1, num2;
    fscanf(file, "%lf%lf", &num1, &num2);
    expr->num1 = num1;
    expr->num2 = num2;

    return expr;
}

// Function to evaluate a mathematical expression
double evaluate(expr_t* expr) {
    double result = 0;

    // Evaluate the expression based on the operator and numbers
    switch (expr->op[0]) {
        case '+':
            result = expr->num1 + expr->num2;
            break;
        case '-':
            result = expr->num1 - expr->num2;
            break;
        case '*':
            result = expr->num1 * expr->num2;
            break;
        case '/':
            result = expr->num1 / expr->num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    return result;
}

int main() {
    // Open the file and read the first expression
    FILE* file = fopen("expressions.txt", "r");
    expr_t* expr = parse_expression(file);

    // Evaluate the expression and print the result
    double result = evaluate(expr);
    printf("Result: %f\n", result);

    // Close the file
    fclose(file);

    return 0;
}