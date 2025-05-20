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
    pthread_t thread_id;
} Job;

Job jobs[NUM_THREADS];
int job_count = 0;

void* worker(void* arg) {
    Job* job = (Job*)arg;
    printf("Thread %d is working\n", job->id);
    sleep(1); // Simulate work
    printf("Thread %d is freeing its job\n", job->id);
    free(job);
    return NULL;
}

int main() {
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        if (pthread_create(&jobs[i].thread_id, NULL, worker, &jobs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(jobs[i].thread_id, NULL);
    }

    // Use-after-free vulnerability
    printf("Use-after-free: Accessing freed memory\n");
    printf("Job ID: %d\n", jobs[0].id);

    pthread_mutex_destroy(&mutex);
    return 0;
}
