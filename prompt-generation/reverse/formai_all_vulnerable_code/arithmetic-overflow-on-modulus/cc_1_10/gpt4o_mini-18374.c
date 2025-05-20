//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Function to compute factorial of a number recursively
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to compute the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to compute the greatest common divisor (GCD) recursively
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute the sum of digits of a number recursively
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum_of_digits(n / 10);
}

// Function to compute the power of a number recursively
double power(double base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

// Function to generate Pascal's triangle recursively
void print_pascals_triangle(int rows, int current_row) {
    if (current_row == rows) {
        return;
    }
    int current_value = 1;
    for (int i = 0; i < current_row; i++) {
        printf("%d ", current_value);
        current_value = current_value * (current_row - i) / (i + 1);
    }
    printf("\n");
    print_pascals_triangle(rows, current_row + 1);
}

// Function to calculate the combination (n choose k) recursively
int combination(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

// Function to check if a number is prime recursively
int is_prime(int n, int divisor) {
    if (n <= 2) {
        return (n == 2) ? 1 : 0;
    }
    if (n % divisor == 0) {
        return 0;
    }
    if (divisor * divisor > n) {
        return 1;
    }
    return is_prime(n, divisor + 1);
}

// Main function to demonstrate various recursive mathematical functions
int main() {
    int number, exp, rows;

    // Factorial Calculation
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &number);
    printf("Factorial of %d is %llu\n", number, factorial(number));

    // Fibonacci Calculation
    printf("Enter a number to find Fibonacci: ");
    scanf("%d", &number);
    printf("Fibonacci of %d is %d\n", number, fibonacci(number));

    // GCD Calculation
    int num1, num2;
    printf("Enter two numbers to find GCD: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    // Sum of Digits Calculation
    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &number);
    printf("Sum of digits of %d is %d\n", number, sum_of_digits(number));

    // Power Calculation
    double base;
    printf("Enter base and exponent to calculate base^exponent: ");
    scanf("%lf %d", &base, &exp);
    printf("%lf raised to the power of %d is %lf\n", base, exp, power(base, exp));

    // Print Pascal's Triangle
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &rows);
    printf("Pascal's Triangle with %d rows:\n", rows);
    print_pascals_triangle(rows, 0);

    // Combination Calculation
    int n, k;
    printf("Enter n and k to calculate n choose k: ");
    scanf("%d %d", &n, &k);
    printf("Combination of %d choose %d is %d\n", n, k, combination(n, k));

    // Prime Check
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &number);
    if (is_prime(number, 2)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}