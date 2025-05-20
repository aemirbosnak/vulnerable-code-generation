//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE 0
#define MAX_VALUE 1000

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
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

    // Get the operation from the user (either +, -, *, or /)
    printf("Enter the operation (+, -, *, or /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}