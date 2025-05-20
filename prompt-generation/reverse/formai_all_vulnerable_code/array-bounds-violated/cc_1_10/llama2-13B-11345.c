//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 10
#define MAX_EXPRESSIONS 5

// Structure to represent an arithmetic expression
typedef struct {
    char op[2];  // Operation (e.g., +, -, *, /)
    int num1, num2; // Numeric values
} expression_t;

// Function to evaluate an arithmetic expression
int evaluate(expression_t *expr) {
    int result;

    // Handle special cases
    if (strcmp(expr->op, "+") == 0) {
        result = expr->num1 + expr->num2;
    } else if (strcmp(expr->op, "-") == 0) {
        result = expr->num1 - expr->num2;
    } else if (strcmp(expr->op, "*") == 0) {
        result = expr->num1 * expr->num2;
    } else if (strcmp(expr->op, "/") == 0) {
        result = expr->num1 / expr->num2;
    } else {
        // Unknown operation
        result = -1;
    }

    return result;
}

int main() {
    // Initialize array of expressions
    expression_t expressions[MAX_EXPRESSIONS];
    for (int i = 0; i < MAX_EXPRESSIONS; i++) {
        expressions[i].op[0] = '\0';
        expressions[i].num1 = 0;
        expressions[i].num2 = 0;
    }

    // Read expressions from the user
    for (int i = 0; i < MAX_OPERANDS; i++) {
        char op[2];
        int num1, num2;

        printf("Enter expression %d: ", i + 1);
        scanf("%1s%d%1s%d", op, &num1, op, &num2);

        // Add expression to the array
        strcpy(expressions[i].op, op);
        expressions[i].num1 = num1;
        expressions[i].num2 = num2;
    }

    // Evaluate each expression and print the results
    for (int i = 0; i < MAX_EXPRESSIONS; i++) {
        int result = evaluate(&expressions[i]);
        if (result == -1) {
            printf("Error: Unknown operation\n");
        } else {
            printf("Result: %d\n", result);
        }
    }

    return 0;
}