#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void * worker(void *arg) {
    int *data = (int *)arg;
    int id = (int)arg;

    while (1) {
        printf("Thread %d: Processing job with data %d\n", id, *data);
        // Dereference unallocated memory
        printf("Thread %d: Data after processing: %d\n", id, **&data);
        sleep(1);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        data[i] = i * 100;
        pthread_create(&threads[i], NULL, worker, (void *)&data[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
