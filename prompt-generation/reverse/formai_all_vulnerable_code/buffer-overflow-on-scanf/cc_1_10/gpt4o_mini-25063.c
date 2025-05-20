//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n, long long* fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void visualizeFibonacci(int n, long long* fib) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        // Print spaces for better visualization
        for (int j = 0; j < fib[i] / 5; j++) {
            printf(" ");
        }
        printf("*"); // Print asterisk for current Fibonacci number
        printf(" (%lld)\n", fib[i]); // Print the value of the Fibonacci number

        if (i == n - 1) {
            printf("Completed Fibonacci sequence up to %d numbers.\n", n);
            printf("Press Enter to exit...");
            getchar(); // Wait for user input to exit
        }
    }
}

int main() {
    int n;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci numbers to generate and visualize: ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    long long* fib = (long long*)malloc(n * sizeof(long long));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);

    free(fib); // Free allocated memory
    return EXIT_SUCCESS;
}