//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    int a = 5, b = 3;

    // Addition
    int sum = a + b;
    printf("a + b = %d\n", sum);

    // Subtraction
    int difference = a - b;
    printf("a - b = %d\n", difference);

    // Multiplication
    int product = a * b;
    printf("a * b = %d\n", product);

    // Division
    int quotient = a / b;
    printf("a / b = %d\n", quotient);

    // Modulus
    int remainder = a % b;
    printf("a %% b = %d\n", remainder);

    // Exponentiation
    double power = pow(a, b);
    printf("a ^ b = %f\n", power);

    // Bitwise AND
    int and = a & b;
    printf("a & b = %d\n", and);

    // Bitwise OR
    int or = a | b;
    printf("a | b = %d\n", or);

    // Bitwise XOR
    int xor = a ^ b;
    printf("a ^ b = %d\n", xor);

    // Bitwise NOT
    int not = ~a;
    printf("~a = %d\n", not);

    // Bitwise left shift
    int lshift = a << b;
    printf("a << b = %d\n", lshift);

    // Bitwise right shift
    int rshift = a >> b;
    printf("a >> b = %d\n", rshift);

    return 0;
}