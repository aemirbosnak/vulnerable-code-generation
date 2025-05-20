//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the fibonacci sequence of a given number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num1, num2, sum, product, factorial_result, fibonacci_result;
    char op;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operator from the user
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        product = num1 / num2;
    } else {
        printf("Invalid operator\n");
        return 1;
    }

    // Calculate the factorial of the first number
    factorial_result = factorial(num1);

    // Calculate the fibonacci sequence of the first number
    fibonacci_result = fibonacci(num1);

    // Print the results
    printf("The result of %d + %d is %d\n", num1, num2, sum);
    printf("The result of %d * %d is %d\n", num1, num2, product);
    printf("The factorial of %d is %d\n", num1, factorial_result);
    printf("The fibonacci sequence of %d is %d\n", num1, fibonacci_result);

    return 0;
}