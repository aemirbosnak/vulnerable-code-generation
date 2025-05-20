//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>

// Function to find factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Oops! Factorial is not defined for negative numbers.\n");
        return 0; // Factorial not defined for negative numbers
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to find Fibonacci number using recursion
int fibonacci(int n) {
    if (n < 0) {
        printf("Oops! Fibonacci is not defined for negative numbers.\n");
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci series
void printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Main function with a touch of user interaction
int main() {
    int choice, num;

    printf("💥 Welcome to the Exciting Recursive Calculator! 💥\n");
    printf("Choose an option:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Find Fibonacci Series\n");
    printf("3. Exit\n");
    
    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a non-negative integer for factorial: ");
                scanf("%d", &num);
                printf("Calculating Factorial of %d...\n", num);
                unsigned long long fact = factorial(num);
                if (num >= 0)
                    printf("The factorial of %d is %llu\n", num, fact);
                break;

            case 2:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &num);
                printFibonacciSeries(num);
                break;

            case 3:
                printf("Thank you for using the Exciting Recursive Calculator! 🚀\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        
        printf("\n✨ Would you like to perform another calculation? (1: Yes, 2: No): ");
        scanf("%d", &choice);
        if (choice != 1) {
            printf("Thank you for using our calculator! Have a great day! 🌟\n");
            break;
        }
    }
    
    return 0;
}