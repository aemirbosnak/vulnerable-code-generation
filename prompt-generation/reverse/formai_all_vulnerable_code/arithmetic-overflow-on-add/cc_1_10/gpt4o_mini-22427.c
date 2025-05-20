//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_THREADS 5
#define BUFFER_SIZE 10

typedef struct {
    int id;
    char message[BUFFER_SIZE];
} WorkerData;

void *worker_function(void *arg) {
    WorkerData *data = (WorkerData *)arg;

    srand(time(NULL) + data->id); // Unique seed for each thread
    int sleep_time = rand() % 5 + 1; // Random sleep time between 1 and 5 seconds

    snprintf(data->message, BUFFER_SIZE, "Thread %d is running.", data->id);
    printf("%s\n", data->message);
    sleep(sleep_time);
    
    snprintf(data->message, BUFFER_SIZE, "Thread %d is done.", data->id);
    printf("%s\n", data->message);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    WorkerData thread_data[MAX_THREADS];
    int rc;
    
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].id = i + 1; // Assigning thread ID
        rc = pthread_create(&threads[i], NULL, worker_function, (void *)&thread_data[i]);
        
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread %d, %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed their execution.\n");

    return 0;
}