//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int num1, num2, result;
    char operation;

    printf("Enter two numbers: ");
    scanf("%d %c %d", &num1, &operation, &num2);

    switch(operation) {
        case '+':
            result = add(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if(b == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}