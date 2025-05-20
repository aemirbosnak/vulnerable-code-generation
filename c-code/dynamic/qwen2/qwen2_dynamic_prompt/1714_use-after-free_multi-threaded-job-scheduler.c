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
    printf("Thread %d: Processing job with data '%s'\n", job->id, job->data);
    sleep(1); // Simulate work
    free(job->data); // Free the allocated memory
    job->data = NULL; // Set pointer to NULL
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = (char*)malloc(20 * sizeof(char));
        sprintf(jobs[i].data, "Data for job %d", i);
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
            printf("Thread %d: Data after free: '%s'\n", jobs[i].id, jobs[i].data);
        } else {
            printf("Thread %d: Data is NULL\n", jobs[i].id);
        }
    }

    return 0;
}
