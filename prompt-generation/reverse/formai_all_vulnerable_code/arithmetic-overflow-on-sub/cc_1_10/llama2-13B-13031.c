//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the C Math Exercise! \n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Check if the result is equal to the magic number
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the hidden magic number!\n");
    } else {
        printf("Too bad, the magic number was not found.\n");
    }

    return 0;
}