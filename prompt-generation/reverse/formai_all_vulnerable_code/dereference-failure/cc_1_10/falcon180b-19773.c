//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_ALLOCS 100

typedef struct {
    int id;
    int *ptr;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i;

    for (i = 0; i < NUM_ALLOCS; i++) {
        data->ptr[i] = i;
    }

    printf("Thread %d finished\n", data->id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].ptr = (int *) malloc(NUM_ALLOCS * sizeof(int));

        if (data[i].ptr == NULL) {
            printf("Failed to allocate memory for thread %d\n", i);
            exit(1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        free(data[i].ptr);
    }

    return 0;
}