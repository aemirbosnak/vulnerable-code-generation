//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void find_prime_numbers(int limit);
void generate_fibonacci(int n);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int choice, limit, n, a, b;

    while (1) {
        printf("\nWelcome to the Math Exploration Program!\n");
        printf("Please choose an option:\n");
        printf("1. Find Prime Numbers\n");
        printf("2. Generate Fibonacci Sequence\n");
        printf("3. Basic Arithmetic Operations\n");
        printf("4. Exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a limit to find prime numbers: ");
                scanf("%d", &limit);
                find_prime_numbers(limit);
                break;

            case 2:
                printf("How many Fibonacci numbers do you want to generate? ");
                scanf("%d", &n);
                generate_fibonacci(n);
                break;

            case 3:
                printf("Enter two numbers for arithmetic operations:\n");
                printf("First number: ");
                scanf("%d", &a);
                printf("Second number: ");
                scanf("%d", &b);
                printf("Addition: %d + %d = %d\n", a, b, add(a, b));
                printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
                printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
                if (b != 0) {
                    printf("Division: %d / %d = %.2f\n", a, b, divide(a, b));
                } else {
                    printf("Cannot divide by zero!\n");
                }
                break;

            case 4:
                printf("Thank you for using the Math Exploration Program! Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void find_prime_numbers(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        bool is_prime = true;

        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void generate_fibonacci(int n) {
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }
    printf("Fibonacci sequence of first %d numbers:\n", n);
    int t1 = 0, t2 = 1, nextTerm;

    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

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
    return (float)a / b;
}