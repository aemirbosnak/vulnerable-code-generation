//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the struct for passing data between threads
typedef struct {
    int num;
    char name[30];
} thread_data;

// Function to be executed by each thread
void *runner(void *arg) {
    thread_data *data = arg;
    printf("Thread %d started with name %s and number %d\n", data->num, data->name, data->num);
    sleep(1);
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads;
    printf("Enter the number of threads to create: ");
    scanf("%d", &num_threads);

    // Create an array of thread data
    thread_data threads[num_threads];

    // Initialize the thread data
    for (int i = 0; i < num_threads; i++) {
        threads[i].num = i + 1;
        sprintf(threads[i].name, "Thread %d", i + 1);
    }

    // Create the threads
    pthread_t threads_id[num_threads];
    int rc;
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads_id[i], NULL, runner, &threads[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join with each thread
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads_id[i], NULL);
    }

    return 0;
}