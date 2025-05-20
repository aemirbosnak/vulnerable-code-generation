//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void do_math(int num1, int num2, int *result) {
    int sum = 0;
    int product = 1;
    int square = 0;
    int square_root = 0;

    // Addition
    sum = num1 + num2;
    printf("Addition: %d + %d = %d\n", num1, num2, sum);

    // Subtraction
    sum = num1 - num2;
    printf("Subtraction: %d - %d = %d\n", num1, num2, sum);

    // Multiplication
    product = num1 * num2;
    printf("Multiplication: %d * %d = %d\n", num1, num2, product);

    // Division
    product = num1 / num2;
    printf("Division: %d / %d = %d\n", num1, num2, product);

    // Modulus
    product = fmod(num1, num2);
    printf("Modulus: %d %c %d = %d\n", num1, '(', num2, ')', product);

    // Square
    square = num1 * num1;
    printf("Square: %d^2 = %d\n", num1, square);

    // Square Root
    square_root = sqrt(square);
    printf("Square Root: %d^2 = %d\n", square, square_root);

    // Magic Number
    printf("Magic Number: %d\n", MAGIC_NUMBER);

    // Result
    *result = sum;
}

int main() {
    int num1, num2, result;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Call the do_math function
    do_math(num1, num2, &result);

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}