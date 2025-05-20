//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to perform addition
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to perform subtraction
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to perform multiplication
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to perform division
int divide(int num1, int num2) {
    return num1 / num2;
}

// Function to perform modulus
int modulus(int num1, int num2) {
    return num1 % num2;
}

// Function to perform power
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to perform factorial
int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num1, num2;
    char operation;

    // Get user input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /, %, ^,!): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation
    switch (operation) {
        case '+':
            printf("The result is: %d\n", add(num1, num2));
            break;
        case '-':
            printf("The result is: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("The result is: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("The result is: %d\n", divide(num1, num2));
            break;
        case '%':
            printf("The result is: %d\n", modulus(num1, num2));
            break;
        case '^':
            printf("The result is: %d\n", power(num1, num2));
            break;
        case '!':
            printf("The result is: %d\n", factorial(num1));
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}