//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

// Function declarations
int factorial(int n);
int fibonacci(int n);
void print_fibonacci_series(int n);
int sum_of_digits(int n);
void print_prime_factors(int n);
void print_identifying_primes(int n, int divisor);

// Main function
int main() {
    int choice, num;

    printf("Math Functions Recursive Program\n");
    printf("--------------------------------\n");
    printf("1. Calculate Factorial\n");
    printf("2. Fibonacci Series\n");
    printf("3. Sum of Digits\n");
    printf("4. Prime Factors\n");
    printf("5. Exit\n");
    
    while (1) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to compute its factorial: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d is %d\n", num, factorial(num));
                }
                break;

            case 2:
                printf("Enter the number of terms in the Fibonacci series: ");
                scanf("%d", &num);
                print_fibonacci_series(num);
                break;

            case 3:
                printf("Enter a number to calculate the sum of its digits: ");
                scanf("%d", &num);
                printf("Sum of digits of %d is %d\n", num, sum_of_digits(num));
                break;

            case 4:
                printf("Enter a number to find its prime factors: ");
                scanf("%d", &num);
                printf("Prime factors of %d are: ", num);
                print_prime_factors(num);
                printf("\n");
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
        printf("--------------------------------\n");
    }
}

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print Fibonacci series
void print_fibonacci_series(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to calculate the sum of digits
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum_of_digits(n / 10);
}

// Function to print prime factors
void print_prime_factors(int n) {
    if (n <= 1) {
        return;
    }
    // Print number of 2s that divide n
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    // n must be odd at this point. So we can skip one element (i.e., we can check i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    // This condition is to check if n is a prime number greater than 2
    if (n > 2) {
        printf("%d ", n);
    }
}