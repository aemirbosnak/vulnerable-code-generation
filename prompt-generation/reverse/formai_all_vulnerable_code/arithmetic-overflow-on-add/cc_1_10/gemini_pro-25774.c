//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread data structure
typedef struct {
    int start;
    int end;
    int count;
} thread_data;

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Thread function to count prime numbers in a range
void *count_primes_thread(void *arg) {
    thread_data *data = (thread_data *)arg;
    int count = 0;
    for (int i = data->start; i <= data->end; ++i) {
        if (is_prime(i)) {
            ++count;
        }
    }
    data->count = count;
    return NULL;
}

int main() {
    // Get the number of threads and the range of numbers to check
    int num_threads, start, end;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Create thread data structures
    thread_data data[num_threads];
    int range = (end - start) / num_threads;
    for (int i = 0; i < num_threads; ++i) {
        data[i].start = start + i * range;
        data[i].end = start + (i + 1) * range - 1;
        data[i].count = 0;
    }

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, count_primes_thread, &data[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the total number of prime numbers
    int total_count = 0;
    for (int i = 0; i < num_threads; ++i) {
        total_count += data[i].count;
    }

    // Print the total number of prime numbers
    printf("Total number of prime numbers between %d and %d: %d\n", start, end, total_count);

    return 0;
}