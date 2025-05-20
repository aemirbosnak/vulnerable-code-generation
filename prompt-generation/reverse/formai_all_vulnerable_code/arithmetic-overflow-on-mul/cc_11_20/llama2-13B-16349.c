//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER -1000000

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to Safe Arithmetic Land! Please enter two numbers and an operation:\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Check if the operation is valid
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        printf("Invalid operation! Please try again.\n");
        return 1;
    }

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    }

    // Check if the result is within the valid range
    if (sum < MIN_NUMBER || sum > MAX_NUMBER) {
        printf("Result is out of range! Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result is: %d\n", sum);

    return 0;
}