//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 0) {
        return 0; // Fibonacci of 0
    } else if (n == 1) {
        return 1; // Fibonacci of 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

// Function to display the Fibonacci sequence up to the n-th number
void displayFibonacci(int n) {
    printf("Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to display options
void displayMenu() {
    printf("\n--- Fibonacci Sequence Generator ---\n");
    printf("1. Generate Fibonacci Sequence\n");
    printf("2. Exit\n");
    printf("-------------------------------------\n");
    printf("Enter your choice: ");
}

// Main function to run the program
int main() {
    int choice, terms;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms to generate: ");
                scanf("%d", &terms);
                if (terms < 0) {
                    printf("Please enter a positive integer.\n");
                } else {
                    displayFibonacci(terms);
                }
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}