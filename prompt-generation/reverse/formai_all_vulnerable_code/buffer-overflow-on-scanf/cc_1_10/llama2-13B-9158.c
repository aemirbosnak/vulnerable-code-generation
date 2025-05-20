//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold the arithmetic operations and their parameters
typedef struct {
    char op; // operation (e.g. +, -, *, /)
    int a, b; // operands
} arithmetic_op_t;

// Define an array to store the arithmetic operations
arithmetic_op_t ops[10];

// Function to perform the arithmetic operations
void perform_ops(void) {
    int i, result;

    // Populate the ops array with user input
    for (i = 0; i < 10; i++) {
        printf("Enter operation %d: ", i + 1);
        scanf("%c%d%d", &ops[i].op, &ops[i].a, &ops[i].b);
    }

    // Loop through the ops array and perform the operations
    for (i = 0; i < 10; i++) {
        switch (ops[i].op) {
            case '+':
                result = ops[i].a + ops[i].b;
                break;
            case '-':
                result = ops[i].a - ops[i].b;
                break;
            case '*':
                result = ops[i].a * ops[i].b;
                break;
            case '/':
                result = ops[i].a / ops[i].b;
                break;
            default:
                printf("Invalid operation %c\n", ops[i].op);
                break;
        }

        // Print the result of each operation
        printf("Result of operation %d: %d\n", i + 1, result);
    }
}

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Loop through the ops array 10 times and perform the operations
    for (int i = 0; i < 10; i++) {
        perform_ops();
    }

    return 0;
}