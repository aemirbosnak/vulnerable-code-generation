//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MIN_NUM 1

// Function to generate a random number between 1 and 100
int random_num() {
    return (rand() % 100) + 1;
}

// Function to check if the input is a valid number
int is_valid_number(int num) {
    if (num < MIN_NUM || num > MAX_NUM) {
        return 0;
    }
    return 1;
}

// Function to perform arithmetic operations
int perform_arithmetic_ops(int num1, int num2, char op) {
    int result;

    // Check if the input numbers are valid
    if (!is_valid_number(num1) || !is_valid_number(num2)) {
        printf("Invalid input numbers\n");
        return 0;
    }

    // Perform the arithmetic operation
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
            printf("Invalid operator\n");
            return 0;
    }

    // Check if the result is valid
    if (result < MIN_NUM || result > MAX_NUM) {
        printf("Invalid result\n");
        return 0;
    }

    return result;
}

int main() {
    int num1, num2, result;
    char op;

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the arithmetic operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation
    result = perform_arithmetic_ops(num1, num2, op);

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}