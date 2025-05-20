//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    // Initialize the first two Fibonacci numbers
    unsigned long long f1 = 0, f2 = 1, next;

    printf("Fibonacci Sequence up to %d terms:\n", n);

    // Print the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            // Print f1 and f2 for the first two terms
            printf("%llu ", i);
        } else {
            // Calculate the next term
            next = f1 + f2;
            f1 = f2;
            f2 = next;
            printf("%llu ", next);
        }
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    unsigned long long f1 = 0, f2 = 1, next;
    printf("\nVisualizing Fibonacci Sequence:\n");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = f1 + f2;
            f1 = f2;
            f2 = next;
        }

        // Visualization: the number of asterisks equal to the Fibonacci number
        printf("%llu: ", next);
        for (unsigned long long j = 0; j < next; j++) {
            printf("*");
            if (j % 50 == 49) { // New line after 50 asterisks
                printf("\n       ");
            }
        }
        printf("\n");
    }
}

int main() {
    int terms;

    printf("Enter the number of terms in the Fibonacci sequence you want to visualize: ");
    scanf("%d", &terms);

    if (terms < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Print the Fibonacci sequence
    printFibonacci(terms);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(terms);

    return 0;
}