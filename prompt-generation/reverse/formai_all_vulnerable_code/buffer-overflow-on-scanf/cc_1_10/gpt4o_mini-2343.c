//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>

void printFibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print Fibonacci numbers with visualization
    printf("\nFibonacci Sequence Visualizer:\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%2d: %2d ", i, fib[i]);
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("1. Generate Fibonacci Sequence\n");
    printf("2. Exit\n");
}

int main() {
    int choice, terms;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms to generate (e.g., 10): ");
                scanf("%d", &terms);
                if (terms < 2) {
                    printf("Please enter a number greater than or equal to 2.\n");
                } else {
                    printFibonacci(terms);
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