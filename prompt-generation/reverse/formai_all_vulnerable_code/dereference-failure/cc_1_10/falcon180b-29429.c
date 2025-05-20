//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 100

typedef struct {
    int id;
    void *buffer;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char *buffer = (char *) data->buffer;
    int id = data->id;

    for (int i = 0; i < NUM_BLOCKS; ++i) {
        memset(buffer + i * BLOCK_SIZE, id, BLOCK_SIZE);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        data[i].id = i;
        data[i].buffer = (void *) malloc(NUM_BLOCKS * BLOCK_SIZE);
        if (!data[i].buffer) {
            fprintf(stderr, "Failed to allocate memory for thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        free(data[i].buffer);
    }

    return 0;
}