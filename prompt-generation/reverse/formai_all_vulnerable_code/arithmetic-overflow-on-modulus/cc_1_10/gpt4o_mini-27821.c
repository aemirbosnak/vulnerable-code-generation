//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>

// Function to calculate Fibonacci recursively
int fibonacci(int n) {
    if (n <= 1) 
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate Factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to generate Fibonacci sequence and print it
void generate_fibonacci_sequence(int terms) {
    printf("Fibonacci Sequence up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to illustrate recursive multiplication
int multiply(int a, int b) {
    if (b == 0) 
        return 0;
    return a + multiply(a, b - 1);
}

// Function to calculate the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Helper function to demonstrate the power of a number recursively
double power(double base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    int terms, number, a, b;
    double base;
    int exponent;

    // Get number of Fibonacci terms from user
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &terms);
    generate_fibonacci_sequence(terms);

    // Get number for factorial calculation
    printf("Enter a positive integer for factorial calculation: ");
    scanf("%d", &number);
    printf("Factorial of %d is: %d\n", number, factorial(number));

    // Get two numbers to find GCD
    printf("Enter two integers to find their GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is: %d\n", a, b, gcd(a, b));

    // Get base and exponent for power calculation
    printf("Enter base and exponent for power calculation (base exponent): ");
    scanf("%lf %d", &base, &exponent);
    printf("%.2lf to the power of %d is: %.2lf\n", base, exponent, power(base, exponent));
    
    // Demonstrating multiplication using recursion
    printf("Enter two numbers to multiply (num1 num2): ");
    scanf("%d %d", &a, &b);
    printf("%d multiplied by %d is: %d\n", a, b, multiply(a, b));

    return 0;
}