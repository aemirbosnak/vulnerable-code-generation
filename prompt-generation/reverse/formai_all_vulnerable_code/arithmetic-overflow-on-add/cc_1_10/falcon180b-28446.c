//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

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
    if (b == 0) {
        printf("Error: Division by zero is not allowed\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the square of a number
int square(int a) {
    return a * a;
}

// Function to calculate the cube of a number
int cube(int a) {
    return a * a * a;
}

int main() {
    int a, b, c;

    // Prompt the user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Calculate the sum of the two numbers
    c = add(a, b);
    printf("The sum of %d and %d is %d\n", a, b, c);

    // Calculate the difference between the two numbers
    c = subtract(a, b);
    printf("The difference between %d and %d is %d\n", a, b, c);

    // Calculate the product of the two numbers
    c = multiply(a, b);
    printf("The product of %d and %d is %d\n", a, b, c);

    // Calculate the quotient of the two numbers
    c = divide(a, b);
    printf("The quotient of %d and %d is %d\n", a, b, c);

    // Calculate the square of a number
    c = square(a);
    printf("The square of %d is %d\n", a, c);

    // Calculate the cube of a number
    c = cube(a);
    printf("The cube of %d is %d\n", a, c);

    return 0;
}