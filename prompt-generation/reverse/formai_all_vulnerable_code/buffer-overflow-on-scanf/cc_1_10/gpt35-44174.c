//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int prime_count = 0;
int prime_numbers[100];

void *find_primes(void *num_range);

int main() {
    int num_range;
    int i, j;
    pthread_t threads[MAX_THREADS];

    printf("Enter the upper limit of the range: ");
    scanf("%d", &num_range);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, find_primes, (void *)&num_range);
    }

    for (j = 0; j < MAX_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("\nThe prime numbers in the range 1 to %d are:\n", num_range);
    for (i = 0; i < prime_count; i++) {
        printf("%d ", prime_numbers[i]);
    }
    printf("\n");

    return 0;
}

void *find_primes(void *num_range) {
    int i, j, is_prime;
    int start = (int)*((int *)num_range) * (prime_count / MAX_THREADS);
    int end = (int)*((int *)num_range) * ((prime_count + 1) / MAX_THREADS);

    for (i = start; i < end; i++) {
        is_prime = 1;

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            pthread_mutex_lock(&mutex);
            prime_numbers[prime_count] = i;
            prime_count++;
            pthread_mutex_unlock(&mutex);
        }
    }

    pthread_exit(NULL);
}