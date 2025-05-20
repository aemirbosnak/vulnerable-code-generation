//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of two numbers
int sum(int num1, int num2) {
    return num1 + num2;
}

// Function to calculate the difference of two numbers
int difference(int num1, int num2) {
    return num1 - num2;
}

// Function to calculate the product of two numbers
int product(int num1, int num2) {
    return num1 * num2;
}

// Function to calculate the quotient of two numbers
int quotient(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return num1 / num2;
}

// Function to calculate the modulo of two numbers
int modulo(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return num1 % num2;
}

int main() {
    int num1, num2;

    // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate and display the sum of the two numbers
    printf("The sum of %d and %d is %d.\n", num1, num2, sum(num1, num2));

    // Calculate and display the difference of the two numbers
    printf("The difference between %d and %d is %d.\n", num1, num2, difference(num1, num2));

    // Calculate and display the product of the two numbers
    printf("The product of %d and %d is %d.\n", num1, num2, product(num1, num2));

    // Calculate and display the quotient of the two numbers
    printf("The quotient of %d and %d is %d.\n", num1, num2, quotient(num1, num2));

    // Calculate and display the modulo of the two numbers
    printf("The modulo of %d and %d is %d.\n", num1, num2, modulo(num1, num2));

    return 0;
}