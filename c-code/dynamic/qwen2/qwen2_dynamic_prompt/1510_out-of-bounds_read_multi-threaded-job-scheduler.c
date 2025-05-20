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
        if (i == 15) {
            // Intentional out-of-bounds read
            printf("Thread %d: Reading from buffer[%d] = %d\n", thread_id, i, buffer[i]);
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
