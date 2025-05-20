//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: thoughtful
// Unique C Benchmarking Example

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void time_function(void (*func)(int), int n);
void function_1(int n);
void function_2(int n);

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random input data
    int n = rand() % 1000000;

    // Time function 1
    time_function(function_1, n);

    // Time function 2
    time_function(function_2, n);

    return 0;
}

// Function to time a function
void time_function(void (*func)(int), int n) {
    // Get start time
    clock_t start = clock();

    // Call function
    func(n);

    // Get end time
    clock_t end = clock();

    // Calculate time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print time taken
    printf("Function took %f seconds to execute.\n", time_taken);
}

// Function 1
void function_1(int n) {
    // Loop through numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        // Do something
    }
}

// Function 2
void function_2(int n) {
    // Create an array of size n
    int *array = malloc(n * sizeof(int));

    // Loop through numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        // Store i in the array
        array[i] = i;
    }

    // Free the array
    free(array);
}