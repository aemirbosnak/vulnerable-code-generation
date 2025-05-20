//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_THREADS 4

typedef struct {
    int number;
    bool is_prime;
} prime_result_t;

void* prime_check_thread(void* arg) {
    prime_result_t* result = (prime_result_t*)arg;
    int number = result->number;

    result->is_prime = true;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            result->is_prime = false;
            break;
        }
    }

    return NULL;
}

int main() {
    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    prime_result_t results[MAX_THREADS];

    printf("Enter a number: ");
    int number;
    scanf("%d", &number);

    int chunk_size = number / num_threads;

    for (int i = 0; i < num_threads; i++) {
        results[i].number = chunk_size * i + 1;
        pthread_create(&threads[i], NULL, prime_check_thread, &results[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);

        if (results[i].is_prime) {
            printf("%d is a prime number.\n", results[i].number);
        } else {
            printf("%d is not a prime number.\n", results[i].number);
        }
    }

    return 0;
}