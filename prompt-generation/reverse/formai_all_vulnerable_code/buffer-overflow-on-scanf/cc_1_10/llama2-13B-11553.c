//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

// Structure to store operand and operation
typedef struct {
    int number;
    char operation;
} operation;

// Array to store operands and operations
operation operations[MAX_OPERATIONS];

// Function to read operations and operands from user
void read_operations(void) {
    int i, j;
    char op;

    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Read operation
        printf("Enter operation (+, -, *, /): ");
        scanf("%c", &op);

        // Read operand
        printf("Enter operand: ");
        scanf("%d", &operations[i].number);

        // Store operation and operand in array
        operations[i].operation = op;
    }
}

// Function to perform arithmetic operations
void perform_operations(void) {
    int i, j;

    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Perform operation
        switch (operations[i].operation) {
            case '+':
                operations[i].number = operations[i].number + operations[i + 1].number;
                break;
            case '-':
                operations[i].number = operations[i].number - operations[i + 1].number;
                break;
            case '*':
                operations[i].number = operations[i].number * operations[i + 1].number;
                break;
            case '/':
                if (operations[i + 1].number == 0) {
                    printf("Error: division by zero\n");
                    return;
                }
                operations[i].number = operations[i].number / operations[i + 1].number;
                break;
            default:
                printf("Invalid operation\n");
                return;
        }
    }
}

int main(void) {
    int i, j;

    // Read operations and operands from user
    read_operations();

    // Perform arithmetic operations
    perform_operations();

    // Print results
    for (i = 0; i < MAX_OPERATIONS; i++) {
        printf("%d %c %d\n", operations[i].number, operations[i].operation, operations[i + 1].number);
    }

    return 0;
}