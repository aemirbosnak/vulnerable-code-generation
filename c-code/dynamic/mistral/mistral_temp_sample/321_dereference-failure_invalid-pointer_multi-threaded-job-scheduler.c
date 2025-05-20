#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define NUM_THREADS 5

typedef struct {
    char* task;
    void* result;
} job;

void* worker(void* args) {
    job* job_data = (job*) args;
    printf("Starting task: %s\n", job_data->task);

    // Invalid memory access
    *(int*)job_data->result = strlen(job_data->task);

    free(job_data->task);
    free(job_data);

    return NULL;
}

int main() {
    pthread_t workers[NUM_THREADS];
    job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        jobs[i].task = malloc(20 * sizeof(char));
        strcpy(jobs[i].task, "Task for worker #");
        jobs[i].task[16 + i] = '\0';
        jobs[i].result = malloc(sizeof(int));

        pthread_create(&workers[i], NULL, worker, &jobs[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
