//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct thread_data {
    int thread_id;
    int *shared_data;
};

void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int *shared_data = data->shared_data;

    // do some work here
    printf("Thread %d is doing some work...\n", thread_id);

    // access shared data
    shared_data[thread_id] = thread_id * 10;

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int shared_data[NUM_THREADS];
    int i;

    // initialize shared data
    for (i = 0; i < NUM_THREADS; i++) {
        shared_data[i] = 0;
    }

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->shared_data = shared_data;

        pthread_create(&threads[i], NULL, thread_function, data);
    }

    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print shared data
    printf("Shared data:\n");
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d updated shared data to %d\n", i + 1, shared_data[i]);
    }

    return 0;
}