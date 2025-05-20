//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
void generate_random_numbers(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to calculate the sum of an array
int calculate_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to benchmark the calculate_sum function
void benchmark_calculate_sum(int *arr, int size, int num_iterations) {
    clock_t start_time = clock();
    for (int i = 0; i < num_iterations; i++) {
        calculate_sum(arr, size);
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.4f seconds\n", elapsed_time);
}

int main() {
    int size = 1000000;
    int num_iterations = 1000;

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Generate random numbers
    generate_random_numbers(arr, size);

    // Benchmark the calculate_sum function
    printf("Benchmarking calculate_sum function...\n");
    benchmark_calculate_sum(arr, size, num_iterations);

    // Free memory
    free(arr);

    return 0;
}