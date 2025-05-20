//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    void* (*start_routine)(void*);
} thread_data_t;

// Define the thread function
void* thread_function(void* arg) {
    // Cast the argument to the thread data structure
    thread_data_t* data = (thread_data_t*) arg;

    // Print the thread ID and start routine
    printf("Thread %d starting with routine: %p\n", data->id, data->start_routine);

    // Call the start routine and pass the argument
    data->start_routine(arg);

    // Print the thread ID and end routine
    printf("Thread %d ending with routine: %p\n", data->id, data->start_routine);

    return NULL;
}

// Define the main function
int main() {
    // Initialize the thread IDs
    int thread_ids[MAX_THREADS] = {0};

    // Initialize the thread data structures
    thread_data_t thread_data[MAX_THREADS];

    // Initialize the number of threads
    int num_threads = 0;

    // Loop until the maximum number of threads is reached
    while (num_threads < MAX_THREADS) {
        // Prompt the user for the thread ID and start routine
        printf("Enter thread ID (0-%d) and start routine (in format 'routine'): ", MAX_THREADS - 1);
        scanf("%d %s", &thread_ids[num_threads], thread_data[num_threads].start_routine);

        // Increment the number of threads
        num_threads++;
    }

    // Loop through the threads and create them
    for (int i = 0; i < num_threads; i++) {
        // Create the thread with the specified ID and start routine
        pthread_create(&thread_data[i].id, NULL, thread_function, &thread_data[i]);
    }

    // Loop through the threads and join them
    for (int i = 0; i < num_threads; i++) {
        // Wait for the thread to finish
        pthread_join(thread_data[i].id, NULL);
    }

    return 0;
}