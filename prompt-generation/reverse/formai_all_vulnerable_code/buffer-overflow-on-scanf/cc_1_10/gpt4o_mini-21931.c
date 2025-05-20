//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, unsigned long long *fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci numbers
void visualizeFibonacci(int n, unsigned long long *fib) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("Index\tValue\tVisualization\n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%llu\t", i, fib[i]);
        
        // Adjust scale for visualization (limit the visual output)
        int scale = fib[i] / 100000; // Divide by a constant factor to fit into the console
        
        for (int j = 0; j < scale; j++) {
            printf("#");
        }
        
        printf("\n");
        sleep(1); // Slow down the output to improve visualization
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Check if the number of Fibonacci numbers is valid
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for Fibonacci sequence
    unsigned long long *fib = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Generate and visualize the Fibonacci sequence
    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);

    // Free allocated memory
    free(fib);
    return 0;
}