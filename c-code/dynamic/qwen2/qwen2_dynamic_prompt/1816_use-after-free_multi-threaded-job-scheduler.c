#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int id;
    char *data;
} Job;

void* thread_func(void* arg) {
    Job *job = (Job*)arg;
    printf("Thread %d: Processing data\n", job->id);
    sleep(1); // Simulate work
    free(job->data); // Free memory
    job->data = NULL; // Set pointer to NULL
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = (char*)malloc(20 * sizeof(char));
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        sprintf(jobs[i].data, "Data for thread %d", i);
        if (pthread_create(&threads[i], NULL, thread_func, &jobs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    // Use-after-free vulnerability
    for (int i = 0; i < NUM_THREADS; i++) {
        if (jobs[i].data != NULL) {
            printf("Thread %d: Data: %s\n", jobs[i].id, jobs[i].data);
        } else {
            printf("Thread %d: Data has been freed\n", jobs[i].id);
        }
    }

    return 0;
}
