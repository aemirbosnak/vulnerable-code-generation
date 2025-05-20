//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

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
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

int main() {
    int num1, num2, result;
    char operation;

    // get input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // perform operation based on user input
    switch(operation) {
        case '+':
            result = add(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("The result is: %d\n", result);
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }

    return 0;
}