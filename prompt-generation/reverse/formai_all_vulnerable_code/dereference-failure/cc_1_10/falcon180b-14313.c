//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the shared data structure
typedef struct {
    int *data;
    int start;
    int end;
} ThreadData;

// Define the worker function
void *worker(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int *local_data = malloc(data->end - data->start + 1);
    int i;

    for(i = data->start; i <= data->end; i++) {
        local_data[i - data->start] = i;
    }

    printf("Thread %d has finished processing data\n", *(int *) data->data);

    free(local_data);
    return NULL;
}

// Define the main function
int main() {
    pthread_t threads[MAX_THREADS];
    int i, j, num_threads = 0;
    ThreadData *data = malloc(sizeof(ThreadData));

    // Initialize the shared data structure
    data->data = malloc(sizeof(int));
    *((int *) data->data) = 0;
    data->start = 0;
    data->end = 100;

    // Create the threads
    for(i = 0; i < MAX_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, worker, data) == 0) {
            num_threads++;
        }
    }

    // Join the threads
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(data->data);
    free(data);

    return 0;
}