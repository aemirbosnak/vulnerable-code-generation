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

Job jobs[NUM_THREADS];
pthread_t threads[NUM_THREADS];

void* thread_func(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d: Starting\n", thread_id);
    sleep(1); // Simulate work
    printf("Thread %d: Freeing data\n", thread_id);
    free(jobs[thread_id].data);
    jobs[thread_id].data = NULL; // Use-after-free vulnerability
    printf("Thread %d: Done\n", thread_id);
    return NULL;
}

int main() {
    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = malloc(20);
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &jobs[i].id);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (jobs[i].data != NULL) {
            free(jobs[i].data);
        }
    }

    return 0;
}
