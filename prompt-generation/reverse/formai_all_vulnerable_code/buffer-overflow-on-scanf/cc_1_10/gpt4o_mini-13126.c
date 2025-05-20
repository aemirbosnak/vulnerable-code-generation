//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to display menu
void displayMenu() {
    printf("\n***** Welcome to the Exciting Math Adventure! *****\n");
    printf("1. Calculate Factorial\n");
    printf("2. Generate Random Prime Numbers\n");
    printf("3. Calculate Fibonacci Series\n");
    printf("4. Exit\n");
    printf("********************************************\n");
    printf("Please choose an option (1-4): ");
}

// Function to calculate factorial
long long int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0; 
    }
    return 1;
}

// Function to generate random prime numbers
void generateRandomPrimes(int count) {
    srand(time(NULL));
    int number, found = 0;
    printf("\nGenerated Random Prime Numbers: ");
    while (found < count) {
        number = rand() % 100 + 1; // Random number between 1 and 100
        if (isPrime(number)) {
            printf("%d ", number);
            found++;
        }
    }
    printf("\n");
}

// Function to calculate Fibonacci series
void fibonacciSeries(int n) {
    int a = 0, b = 1, next;
    printf("\nFibonacci Series up to %d terms: \n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int choice, n;

    // Main program loop
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Factorial is not defined for negative numbers!\n");
                } else {
                    printf("Factorial of %d is %lld\n", n, factorial(n));
                }
                break;
            case 2:
                printf("How many random prime numbers would you like to generate? ");
                scanf("%d", &n);
                generateRandomPrimes(n);
                break;
            case 3:
                printf("How many terms of the Fibonacci series do you want? ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Please enter a positive integer!\n");
                } else {
                    fibonacciSeries(n);
                }
                break;
            case 4:
                printf("Thank you for joining the Exciting Math Adventure! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option (1-4).\n");
        }
    }
    
    return 0;
}