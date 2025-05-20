//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0) { 
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Function to calculate fibonacci series using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate sum of n natural numbers using recursion
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n + sum(n - 1);
    }
}

// Main function
int main() {
    int choice, n, i;
    do {
        printf("\nSelect an option:"
            "\n1. Calculate factorial"
            "\n2. Calculate fibonacci series"
            "\n3. Calculate sum of n natural numbers"
            "\n4. Exit"
            "\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a positive integer: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        case 2:
            printf("Enter the number of terms in fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci series: ");
            for (i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
        case 3:
            printf("Enter a positive integer: ");
            scanf("%d", &n);
            printf("Sum of first %d natural numbers is %d\n", n, sum(n));
            break;
        case 4:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}