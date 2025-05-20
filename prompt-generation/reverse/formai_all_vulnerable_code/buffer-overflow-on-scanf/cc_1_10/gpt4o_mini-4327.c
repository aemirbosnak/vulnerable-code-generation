//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int start;
    int end;
    long long result;
} FactorialArgs;

void *calculate_factorial(void *args) {
    FactorialArgs *factorialArgs = (FactorialArgs *)args;
    factorialArgs->result = 1;

    for (int i = factorialArgs->start; i <= factorialArgs->end; i++) {
        factorialArgs->result *= i;
    }
    return NULL;
}

long long factorial(int n) {
    if (n < 0) return -1; // Handle negative inputs

    if (n == 0 || n == 1) return 1; // Base case

    // Calculate the chunk size for each thread
    int chunkSize = n / MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    FactorialArgs threadArgs[MAX_THREADS];
    long long total = 1;

    for (int i = 0; i < MAX_THREADS; i++) {
        threadArgs[i].start = i * chunkSize + 1; // Start of chunk
        if (i == MAX_THREADS - 1) {
            threadArgs[i].end = n; // Last thread takes the rest
        } else {
            threadArgs[i].end = (i + 1) * chunkSize; // End of chunk
        }

        // Create thread
        pthread_create(&threads[i], NULL, calculate_factorial, &threadArgs[i]);
    }

    // Join threads and calculate final result
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total *= threadArgs[i].result; // Combine results
    }

    return total;
}

int main() {
    int number;

    printf("Enter a positive integer to calculate its factorial: ");
    scanf("%d", &number);

    long long result = factorial(number);
    if (result < 0) {
        printf("Error: Factorial of a negative number isn't defined.\n");
    } else {
        printf("Factorial of %d is %lld\n", number, result);
    }

    return 0;
}