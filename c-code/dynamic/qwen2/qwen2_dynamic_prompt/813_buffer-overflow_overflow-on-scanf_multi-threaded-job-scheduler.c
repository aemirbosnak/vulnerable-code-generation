#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    char *description;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* worker(void* arg) {
    int thread_id = *(int*)arg;
    while (1) {
        if (job_count > 0) {
            Job current_job = jobs[0];
            for (int i = 0; i < job_count - 1; i++) {
                jobs[i] = jobs[i + 1];
            }
            job_count--;
            printf("Thread %d is processing job %d: %s\n", thread_id, current_job.id, current_job.description);
            free(current_job.description);
        } else {
            pthread_exit(NULL);
        }
    }
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];

    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    while (1) {
        if (job_count < MAX_JOBS) {
            Job new_job;
            new_job.id = job_count + 1;
            printf("Enter job description for job %d: ", new_job.id);
            new_job.description = (char*)malloc(256 * sizeof(char));
            scanf("%255s", new_job.description); // Vulnerable to buffer overflow
            jobs[job_count++] = new_job;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
