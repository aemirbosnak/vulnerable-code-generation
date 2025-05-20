//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// main function
int main() {
    int num1, num2, result;
    char operation;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    switch(operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operation entered.\n");
            return 0;
    }

    printf("Result: %d\n", result);

    return 0;
}

// function to add two numbers
int add(int a, int b) {
    return a + b;
}

// function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}