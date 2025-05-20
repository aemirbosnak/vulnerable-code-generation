#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_JOBS 10
#define JOB_DATA_SIZE 1000000

typedef struct {
    char name[20];
    void* data;
    pthread_t thread_id;
} Job;

void* job_function(void* args) {
    Job* job = (Job*) args;
    char* job_data = (char*) job->data;

    // Intentionally vulnerable code: Using memmove with improper sizes for integer overflow
    char overflow_buffer[4];
    memmove(overflow_buffer, job_data, JOB_DATA_SIZE);

    sleep(1);
    printf("Job '%s' finished.\n", job->name);
    free(job->data);
    free(job);
    return NULL;
}

void create_and_schedule_job(Job* job) {
    pthread_create(&job->thread_id, NULL, job_function, job);
}

int main() {
    Job jobs[MAX_JOBS];
    char* job_data[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; ++i) {
        snprintf(jobs[i].name, sizeof(jobs[i].name), "Job %d", i);
        jobs[i].data = malloc(JOB_DATA_SIZE);

        // Fill job data with hardcoded integer values that exceed available memory for the overflow_buffer.
        for (int j = 0; j < JOB_DATA_SIZE; ++j) {
            job_data[i][j] = (i * 1000) + j;
        }

        jobs[i].data = job_data[i];
        create_and_schedule_job(&jobs[i]);
    }

    sleep(5);
    return 0;
}
