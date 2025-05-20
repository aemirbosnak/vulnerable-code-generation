//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>

// Define the function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

// Define the function to calculate the difference between two numbers
int difference(int a, int b) {
    return a - b;
}

// Define the function to calculate the product of two numbers
int product(int a, int b) {
    return a * b;
}

// Define the function to calculate the quotient of two numbers
int quotient(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

// Define the function to calculate the remainder of two numbers
int remainder(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a % b;
}

// Define the function to calculate the power of two numbers
int power(int a, int b) {
    if (b < 0) {
        printf("Error: Negative exponent is not allowed.\n");
        return 0;
    }
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    int num1, num2;

    // Get input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate the sum, difference, product, quotient, and remainder
    int sum_result = sum(num1, num2);
    int diff_result = difference(num1, num2);
    int prod_result = product(num1, num2);
    int quot_result = quotient(num1, num2);
    int rem_result = remainder(num1, num2);

    // Calculate the power of the two numbers
    int pow_result = power(num1, num2);

    // Print the results
    printf("Sum: %d\n", sum_result);
    printf("Difference: %d\n", diff_result);
    printf("Product: %d\n", prod_result);
    printf("Quotient: %d\n", quot_result);
    printf("Remainder: %d\n", rem_result);
    printf("Power: %d\n", pow_result);

    return 0;
}