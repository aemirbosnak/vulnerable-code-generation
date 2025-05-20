//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

// Function to calculate Fibonacci of n
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate factorial of n
long factorial(int n) {
    if (n < 0) {
        printf("Factorial doesn't exist for negative numbers.\n");
        return -1; // Indicates an error
    }
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to print the Fibonacci series up to n terms
void print_fibonacci_series(int terms) {
    printf("\nFibonacci Series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to print the factorial of numbers up to n
void print_factorial_series(int terms) {
    printf("\nFactorial values up to %d:\n", terms);
    for (int i = 0; i <= terms; i++) {
        long fact = factorial(i);
        if (fact != -1) { // Avoid printing an error
            printf("%d! = %ld\n", i, fact);
        }
    }
}

// Main function
int main() {
    int choice, terms;

    // User menu
    do {
        printf("\nMathematical Function Calculator using Recursion\n");
        printf("1. Fibonacci Series\n");
        printf("2. Factorial\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms for Fibonacci Series: ");
                scanf("%d", &terms);
                print_fibonacci_series(terms);
                break;

            case 2:
                printf("Enter the number to calculate factorial: ");
                scanf("%d", &terms);
                print_factorial_series(terms);
                break;

            case 3:
                printf("Exiting... Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}