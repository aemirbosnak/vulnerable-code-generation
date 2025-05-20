//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void greetUser() {
    printf("Welcome to the Curious Math Adventure!\n");
    printf("Today, you'll embark on a journey through numbers.\n");
    printf("Choose wisely, dear traveler!\n\n");
}

void displayMenu() {
    printf("Choose an operation:\n");
    printf("1. Check for Prime\n");
    printf("2. Calculate Factorial\n");
    printf("3. Generate Fibonacci Sequence\n");
    printf("4. Exit\n");
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long factorial(int n) {
    if (n < 0) return -1;  // Invalid
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void generateFibonacci(int terms) {
    long long t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Sequence:\n");
    for (int i = 1; i <= terms; ++i) {
        printf("%lld, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("...\n");
}

int main() {
    int choice, number, terms;

    greetUser();

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Check for Prime
                printf("Enter a number to check for prime: ");
                scanf("%d", &number);
                if (isPrime(number)) {
                    printf("%d is a prime number!\n\n", number);
                } else {
                    printf("%d is not a prime number.\n\n", number);
                }
                break;
            case 2: // Calculate Factorial
                printf("Enter a non-negative integer to calculate factorial: ");
                scanf("%d", &number);
                long long fact = factorial(number);
                if (fact != -1) {
                    printf("Factorial of %d is %lld\n\n", number, fact);
                } else {
                    printf("Invalid input! Factorial is not defined for negative numbers.\n\n");
                }
                break;
            case 3: // Generate Fibonacci Sequence
                printf("Enter how many terms of the Fibonacci sequence you want: ");
                scanf("%d", &terms);
                generateFibonacci(terms);
                break;
            case 4: // Exit
                printf("Thank you for joining the Curious Math Adventure! Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n\n");
        }
    }

    return 0;
}