//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for thread data
struct thread_data {
    int id;
    char *message;
};

// Function to be executed by each thread
void *print_message(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    printf("Thread %d: %s\n", data->id, data->message);
    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    int rc;
    int i;

    // Create an array of thread data
    struct thread_data data[num_threads];
    for (i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].message = (char *) malloc(20);
        sprintf(data[i].message, "Hello from thread %d", i + 1);
    }

    // Create the threads
    for (i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, print_message, (void *) &data[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join the threads
    for (i = 0; i < num_threads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}