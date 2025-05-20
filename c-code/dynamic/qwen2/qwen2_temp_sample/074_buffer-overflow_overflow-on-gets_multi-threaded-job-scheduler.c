#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    char *command;
    int id;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    int id = *(int*)arg;
    if (id >= job_count) return NULL;
    printf("Executing job %d: %s\n", id, jobs[id].command);
    // Simulate job execution time
    sleep(2);
    printf("Job %d completed.\n", id);
    free(jobs[id].command);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int ids[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].command = malloc(1024); // Allocate memory for command
        sprintf(jobs[i].command, "sleep %d", rand() % 5 + 1);
        jobs[i].id = i;
        ids[i] = i;
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_create(&threads[i], NULL, execute_job, &ids[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        free(jobs[i].command);
    }

    return 0;
}
