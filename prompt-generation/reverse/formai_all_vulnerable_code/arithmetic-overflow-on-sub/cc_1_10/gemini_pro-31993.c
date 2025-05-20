//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Safe memory allocation function
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Safe reallocation function
void *safe_realloc(void *ptr, size_t size) {
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to benchmark
void function_to_benchmark(void *arg) {
    // Perform the operation being benchmarked

    // NOTE: In a real benchmarking scenario, this code would likely be implemented
    // in assembly or low-level C for optimal performance.
}

// Benchmarking function
double benchmark(void *arg, int iterations) {
    clock_t start_time = clock();
    for (int i = 0; i < iterations; i++) {
        function_to_benchmark(arg);
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time / iterations;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <argument> <iterations>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command-line arguments
    void *arg = argv[1];
    int iterations = atoi(argv[2]);

    // Perform benchmarking
    double elapsed_time = benchmark(arg, iterations);

    // Print results
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return EXIT_SUCCESS;
}