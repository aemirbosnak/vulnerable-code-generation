//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int power(int base, int exp);
int factorial(int n);
int is_prime(int n);

int main() {
    int choice, a, b;

    printf("Welcome to the Amazing Arithmetic Adventure!\n");
    printf("Get ready to blast-off with numbers!\n");
    
    while (1) {
        printf("\nChoose an operation to perform (1-8):\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Check Prime\n");
        printf("8. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        // Handle user choices
        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d %d", &a, &b);
                printf("%d + %d = %d\n", a, b, add(a, b));
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &a, &b);
                printf("%d - %d = %d\n", a, b, subtract(a, b));
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &a, &b);
                printf("%d * %d = %d\n", a, b, multiply(a, b));
                break;
            case 4:
                printf("Enter two numbers for division (numerator denominator): ");
                scanf("%d %d", &a, &b);
                if (b != 0) {
                    printf("%d / %d = %.2f\n", a, b, divide(a, b));
                } else {
                    printf("Error: Division by zero is undefined!\n");
                }
                break;
            case 5:
                printf("Enter base and exponent (base exp): ");
                scanf("%d %d", &a, &b);
                printf("%d^%d = %d\n", a, b, power(a, b));
                break;
            case 6:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &a);
                if (a >= 0) {
                    printf("%d! = %d\n", a, factorial(a));
                } else {
                    printf("Error: Factorial of a negative number is undefined!\n");
                }
                break;
            case 7:
                printf("Enter a number to check if it's prime: ");
                scanf("%d", &a);
                if (is_prime(a)) {
                    printf("%d is a prime number!\n", a);
                } else {
                    printf("%d is not a prime number.\n", a);
                }
                break;
            case 8:
                printf("Thank you for using the Amazing Arithmetic Adventure! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}

// Function implementations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / (float)b;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int is_prime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;  // Found a divisor, not prime
        }
    }
    return 1; // No divisors found, it is prime
}