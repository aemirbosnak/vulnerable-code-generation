//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

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
        printf("Error! Division by zero is not allowed.\n");
        return -1;
    }
    return a / b;
}

// function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num1, num2, result;

    // addition
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = add(num1, num2);
    printf("The sum of %d and %d is %d.\n", num1, num2, result);

    // subtraction
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = subtract(num1, num2);
    printf("The difference between %d and %d is %d.\n", num1, num2, result);

    // multiplication
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = multiply(num1, num2);
    printf("The product of %d and %d is %d.\n", num1, num2, result);

    // division
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = divide(num1, num2);
    printf("The quotient of %d and %d is %d.\n", num1, num2, result);

    // factorial
    printf("Enter a number: ");
    scanf("%d", &num1);
    result = factorial(num1);
    printf("The factorial of %d is %d.\n", num1, result);

    return 0;
}