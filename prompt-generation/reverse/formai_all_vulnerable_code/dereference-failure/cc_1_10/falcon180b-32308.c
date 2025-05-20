//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for our thread data
typedef struct {
    int id;
    char *message;
} thread_data_t;

// Function to be executed by each thread
void *print_message(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;

    printf("Thread %d: %s\n", data->id, data->message);

    return NULL;
}

// Create the specified number of threads, each printing a unique message
void create_threads(int num_threads) {
    pthread_t threads[num_threads];
    thread_data_t data[num_threads];

    // Initialize our thread data
    for (int i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].message = malloc(20);
        sprintf(data[i].message, "Thread %d", i + 1);
    }

    // Create our threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, print_message, &data[i]);
    }

    // Join all threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }

    // Convert the command line argument to an integer
    int num_threads = atoi(argv[1]);

    // Create our threads
    create_threads(num_threads);

    return 0;
}