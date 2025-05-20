#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 10

typedef struct {
    char* data;
    size_t size;
} Job;

Job jobs[MAX_THREADS];
pthread_t workers[MAX_THREADS];

void* worker(void* arg) {
    size_t i = (size_t) arg;
    while (1) {
        pthread_mutex_lock(&jobs[i].data[jobs[i].size]);
        char job_data[BUFFER_SIZE];
        strcpy(job_data, jobs[i].data);
        printf("Worker %ld executed job: %s\n", i, job_data);
        jobs[i].size = 0;
        pthread_mutex_unlock(&jobs[i].data[0]);
    }
}

int main() {
    for (size_t i = 0; i < MAX_THREADS; i++) {
        jobs[i].data = malloc(BUFFER_SIZE);
    }

    for (size_t i = 0; i < MAX_THREADS; i++) {
        pthread_create(&workers[i], NULL, worker, (void*) i);
    }

    for (size_t i = 0; i < MAX_THREADS; i++) {
        for (size_t j = 0; j < BUFFER_SIZE * 10; j++) {
            jobs[i].data[j] = 'A' + (rand() % 26);
        }
        jobs[i].size = BUFFER_SIZE * 10;
    }

    for (size_t i = 0; i < MAX_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
