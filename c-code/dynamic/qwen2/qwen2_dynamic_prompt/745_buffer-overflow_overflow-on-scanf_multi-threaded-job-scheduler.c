#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    int id;
    char description[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* worker_thread(void* arg) {
    int thread_id = *(int*)arg;
    while (1) {
        if (job_count > 0) {
            Job current_job = jobs[--job_count];
            printf("Thread %d is processing job %d: %s\n", thread_id, current_job.id, current_job.description);
        } else {
            pthread_exit(NULL);
        }
    }
}

int main() {
    pthread_t threads[4];
    int thread_ids[4] = {0, 1, 2, 3};

    // Create worker threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, worker_thread, &thread_ids[i]);
    }

    // Simulate adding jobs to the scheduler
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        sprintf(jobs[i].description, "Job %d", i + 1);
        job_count++;
    }

    // Join worker threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
