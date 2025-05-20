//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char op;

    printf("Welcome to the Brave C Math Adventure!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (add, subtract, multiply, or divide)
    printf("Choose an operation (+, -, x, or /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == 'x') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        printf("Invalid operation. Quitting...\n");
        return 1;
    }

    // Print the result
    printf("Result: %d\n", result);

    // Add some magic to the result
    result *= MAGIC_NUMBER;

    // Print the final result
    printf("Final result: %d\n", result);

    return 0;
}