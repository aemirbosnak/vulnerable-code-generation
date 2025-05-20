//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSequence(int terms) {
    printf("Fibonacci sequence up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
}

int calculateFibonacciAtPosition(int position) {
    return fibonacci(position);
}

void interactiveMenu() {
    int choice, terms, position;

    do {
        printf("\nFibonacci Sequence Calculator\n");
        printf("1. Print Fibonacci sequence up to N terms\n");
        printf("2. Calculate Fibonacci number at specific position\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms: ");
                scanf("%d", &terms);
                printFibonacciSequence(terms);
                break;
            case 2:
                printf("Enter the position (0-indexed): ");
                scanf("%d", &position);
                if (position < 0) {
                    printf("Position must be a non-negative integer.\n");
                } else {
                    printf("Fibonacci number at position %d is %llu\n", position, calculateFibonacciAtPosition(position));
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3);
}

int main() {
    interactiveMenu();
    return 0;
}