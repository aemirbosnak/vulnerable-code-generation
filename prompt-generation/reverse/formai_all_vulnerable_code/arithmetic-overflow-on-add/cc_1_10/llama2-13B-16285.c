//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INTEGER 1000000
#define MAX_DECIMAL 10000000

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function to calculate the least common multiple of two integers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int num1, num2, result;
    char operation;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (either +, -, *, or /)
    printf("Enter the operation (+, -, *, or /): ");
    scanf(" %c", &operation);

    // Perform the operation
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    } else {
        printf("Invalid operation. Please enter a valid operation (+, -, *, or /).\n");
        return 1;
    }

    // Check if the result is an integer or not
    if (result % 1 == 0) {
        printf("The result is an integer: %d\n", result);
    } else {
        printf("The result is not an integer: %f\n", result);
    }

    return 0;
}