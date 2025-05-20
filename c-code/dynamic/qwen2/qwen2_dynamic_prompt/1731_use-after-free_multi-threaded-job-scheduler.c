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
    printf("Thread %d is processing job %d\n", thread_id, jobs[thread_id].id);
    sleep(1); // Simulate work
    free(jobs[thread_id].data); // Freeing memory
    jobs[thread_id].data = NULL; // Setting pointer to NULL
    return NULL;
}

int main() {
    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = malloc(100); // Allocating memory
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Use-after-free vulnerability
    for (int i = 0; i < NUM_THREADS; i++) {
        if (jobs[i].data != NULL) {
            printf("Use-after-free: Thread %d accessed freed data\n", i);
            free(jobs[i].data); // Double free
        }
    }

    return 0;
}
