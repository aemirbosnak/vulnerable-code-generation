//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: distributed
// ==========================
// = Distributed Cryptography =
// ==========================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROUNDS 1000

// Global variables
int shared_secret[NUM_THREADS];
int num_threads;
int num_rounds;
int round_count;
pthread_mutex_t lock;

void *run(void *arg) {
    int thread_id = *(int *) arg;
    int local_secret = rand() % 100000;

    pthread_mutex_lock(&lock);
    shared_secret[thread_id] = local_secret;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int sum = 0;

    srand(time(NULL));

    num_threads = NUM_THREADS;
    num_rounds = NUM_ROUNDS;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, run, (void *) &i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Shared secret: ");
    for (i = 0; i < num_threads; i++) {
        printf("%d ", shared_secret[i]);
        sum += shared_secret[i];
    }
    printf("\nSum of shared secrets: %d\n", sum);

    return 0;
}