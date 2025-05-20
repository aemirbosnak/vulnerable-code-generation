//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Function to add two numbers */
int add(int a, int b) {
    return a + b;
}

/* Function to subtract two numbers */
int subtract(int a, int b) {
    return a - b;
}

/* Function to multiply two numbers */
int multiply(int a, int b) {
    return a * b;
}

/* Function to divide two numbers */
int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

int main() {
    int num1, num2, result;
    char operation;

    /* Prompt the user to enter two numbers and an operation */
    printf("Enter two numbers and an operation (+, -, *, /): ");
    scanf("%d %c %d", &num1, &operation, &num2);

    /* Perform the operation and print the result */
    switch (operation) {
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
            fprintf(stderr, "Error: Invalid operation.\n");
            exit(1);
    }

    /* Print the result */
    printf("Result: %d\n", result);

    return 0;
}