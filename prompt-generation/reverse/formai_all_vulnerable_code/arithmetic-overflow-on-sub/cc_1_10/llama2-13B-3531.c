//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MOD 1000003

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Function to calculate the modular inverse of a number
int mod_inv(int a, int n) {
    int r = 0;
    while (n != 0) {
        r = (r * a) % n;
        n /= 10;
    }
    return r;
}

int main() {
    int num1, num2, sum, diff, product, quotient, remainder;
    char operation;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            product = num1 * num2;
            break;
        case '/':
            quotient = num1 / num2;
            remainder = num1 % num2;
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Calculate the result modulo MOD
    switch (operation) {
        case '+':
            sum = (sum % MOD) + (num2 % MOD);
            break;
        case '-':
            diff = (diff % MOD) + (num2 % MOD);
            break;
        case '*':
            product = (product % MOD) + (num2 % MOD);
            break;
        case '/':
            quotient = (quotient % MOD) + (num2 % MOD);
            remainder = (remainder % MOD);
            break;
    }

    // Print the result
    printf("Result: %d\n", sum);

    return 0;
}