//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM -100000

// Struct to hold a single arithmetic operation and its result
typedef struct {
    char op; // Operation (e.g. +, -, *, /)
    int a, b; // Operands
    int result; // Result of the operation
} ArithOp;

// Function to perform an arithmetic operation
ArithOp perform_arith_op(char op, int a, int b) {
    ArithOp result;

    switch (op) {
        case '+':
            result.result = a + b;
            break;
        case '-':
            result.result = a - b;
            break;
        case '*':
            result.result = a * b;
            break;
        case '/':
            if (b == 0) {
                result.result = -1; // Division by zero
            } else {
                result.result = a / b;
            }
            break;
        default:
            result.result = -1; // Unknown operation
            break;
    }

    return result;
}

// Function to perform a series of arithmetic operations
ArithOp perform_series(char op[], int a, int b) {
    ArithOp result;

    for (int i = 0; op[i] != '\0'; i++) {
        result = perform_arith_op(op[i], a, b);
        a = result.result;
        b = 0;
    }

    return result;
}

int main() {
    // Initialize random numbers
    srand(time(NULL));
    int a = rand() % MAX_NUM + MIN_NUM;
    int b = rand() % MAX_NUM + MIN_NUM;

    // Perform a series of arithmetic operations
    char op[10];
    for (int i = 0; i < 10; i++) {
        op[i] = '+'; // Default operation is addition
        if (rand() % 2 == 0) {
            op[i] = '-'; // 50% chance of subtracting
        } else {
            op[i] = '*'; // 30% chance of multiplying
        }
        if (rand() % 3 == 0) {
            op[i] = '/'; // 20% chance of dividing
        }
    }

    ArithOp result = perform_series(op, a, b);

    // Print the final result
    printf("%d\n", result.result);

    return 0;
}