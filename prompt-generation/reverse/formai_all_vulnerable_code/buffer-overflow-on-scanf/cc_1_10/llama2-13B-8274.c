//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

// Structure to store numbers and operations
typedef struct {
    int number;
    char operation;
} operation;

// Array to store numbers and operations
operation operations[MAX_OPERATIONS][MAX_NUMBERS];

// Function to perform an arithmetic operation
void perform_operation(int number1, char operation1, int number2, char operation2) {
    int result;

    // Perform the operation
    switch (operation1) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
        default:
            result = -1;
            break;
    }

    // Print the result
    printf("Result: %d\n", result);
}

// Function to get user input
void get_input() {
    int i, j;

    // Loop until all operations and numbers are entered
    while (1) {
        // Get an operation
        printf("Enter an operation (+, -, *, /): ");
        scanf("%c", &operations[i][j].operation);

        // Get a number
        printf("Enter a number: ");
        scanf("%d", &operations[i][j].number);

        // Check if the operation and number are valid
        if (operations[i][j].operation == '+' || operations[i][j].operation == '-' || operations[i][j].operation == '*' || operations[i][j].operation == '/') {
            // Add the operation and number to the array
            operations[i][j].operation = operations[i][j].operation;
            operations[i][j].number = operations[i][j].number;
        } else {
            printf("Invalid input. Try again.\n");
        }

        // Increment the index
        j++;

        // Check if all operations and numbers have been entered
        if (j == MAX_NUMBERS) {
            break;
        }
    }
}

// Function to perform all operations
void perform_all_operations() {
    int i;

    // Loop through all operations
    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Perform each operation
        perform_operation(operations[i][0].number, operations[i][0].operation, operations[i][1].number, operations[i][1].operation);
    }
}

int main() {
    int i, j;

    // Initialize the arrays
    for (i = 0; i < MAX_OPERATIONS; i++) {
        for (j = 0; j < MAX_NUMBERS; j++) {
            operations[i][j].number = 0;
            operations[i][j].operation = '\0';
        }
    }

    // Get user input
    get_input();

    // Perform all operations
    perform_all_operations();

    return 0;
}