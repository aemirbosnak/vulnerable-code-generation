//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 10

// Structure to hold the math expression and its result
typedef struct {
    char op[2];    // Operation (e.g. +, -, x, /)
    int num1, num2; // Numerical values
    int result;   // Calculated result
} math_expr_t;

// Function to parse the math expression and evaluate it
int parse_math_expr(math_expr_t *expr) {
    int i, j;
    char c;

    // Initialize the expression and result to 0
    expr->op[0] = '\0';
    expr->num1 = 0;
    expr->num2 = 0;
    expr->result = 0;

    // Get the next character from the input
    while ((c = getchar()) != EOF) {
        // If the character is a number, convert it to an integer
        if (isdigit(c)) {
            expr->num1 = expr->num1 * 10 + (c - '0');
        }
        // If the character is an operation, process it
        else if (isalpha(c)) {
            // If the operation is not yet defined, prompt the user to define it
            if (expr->op[0] == '\0') {
                printf("Operation not defined. Enter a valid operation (+, -, x, /): ");
                scanf("%s", expr->op);
            }
            // Process the operation
            else if (strcmp(expr->op, "+") == 0) {
                expr->result = expr->num1 + expr->num2;
            }
            else if (strcmp(expr->op, "-") == 0) {
                expr->result = expr->num1 - expr->num2;
            }
            else if (strcmp(expr->op, "*") == 0) {
                expr->result = expr->num1 * expr->num2;
            }
            else if (strcmp(expr->op, "/") == 0) {
                expr->result = expr->num1 / expr->num2;
            }
        }
    }

    // Check if the expression is valid
    if (expr->num1 == 0 || expr->num2 == 0) {
        printf("Invalid expression. Please enter valid numbers and operations.\n");
        return 0;
    }

    return 1;
}

// Function to print the result of the math expression
void print_result(math_expr_t *expr) {
    printf("Result: %d\n", expr->result);
}

int main() {
    math_expr_t expr;

    // Prompt the user to enter a math expression
    printf("Enter a math expression (+, -, x, /): ");

    // Parse the expression and evaluate it
    if (parse_math_expr(&expr) == 0) {
        return 0;
    }

    // Print the result of the expression
    print_result(&expr);

    // Ask the user if they want to try again
    printf("Do you want to try again? (y/n): ");
    char response;
    scanf("%c", &response);

    // If the user wants to try again, repeat the process
    if (response == 'y' || response == 'Y') {
        printf("Enter a math expression (+, -, x, /): ");
        parse_math_expr(&expr);
        print_result(&expr);
    }

    return 0;
}