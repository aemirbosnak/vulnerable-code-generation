//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

// Function to handle invalid input
void invalid_input_handler(int line_number) {
    printf("Invalid input on line %d. Please enter a valid number.\n", line_number);
    getchar(); // Discards the invalid input
}

// Function to handle division by zero
void divide_by_zero_handler(int line_number) {
    printf("Error: Division by zero on line %d. Program terminating.\n", line_number);
    exit(EXIT_FAILURE);
}

int main() {
    int num1, num2, result;
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

    // Perform the operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;

        // Check for division by zero
        if (num2 == 0) {
            divide_by_zero_handler(__LINE__);
        }
    } else {
        invalid_input_handler(__LINE__);
    }

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}