//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 16

// Global variables
int num_threads;
int *data;
int *result;
int data_size;
pthread_mutex_t mutex;
double elapsed_time;

// Function prototypes
void *thread_func(void *param);
void init_data(int size);
void cleanup();

// Main function
int main(int argc, char *argv[]) {
    srand(time(NULL));
    num_threads = rand() % MAX_THREADS + 1;
    data_size = rand() % 10000 + 1;
    data = (int *)malloc(data_size * sizeof(int));
    result = (int *)malloc(data_size * sizeof(int));
    init_data(data_size);

    pthread_t threads[MAX_THREADS];
    int rc;

    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    cleanup();

    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}

// Thread function
void *thread_func(void *param) {
    int thread_id = (int)param;
    int start_index = thread_id * data_size / num_threads;
    int end_index = (thread_id + 1) * data_size / num_threads - 1;

    pthread_mutex_lock(&mutex);
    for (int i = start_index; i <= end_index; i++) {
        result[i] = data[i] * 2;
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Initialize data
void init_data(int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

// Cleanup
void cleanup() {
    free(data);
    free(result);
    pthread_mutex_destroy(&mutex);
}