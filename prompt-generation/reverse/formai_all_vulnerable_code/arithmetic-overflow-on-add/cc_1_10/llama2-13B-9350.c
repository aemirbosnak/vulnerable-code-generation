//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000
#define MAX_OPERATIONS 5

// Structure to hold the numbers and operations
typedef struct {
    int number;
    char operation;
} operation;

// Array to store the numbers and operations
operation operations[MAX_OPERATIONS];

// Function to get the numbers and operations from the user
void get_operations(void);

// Function to perform the arithmetic operations
void perform_operations(void);

// Function to print the results
void print_results(void);

int main(void) {
    // Initialize the operations array
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].number = 0;
        operations[i].operation = '\0';
    }

    // Get the numbers and operations from the user
    get_operations();

    // Perform the arithmetic operations
    perform_operations();

    // Print the results
    print_results();

    return 0;
}

// Function to get the numbers and operations from the user
void get_operations(void) {
    int i, j;

    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Get the number from the user
        printf("Enter a number: ");
        scanf("%d", &operations[i].number);

        // Get the operation from the user
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operations[i].operation);
    }
}

// Function to perform the arithmetic operations
void perform_operations(void) {
    int i, j;
    int result;

    // Iterate through the operations array
    for (i = 0; i < MAX_OPERATIONS; i++) {
        // If the operation is not NULL, perform the operation
        if (operations[i].operation != '\0') {
            // If the operation is addition, subtraction, or multiplication
            if (operations[i].operation == '+' || operations[i].operation == '-' || operations[i].operation == '*') {
                // Perform the operation
                result = operations[i].number + (operations[i].operation == '+' ? operations[i + 1].number : operations[i + 1].number - operations[i].number);
            } else if (operations[i].operation == '/') {
                // Perform the operation
                result = operations[i].number / operations[i + 1].number;
            } else {
                // If the operation is not valid, print an error message
                printf("Invalid operation\n");
                return;
            }

            // Store the result in the next index of the operations array
            operations[i + 1].number = result;
        }
    }
}

// Function to print the results
void print_results(void) {
    int i;

    // Iterate through the operations array
    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Print the number and operation
        printf("%d %c %d\n", operations[i].number, operations[i].operation, operations[i + 1].number);
    }
}