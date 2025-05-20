//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_THREADS 10

typedef struct {
    int count;
    int start;
} ThreadData;

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void* generate_primes(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    printf("Thread started: Starting from %d\n", data->start);
    int num_found = 0;
    int num_to_check = data->start;

    while (num_found < data->count) {
        if (is_prime(num_to_check)) {
            printf("Prime found by thread: %d\n", num_to_check);
            num_found++;
        }
        num_to_check++;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int total_primes;

    printf("Enter the total number of prime numbers to generate: ");
    scanf("%d", &total_primes);

    int primes_per_thread = total_primes / MAX_THREADS;
    int remaining_primes = total_primes % MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].count = primes_per_thread + (i < remaining_primes ? 1 : 0);
        thread_data[i].start = i * primes_per_thread + (i < remaining_primes ? i : remaining_primes);

        if (pthread_create(&threads[i], NULL, generate_primes, (void*)&thread_data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed. Total primes generated: %d\n", total_primes);
    return 0;
}