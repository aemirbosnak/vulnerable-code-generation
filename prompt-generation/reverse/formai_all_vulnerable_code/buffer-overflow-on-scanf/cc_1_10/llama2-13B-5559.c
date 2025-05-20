//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold our arithmetic operations
typedef struct {
    int op; // operation (add, sub, mult, div)
    int a, b; // operands
} arithmetic_op_t;

// Function to perform an arithmetic operation
arithmetic_op_t perform_arith(arithmetic_op_t op) {
    switch (op.op) {
        case 1: // add
            return (arithmetic_op_t) {.op = op.op, .a = op.a + op.b};
        case 2: // sub
            return (arithmetic_op_t) {.op = op.op, .a = op.a - op.b};
        case 3: // mult
            return (arithmetic_op_t) {.op = op.op, .a = op.a * op.b};
        case 4: // div
            return (arithmetic_op_t) {.op = op.op, .a = op.a / op.b};
        default:
            return (arithmetic_op_t) {.op = 0, .a = 0, .b = 0};
    }
}

int main() {
    // Create a menu for the user to choose an operation
    int choice;
    printf("Welcome to Arithmetic Land!\n");
    printf("Please select an operation from the following menu:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    // Prompt the user for the operands
    int a, b;
    printf("Enter the first operand: ");
    scanf("%d", &a);
    printf("Enter the second operand: ");
    scanf("%d", &b);

    // Create an arithmetic operation struct
    arithmetic_op_t op = {.op = choice, .a = a, .b = b};

    // Perform the operation and print the result
    arithmetic_op_t result = perform_arith(op);
    printf("Result: %d\n", result.a);

    return 0;
}