//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAX_OPERATIONS 10

// Define a struct to hold the operation and its parameters
typedef struct {
    char op; // operation (e.g. +, -, *, /)
    int a, b; // operands
} operation;

// Define an array to hold the operations
operation operations[MAX_OPERATIONS];

// Define a function to perform an operation
void do_operation(operation *op) {
    switch (op->op) {
        case '+':
            op->a = op->a + op->b;
            break;
        case '-':
            op->a = op->a - op->b;
            break;
        case '*':
            op->a = op->a * op->b;
            break;
        case '/':
            if (op->b == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            op->a = op->a / op->b;
            break;
        default:
            printf("Error: unknown operation %c\n", op->op);
            exit(1);
    }
}

int main() {
    int i, num1, num2, result;
    char op;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Check if the operation is valid
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        printf("Error: invalid operation\n");
        exit(1);
    }

    // Create an operation struct and add it to the array
    operation *op_struct = malloc(sizeof(operation));
    op_struct->op = op;
    op_struct->a = num1;
    op_struct->b = num2;
    operations[0] = *op_struct;

    // Perform the operation
    do_operation(operations);

    // Print the result
    printf("Result: %d\n", operations[0].a);

    // Free the memory
    free(op_struct);

    return 0;
}