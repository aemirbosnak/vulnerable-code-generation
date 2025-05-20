//Falcon-180B DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_REQUESTS 1000

typedef struct {
    int id;
    int *data;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int id = data->id;
    int *ptr = data->data;

    for (int i = 0; i < NUM_REQUESTS; i++) {
        printf("Thread %d is accessing memory location %p\n", id, ptr);
        fflush(stdout);
        usleep(100);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    int *shared_memory = (int *) malloc(NUM_THREADS * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = rand() % NUM_THREADS;
        shared_memory[ids[i]] = i;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t data;
        data.id = ids[i];
        data.data = &shared_memory[ids[i]];

        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(shared_memory);

    return 0;
}