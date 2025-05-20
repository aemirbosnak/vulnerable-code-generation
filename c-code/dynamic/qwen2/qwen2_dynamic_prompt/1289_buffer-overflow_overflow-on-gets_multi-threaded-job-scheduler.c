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
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    if (index >= job_count) return NULL;
    printf("Executing job: %s\n", jobs[index].job_name);
    free(jobs[index].job_name); // Potential use-after-free
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].job_name = malloc(256);
        snprintf(jobs[i].job_name, 256, "Job%d", i);
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, execute_job, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        free(jobs[i].job_name); // Double free
    }

    return 0;
}
