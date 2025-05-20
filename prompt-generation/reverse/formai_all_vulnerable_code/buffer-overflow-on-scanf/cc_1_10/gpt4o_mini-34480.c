//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

// Function to generate Fibonacci numbers and print them with visual representation
void generateFibonacci(int limit) {
    int first = 0, second = 1, next;
    printf("Fibonacci Sequence (up to %d):\n", limit);
    
    // Printing the first two Fibonacci numbers, special handling for the first element
    printf("%d: ", first);
    for (int i = 0; i < first; i++) {
        printf("*");
    }
    printf("\n");
    
    if (limit > 0) {
        printf("%d: ", second);
        for (int i = 0; i < second; i++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Generating and printing the subsequent Fibonacci numbers
    while (1) {
        next = first + second;

        // Break if the next Fibonacci number exceed the limit
        if (next > limit) {
            break;
        }

        printf("%d: ", next);
        for (int i = 0; i < next; i++) {
            printf("*");
        }
        printf("\n");

        // Update for next iteration
        first = second;
        second = next;
    }
}

int main() {
    int limit;

    // Asking user for input limit for the Fibonacci sequence
    printf("Enter the maximum limit for Fibonacci Sequence: ");
    scanf("%d", &limit);

    // Error handling for non-positive limit
    if (limit < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Generate and visualize the Fibonacci sequence
    generateFibonacci(limit);

    return 0;
}