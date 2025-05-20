//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100

// Function to handle errors
void handle_error(const char *msg) {
    printf("Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to perform arithmetic operations
int perform_ops(int num1, int num2, char op) {
    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            handle_error("Invalid operation");
            return 0;
    }

    return result;
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
    result = perform_ops(num1, num2, op);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}