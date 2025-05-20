//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>

// Define a function to perform addition
int add(int x, int y) {
    return x + y;
}

// Define a function to perform subtraction
int subtract(int x, int y) {
    return x - y;
}

// Define a function to perform multiplication
int multiply(int x, int y) {
    return x * y;
}

// Define a function to perform division
int divide(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return x / y;
}

// Define a function to perform modulus
int modulus(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return x % y;
}

// Define a function to perform exponentiation
int exponentiate(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int num1, num2, result;

    // Prompt the user to enter two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Perform addition
    result = add(num1, num2);
    printf("Addition: %d\n", result);

    // Perform subtraction
    result = subtract(num1, num2);
    printf("Subtraction: %d\n", result);

    // Perform multiplication
    result = multiply(num1, num2);
    printf("Multiplication: %d\n", result);

    // Perform division
    result = divide(num1, num2);
    printf("Division: %d\n", result);

    // Perform modulus
    result = modulus(num1, num2);
    printf("Modulus: %d\n", result);

    // Perform exponentiation
    result = exponentiate(num1, num2);
    printf("Exponentiation: %d\n", result);

    return 0;
}