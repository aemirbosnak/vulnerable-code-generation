//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void print_visualization(int fib[], int count) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < count; ++i) {
        printf("%10d: ", fib[i]);
        for (int j = 0; j < fib[i] / 5; ++j) { // Scale for visualization
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int limit, *fib, count = 0;

    printf("Enter the maximum value for Fibonacci numbers (positive integer): ");
    
    // Validate input
    while (1) {
        if (scanf("%d", &limit) != 1 || limit <= 0) {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        break;
    }

    // Dynamic memory allocation for Fibonacci numbers
    fib = (int *)malloc(sizeof(int) * limit);
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generating Fibonacci sequence
    int a = 0, b = 1, next;
    
    if (limit >= 0) {
        fib[count++] = a;
    }
    if (limit >= 1) {
        fib[count++] = b;
    }

    while (1) {
        next = a + b;
        if (next > limit) {
            break;
        }
        fib[count++] = next;
        a = b;
        b = next;
    }

    // Print Fibonacci numbers
    printf("\nFibonacci numbers up to %d:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Print Visualization
    print_visualization(fib, count);

    // Free allocated memory
    free(fib);

    return 0;
}