#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int* data;
} Job;

void* worker(void* arg) {
    Job* job = (Job*)arg;
    printf("Worker processing data: %d\n", *job->data);
    free(job->data); // Simulating improper memory management
    return NULL;
}

int main() {
    pthread_t threads[5];
    Job jobs[5];

    for (int i = 0; i < 5; i++) {
        jobs[i].data = (int*)malloc(sizeof(int));
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        *jobs[i].data = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, worker, &jobs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 5; i++) {
        free(jobs[i].data); // Freeing already freed memory
    }

    printf("Dereference failure triggered\n");

    return EXIT_SUCCESS;
}
