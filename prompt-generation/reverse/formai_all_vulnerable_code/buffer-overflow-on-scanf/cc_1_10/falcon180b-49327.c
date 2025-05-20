//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a function to calculate the sum of two numbers
int add(int a, int b) {
    return a + b;
}

// Define a function to calculate the difference between two numbers
int subtract(int a, int b) {
    return a - b;
}

// Define a function to calculate the product of two numbers
int multiply(int a, int b) {
    return a * b;
}

// Define a function to calculate the quotient of two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

// Define a function to calculate the remainder of two numbers
int modulus(int a, int b) {
    return a % b;
}

// Define a function to calculate the power of two numbers
int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    
    // Prompt the user to enter two numbers
    printf("Enter the first number: ");
    int num1 = scanf("%d", &num1);
    printf("Enter the second number: ");
    int num2 = scanf("%d", &num2);

    // Calculate the sum of the two numbers
    int sum = add(num1, num2);
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    // Calculate the difference between the two numbers
    int diff = subtract(num1, num2);
    printf("The difference between %d and %d is %d.\n", num1, num2, diff);

    // Calculate the product of the two numbers
    int prod = multiply(num1, num2);
    printf("The product of %d and %d is %d.\n", num1, num2, prod);

    // Calculate the quotient of the two numbers
    int quot = divide(num1, num2);
    printf("The quotient of %d and %d is %d.\n", num1, num2, quot);

    // Calculate the remainder of the two numbers
    int rem = modulus(num1, num2);
    printf("The remainder of %d divided by %d is %d.\n", num1, num2, rem);

    // Calculate the power of the two numbers
    int pow = power(num1, num2);
    printf("The result of %d raised to the power of %d is %d.\n", num1, num2, pow);

    return 0;
}