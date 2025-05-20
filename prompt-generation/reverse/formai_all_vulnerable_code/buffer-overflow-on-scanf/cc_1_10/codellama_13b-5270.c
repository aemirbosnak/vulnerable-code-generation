//Code Llama-13B DATASET v1.0 Category: Arithmetic ; Style: decentralized
/*
 * A decentralized arithmetic example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the user's input
void get_input(int *num1, int *num2) {
    printf("Enter two numbers: ");
    scanf("%d %d", num1, num2);
}

// Function to perform arithmetic operations
void perform_operation(int num1, int num2, char operation) {
    int result = 0;

    switch (operation) {
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
            printf("Invalid operation!\n");
            break;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2;
    char operation;

    // Get the user's input
    get_input(&num1, &num2);

    // Get the user's operation
    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    perform_operation(num1, num2, operation);

    return 0;
}