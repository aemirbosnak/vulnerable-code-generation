//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAX_OPERATIONS 5

// Structure to hold the numbers and operations
typedef struct {
    int number;
    char operation;
} operation_t;

// Array to store the numbers and operations
operation_t operations[MAX_OPERATIONS];

// Function to get the numbers and operations from the user
void get_operations() {
    int i, j;
    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Get the first number from the user
        printf("Enter the first number: ");
        scanf("%d", &operations[i].number);

        // Get the second number from the user
        printf("Enter the second number: ");
        scanf("%d", &operations[i].number);

        // Get the operation from the user
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &operations[i].operation);
    }
}

// Function to perform the operations
void perform_operations() {
    int i, j;
    for (i = 0; i < MAX_OPERATIONS; i++) {
        for (j = i + 1; j < MAX_OPERATIONS; j++) {
            // Perform the operation
            if (operations[i].operation == '+') {
                operations[j].number += operations[i].number;
            } else if (operations[i].operation == '-') {
                operations[j].number -= operations[i].number;
            } else if (operations[i].operation == '*') {
                operations[j].number *= operations[i].number;
            } else if (operations[i].operation == '/') {
                operations[j].number /= operations[i].number;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the numbers and operations
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].number = rand() % MAX_NUMBER;
        operations[i].operation = '+';
    }

    // Get the operations from the user
    get_operations();

    // Perform the operations
    perform_operations();

    // Print the results
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        printf("%d %c %d\n", operations[i].number, operations[i].operation, operations[i].number);
    }

    return 0;
}