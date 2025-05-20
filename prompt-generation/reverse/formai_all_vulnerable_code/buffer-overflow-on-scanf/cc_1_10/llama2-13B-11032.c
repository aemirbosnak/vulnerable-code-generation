//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_NUMBER 1000

// Define a structure to hold the arithmetic operations
typedef struct {
    char op;  // Operation (e.g. +, -, *, /)
    int num1, num2;  // Two integers for the operands
} arithmetic_operation;

// Define an array to store the arithmetic operations
arithmetic_operation operations[MAX_INPUT];

// Function to read the arithmetic operations from the user
void get_operations(void) {
    int i, j;

    for (i = 0; i < MAX_INPUT; i++) {
        printf("Enter an arithmetic operation (+, -, *, /): ");
        scanf(" %c", &operations[i].op);

        // Get the two integers for the operands
        printf("Enter the first operand: ");
        scanf(" %d", &operations[i].num1);
        printf("Enter the second operand: ");
        scanf(" %d", &operations[i].num2);
    }
}

// Function to perform the arithmetic operations
void perform_operations(void) {
    int i;

    for (i = 0; i < MAX_INPUT; i++) {
        switch (operations[i].op) {
            case '+':
                printf("The sum of %d and %d is %d\n", operations[i].num1, operations[i].num2, operations[i].num1 + operations[i].num2);
                break;
            case '-':
                printf("The difference of %d and %d is %d\n", operations[i].num1, operations[i].num2, operations[i].num1 - operations[i].num2);
                break;
            case '*':
                printf("The product of %d and %d is %d\n", operations[i].num1, operations[i].num2, operations[i].num1 * operations[i].num2);
                break;
            case '/':
                if (operations[i].num2 == 0) {
                    printf("Error: division by zero\n");
                } else {
                    printf("The quotient of %d and %d is %d\n", operations[i].num1, operations[i].num2, operations[i].num1 / operations[i].num2);
                }
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
    }
}

int main(void) {
    srand(time(NULL));  // Seed the random number generator

    // Get the arithmetic operations from the user
    get_operations();

    // Perform the arithmetic operations
    perform_operations();

    return 0;
}