//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// function to add two numbers recursively
int add(int a, int b) {
    if (b == 0) {
        return a;
    }
    return add(a + 1, b - 1);
}

// function to multiply two numbers recursively
int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b == 1) {
        return a;
    }
    return a + multiply(a, b - 1);
}

// function to subtract two numbers recursively
int subtract(int a, int b) {
    if (b == 0) {
        return a;
    }
    return subtract(a - 1, b + 1);
}

// function to divide two numbers recursively
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    if (a == 0) {
        return 0;
    }
    if (a < b) {
        return 0;
    }
    return divide(a - b, b) + 1;
}

int main() {
    int num1, num2, result;
    char operation;

    // prompt user to enter two numbers and an operation
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // perform the arithmetic operation recursively
    switch (operation) {
        case '+':
            result = add(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("The result is %d.\n", result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}