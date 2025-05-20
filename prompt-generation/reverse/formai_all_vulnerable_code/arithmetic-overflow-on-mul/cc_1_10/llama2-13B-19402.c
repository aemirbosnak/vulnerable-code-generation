//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char operation;
    float result;

    printf("Welcome to the Automated Arithmetic Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (e.g. +, -, *, /)
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        sum = num1 + num2;
    } else if (operation == '-') {
        sum = num1 - num2;
    } else if (operation == '*') {
        sum = num1 * num2;
    } else if (operation == '/') {
        sum = num1 / num2;
    } else {
        sum = MAGIC_NUMBER; // handle invalid input
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, operation, num2, sum);

    // Get the result from the user
    printf("Do you want to calculate again? (y/n): ");
    scanf(" %c", &operation);

    if (operation == 'y') {
        main(); // recursive call
    } else {
        printf("Goodbye!.\n");
    }

    return 0;
}