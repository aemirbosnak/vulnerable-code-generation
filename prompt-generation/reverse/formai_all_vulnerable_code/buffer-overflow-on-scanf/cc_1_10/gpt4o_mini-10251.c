//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to calculate Fibonacci number recursively
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Structure to hold parameters for thread function
typedef struct {
    int index;
    long long result;
} FibonacciData;

// Thread function to compute Fibonacci number
void* compute_fibonacci(void* arg) {
    FibonacciData* data = (FibonacciData*)arg;
    data->result = fibonacci(data->index);
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to compute: ");
    scanf("%d", &n);

    // Allocate memory for FibonacciData structures and threads
    FibonacciData* fibonacci_data = malloc(n * sizeof(FibonacciData));
    pthread_t* threads = malloc(n * sizeof(pthread_t));

    // Create threads to compute Fibonacci numbers
    for (int i = 0; i < n; i++) {
        fibonacci_data[i].index = i; // Set the index for Fibonacci calculation
        pthread_create(&threads[i], NULL, compute_fibonacci, (void*)&fibonacci_data[i]);
    }

    // Wait for all threads to complete and print results
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
        printf("Fibonacci(%d) = %lld\n", fibonacci_data[i].index, fibonacci_data[i].result);
    }

    // Clean up
    free(fibonacci_data);
    free(threads);

    return 0;
}