//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_NUM 100000000
#define NUM_THREADS 4

int primes[MAX_NUM];
int count = 0;

void *is_prime(void *arg) {
    int start = *(int *) arg;
    int end = start + MAX_NUM / NUM_THREADS;

    for (int i = start; i < end; i++) {
        if (primes[i]) {
            continue;
        }

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                primes[i] = 1;
                break;
            }
        }
    }

    pthread_exit(0);
}

int main() {
    int i, j;
    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, is_prime, (void *) i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 2; i < MAX_NUM; i++) {
        if (!primes[i]) {
            printf("%d\n", i);
            count++;
        }

        if (count == 10) {
            break;
        }
    }

    return 0;
}