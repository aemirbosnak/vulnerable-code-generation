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
    FILE* file = fopen("jobs.txt", "r");
    if (!file) {
        perror("Failed to open jobs file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%d %[^\n]", &jobs[job_count].id, jobs[job_count].description) != EOF) {
        job_count++;
    }

    fclose(file);

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
