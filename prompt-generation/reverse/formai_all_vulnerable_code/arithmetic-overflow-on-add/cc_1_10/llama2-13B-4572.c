//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple of two integers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2, product, sum, difference, remainder, quotient, divide;
    char operation;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        sum = num1 + num2;
    } else if (operation == '-') {
        difference = num1 - num2;
    } else if (operation == '*') {
        product = num1 * num2;
    } else if (operation == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    } else {
        printf("Invalid operation\n");
        return 1;
    }

    // Check for overflow
    if (product > MAX_INT || product < MIN_INT) {
        printf("Overflow\n");
        return 2;
    }

    // Check for division by zero
    if (num2 == 0) {
        printf("Division by zero\n");
        return 3;
    }

    // Print the result
    printf("Result: %d\n", sum);

    return 0;
}