//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 1000
#define MAX_OPERATIONS 10

// Structure to store the expression and its operations
typedef struct {
    char op[3]; // Operation (e.g. +, -, *, /)
    int num1, num2; // Numerical values
} operation;

// Function to evaluate the expression
double evaluate(operation *ops, int num_ops) {
    double result = 0;
    for (int i = 0; i < num_ops; i++) {
        switch (ops[i].op[0]) {
            case '+':
                result += ops[i].num1 + ops[i].num2;
                break;
            case '-':
                result -= ops[i].num1 - ops[i].num2;
                break;
            case '*':
                result *= ops[i].num1 * ops[i].num2;
                break;
            case '/':
                result /= ops[i].num1 / ops[i].num2;
                break;
            default:
                printf("Invalid operation %c\n", ops[i].op[0]);
                return 0;
        }
    }
    return result;
}

// Function to parse the expression and store it in the operation array
void parse_expression(char *expression, operation *ops, int *num_ops) {
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            ops[i].op[0] = expression[i];
            ops[i].num1 = atoi(expression + i + 1);
            i++;
            ops[i].num2 = atoi(expression + i + 1);
            i++;
        } else {
            ops[i].num1 = atoi(expression + i + 1);
            i++;
        }
    }
    *num_ops = i;
}

int main() {
    int num_ops;
    operation ops[MAX_OPERATIONS];

    // Parse the expression
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);
    parse_expression(expression, ops, &num_ops);

    // Evaluate the expression
    double result = evaluate(ops, num_ops);

    // Print the result
    printf("Result: %f\n", result);

    return 0;
}