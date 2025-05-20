//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n);
void print_fibonacci_bar(int *fib, int n);

int main() {
    int n;

    // Get user input for how many Fibonacci numbers to display
    printf("Enter the number of Fibonacci numbers to generate: ");
    if(scanf("%d", &n) != 1 || n < 1 ) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    print_fibonacci(n);

    return 0;
}

void print_fibonacci(int n) {
    int *fib = (int*)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // First two Fibonacci numbers
    fib[0] = 0;
    if(n > 1) {
        fib[1] = 1;
    }

    // Generate Fibonacci numbers
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print Fibonacci numbers
    printf("\nGenerating Fibonacci Numbers:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Visualize Fibonacci numbers with bars
    printf("\nVisualizing the Fibonacci Sequence:\n\n");
    print_fibonacci_bar(fib, n);

    // Free the allocated memory
    free(fib);
}

void print_fibonacci_bar(int *fib, int n) {
    for(int i = 0; i < n; i++) {
        printf("%2d | ", fib[i]);

        int bar_length = fib[i] / 2; // Adjust bar scale
        for(int j = 0; j < bar_length; j++) {
            printf("■");
        }

        // Adding some irregular spacing for artistic effect
        if (i % 3 == 0 && i != 0) {
            printf("   <-- ");
        } else {
            printf("   ");
        }
        printf("\n");
    }

    printf("\nVisual Representation of Fibonacci Numbers\n");
    printf("■ represents the value of Fibonacci numbers divided by 2\n");
}