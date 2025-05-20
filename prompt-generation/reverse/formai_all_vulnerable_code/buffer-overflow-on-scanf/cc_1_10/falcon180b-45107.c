//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Cryptic function to calculate the sum of two numbers
int cryptic_sum(int a, int b) {
    return ((a + b) & 0xff);
}

// Cryptic function to calculate the difference of two numbers
int cryptic_diff(int a, int b) {
    return ((a - b) & 0xff);
}

// Cryptic function to calculate the product of two numbers
int cryptic_prod(int a, int b) {
    return ((a * b) & 0xff);
}

// Cryptic function to calculate the quotient of two numbers
int cryptic_quot(int a, int b) {
    return ((a / b) & 0xff);
}

// Cryptic function to calculate the modulus of two numbers
int cryptic_mod(int a, int b) {
    return ((a % b) & 0xff);
}

int main() {
    int num1, num2, result;

    // Get input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate the sum, difference, product, quotient, and modulus
    result = cryptic_sum(num1, num2);
    printf("Sum: %d\n", result);

    result = cryptic_diff(num1, num2);
    printf("Difference: %d\n", result);

    result = cryptic_prod(num1, num2);
    printf("Product: %d\n", result);

    result = cryptic_quot(num1, num2);
    printf("Quotient: %d\n", result);

    result = cryptic_mod(num1, num2);
    printf("Modulus: %d\n", result);

    return 0;
}