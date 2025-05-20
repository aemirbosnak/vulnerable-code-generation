//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

#define NUM_THREADS 4

typedef struct {
    long start;
    long end;
    int *prime_count;
    pthread_mutex_t *lock;
} ThreadData;

// Function to check if a number is prime
bool is_prime(long number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (long i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Thread function to calculate prime numbers in a given range
void* calculate_primes(void* arg) {
    ThreadData *data = (ThreadData*) arg;
    long count = 0;

    for (long num = data->start; num <= data->end; num++) {
        if (is_prime(num)) {
            pthread_mutex_lock(data->lock);
            (*data->prime_count)++;
            pthread_mutex_unlock(data->lock);
        }
    }
    return NULL;
}

int main() {
    long limit;
    printf("Enter the upper limit to compute prime numbers: ");
    scanf("%ld", &limit);

    if (limit < 2) {
        printf("The limit must be at least 2.\n");
        return 1;
    }

    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int prime_count = 0;
    pthread_mutex_t lock;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    long range = limit / NUM_THREADS;

    // Create threads to compute primes
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].start = i * range + 1;
        threadData[i].end = (i == NUM_THREADS - 1) ? limit : (i + 1) * range;
        threadData[i].prime_count = &prime_count;
        threadData[i].lock = &lock;

        if (pthread_create(&threads[i], NULL, calculate_primes, (void*)&threadData[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup the mutex
    pthread_mutex_destroy(&lock);

    printf("Total prime numbers found up to %ld: %d\n", limit, prime_count);
    return 0;
}