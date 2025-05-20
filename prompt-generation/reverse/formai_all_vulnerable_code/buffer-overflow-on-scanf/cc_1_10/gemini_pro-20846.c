//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inspired by the golden ratio and the Fibonacci sequence, this program visualizes the beauty of nature. 

// Function to generate the next Fibonacci number.
long long fibonacci(int n) 
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print a Fibonacci spiral.
void fibonacci_spiral(int n) 
{
    int i, j, k;
    long long fib;
    
    // Allocate memory for the spiral.
    int **spiral = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        spiral[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Initialize the spiral with zeros.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            spiral[i][j] = 0;
        }
    }
    
    // Set the starting point of the spiral.
    i = n / 2;
    j = n / 2;

    // Generate the Fibonacci spiral.
    for (k = 0; k < n * n; k++) {
        // Get the next Fibonacci number.
        fib = fibonacci(k);

        // Place the Fibonacci number in the spiral.
        spiral[i][j] = fib;

        // Move to the next position in the spiral.
        i += (fib % 2) * (1 - 2 * (k % 2));
        j += (1 - fib % 2) * (1 - 2 * (k % 2));

        // Wrap around the spiral if necessary.
        if (i < 0) {
            i += n;
        } else if (i >= n) {
            i -= n;
        }
        if (j < 0) {
            j += n;
        } else if (j >= n) {
            j -= n;
        }
    }
    
    // Print the Fibonacci spiral.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", spiral[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory allocated for the spiral.
    for (i = 0; i < n; i++) {
        free(spiral[i]);
    }
    free(spiral);
}

int main() {
    int n;

    printf("Enter the size of the Fibonacci spiral: ");
    scanf("%d", &n);

    // Generate and print the Fibonacci spiral.
    fibonacci_spiral(n);

    return 0;
}