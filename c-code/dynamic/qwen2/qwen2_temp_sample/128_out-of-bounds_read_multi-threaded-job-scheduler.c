#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_func(void* arg) {
    int thread_id = *(int*)arg;
    int buffer[5];
    // Deliberate out-of-bounds read vulnerability
    printf("Thread %d: Reading from buffer[%d]\n", thread_id, 7);
    int value = buffer[7];  // Out-of-bounds read
    printf("Thread %d: Value read: %d\n", thread_id, value);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
