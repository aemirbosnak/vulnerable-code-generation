//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 42

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the Fibonacci sequence of a given number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int number;
    char operation;

    // Get the number and operation from the user
    printf("Enter a number and an operation (+, -, *, /): ");
    scanf("%d%c", &number, &operation);

    // Perform the operation
    if (operation == '+') {
        printf("The result of %d + %d is %d\n", number, MAGIC_NUMBER, number + MAGIC_NUMBER);
    } else if (operation == '-') {
        printf("The result of %d - %d is %d\n", number, MAGIC_NUMBER, number - MAGIC_NUMBER);
    } else if (operation == '*') {
        printf("The result of %d * %d is %d\n", number, MAGIC_NUMBER, number * MAGIC_NUMBER);
    } else if (operation == '/') {
        printf("The result of %d / %d is %d\n", number, MAGIC_NUMBER, number / MAGIC_NUMBER);
    } else {
        printf("Invalid operation. Please try again.");
        return 1;
    }

    // Calculate the factorial and Fibonacci sequence
    int factorial_result = factorial(number);
    int fibonacci_result = fibonacci(number);

    // Print the results
    printf("The factorial of %d is %d\n", number, factorial_result);
    printf("The Fibonacci sequence of %d is %d\n", number, fibonacci_result);

    return 0;
}