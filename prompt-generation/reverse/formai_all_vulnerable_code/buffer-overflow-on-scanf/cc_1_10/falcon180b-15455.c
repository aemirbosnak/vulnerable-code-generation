//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads that can be created
#define MAX_THREADS 10

// Define the structure for passing data to threads
typedef struct {
    int thread_id;
    int count;
} thread_data;

// Function to be executed by each thread
void *count_to_ten(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i;

    for (i = 1; i <= data->count; i++) {
        printf("Thread %d is counting to %d: %d\n", data->thread_id, data->count, i);
        sleep(1); // Sleep for 1 second between each count
    }

    return NULL;
}

// Function to create and manage threads
void create_threads(int num_threads, int count) {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    int i;

    // Initialize thread data
    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        data[i].count = count;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, count_to_ten, &data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    int num_threads;

    // Get the number of threads to create from the user
    printf("Enter the number of threads to create: ");
    scanf("%d", &num_threads);

    // Create and manage threads
    create_threads(num_threads, 10);

    return 0;
}