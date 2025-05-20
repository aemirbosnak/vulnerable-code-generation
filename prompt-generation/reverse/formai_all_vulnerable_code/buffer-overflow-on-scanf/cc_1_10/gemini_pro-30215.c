//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to be benchmarked
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function
int main()
{
    // Initialize variables
    int n, i, j, k;
    double time_taken;

    // Get the number of iterations
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Warm up the JIT compiler
    for (i = 0; i < 1000; i++)
        fibonacci(i);

    // Start the timer
    clock_t start = clock();

    // Run the benchmark
    for (i = 0; i < n; i++)
    {
        // Calculate the Fibonacci number
        k = fibonacci(i);

        // Do some additional work to prevent the compiler from optimizing away the function call
        for (j = 0; j < 1000; j++)
            k += j;
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}