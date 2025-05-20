#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    char *job_name;
    int priority;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    printf("Executing job: %s with priority: %d\n", jobs[index].job_name, jobs[index].priority);
    free(jobs[index].job_name); // Potential use-after-free if not handled properly
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].job_name = malloc(256 * sizeof(char));
        sprintf(jobs[i].job_name, "Job_%d", i);
        jobs[i].priority = rand() % 10;
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, execute_job, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        free(jobs[i].job_name);
    }

    return 0;
}
