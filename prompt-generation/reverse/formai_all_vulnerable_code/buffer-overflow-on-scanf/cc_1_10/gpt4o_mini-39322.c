//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

// Function to compute the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case for Fibonacci
    } else if (n == 1) {
        return 1; // Base case for Fibonacci
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

// Function to compute the factorial of a number recursively
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    } else if (n == 0 || n == 1) {
        return 1; // Base cases for factorial
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int choice, number;
    
    printf("Welcome to the Recursive Function Calculator!\n");
    printf("Please select an option:\n");
    printf("1. Calculate Fibonacci number\n");
    printf("2. Calculate Factorial\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You selected Fibonacci.\n");
            printf("Enter a non-negative integer for Fibonacci calculation: ");
            scanf("%d", &number);
            if (number < 0) {
                printf("Invalid input! Please enter a non-negative integer.\n");
            } else {
                printf("Fibonacci(%d) = %d\n", number, fibonacci(number));
            }
            break;
        case 2:
            printf("You selected Factorial.\n");
            printf("Enter a non-negative integer for Factorial calculation: ");
            scanf("%d", &number);
            int result = factorial(number);
            if (result == -1) {
                printf("Invalid input! Factorial is not defined for negative integers.\n");
            } else {
                printf("%d! = %d\n", number, result);
            }
            break;
        default:
            printf("Invalid choice! Please select either 1 or 2.\n");
            break;
    }
    
    printf("Thank you for using the Recursive Function Calculator.\n");
    return 0;
}