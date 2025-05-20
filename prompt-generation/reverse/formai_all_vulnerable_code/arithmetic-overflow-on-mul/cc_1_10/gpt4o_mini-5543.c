//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate Fibonacci series
void generate_fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to perform basic arithmetic operations
void basic_arithmetic_operations() {
    int num1, num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Choose an operator (+, -, *, /): ");
    scanf(" %c", &operator); // space before %c to consume any whitespace

    switch (operator) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %.2f\n", (float)num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Invalid operator!\n");
    }
}

// Function to display prime numbers in a given range
void display_primes(int range) {
    printf("Prime numbers up to %d:\n", range);
    for (int i = 2; i <= range; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Main program to interact with the user
int main() {
    int choice, range, fib_terms;

    printf("Welcome to the Math Explorer Program!\n");
    printf("Please choose an option:\n");
    printf("1. Prime Numbers\n");
    printf("2. Fibonacci Series\n");
    printf("3. Basic Arithmetic Operations\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the range to find prime numbers: ");
                scanf("%d", &range);
                display_primes(range);
                break;
            case 2:
                printf("Enter the number of Fibonacci terms: ");
                scanf("%d", &fib_terms);
                generate_fibonacci(fib_terms);
                break;
            case 3:
                basic_arithmetic_operations();
                break;
            case 4:
                printf("Thank you for using the Math Explorer Program! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 to 4.\n");
        }

        printf("\nWould you like to perform another operation? (1 for Yes, 0 for No): ");
        int continue_program;
        scanf("%d", &continue_program);
        if (continue_program == 0) {
            printf("Thank you for exploring with us! Goodbye!\n");
            break;
        }
    }

    return 0;
}