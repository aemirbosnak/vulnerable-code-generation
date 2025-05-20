//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 100

// Structure to store the arguments for each thread
typedef struct {
    int start;
    int end;
} thread_args;

// Function to calculate the Fibonacci sequence
void* calculate_fibonacci(void* args) {
    // Get the arguments
    thread_args* arguments = (thread_args*) args;
    int start = arguments->start;
    int end = arguments->end;

    // Calculate the Fibonacci sequence
    int fib[end - start + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= end - start; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci sequence
    printf("Fibonacci sequence from %d to %d: ", start, end);
    for (int i = 0; i <= end - start; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return NULL;
}

int main() {
    // Get the number of threads
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Check if the number of threads is valid
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads. Must be between 1 and %d.\n", MAX_THREADS);
        return -1;
    }

    // Get the range of numbers to calculate the Fibonacci sequence for
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Check if the range of numbers is valid
    if (start < 0 || end < 0 || start > end) {
        printf("Invalid range of numbers. Starting number must be non-negative and ending number must be greater than or equal to starting number.\n");
        return -1;
    }

    // Create the thread pool
    pthread_t threads[num_threads];

    // Calculate the range of numbers for each thread
    int range = (end - start + 1) / num_threads;

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        thread_args* args = malloc(sizeof(thread_args));
        args->start = start + i * range;
        args->end = start + (i + 1) * range - 1;
        pthread_create(&threads[i], NULL, calculate_fibonacci, args);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}