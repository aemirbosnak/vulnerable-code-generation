#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    int buffer[10];
    int i;

    // Simulate some work
    for (i = 0; i < 20; i++) {
        if (thread_id == 0 && i >= 10) {
            printf("Thread %d: Reading out-of-bounds index %d\n", thread_id, i);
            printf("%d\n", buffer[i]); // Out of bounds read
        } else {
            buffer[i % 10] = i;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
