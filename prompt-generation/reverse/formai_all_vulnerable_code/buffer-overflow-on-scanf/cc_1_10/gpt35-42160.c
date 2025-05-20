//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int choice, n, base, exponent, a, b;
    printf("Welcome to the recursion program!\n");
    printf("1. Factorial of a number.\n");
    printf("2. Power function.\n");
    printf("3. Fibonacci term.\n");
    printf("4. GCD of two numbers.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;

        case 2:
            printf("Enter base and exponent: ");
            scanf("%d %d", &base, &exponent);
            printf("%d to the power of %d is %d\n", base, exponent, power(base, exponent));
            break;

        case 3:
            printf("Enter the term number: ");
            scanf("%d", &n);
            printf("The %dth Fibonacci term is %d\n", n, fibonacci(n));
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}