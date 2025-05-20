#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define JOB_BUFFER_SIZE 256

typedef struct Job {
    char command[JOB_BUFFER_SIZE];
    pthread_t thread_id;
} Job;

Job job_queue[MAX_JOBS];
int num_jobs = 0;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Executing job: %s\n", job->command);
    // Intentionally violate array bounds
    int result = strcmp(job->command, "dereference_failure");
    free(job);
    return 0;
}

void add_job(char* command) {
    if (num_jobs >= MAX_JOBS) {
        printf("Job queue is full. Cannot add job: %s\n", command);
        return;
    }
    strcpy(job_queue[num_jobs].command, command);
    pthread_create(&job_queue[num_jobs].thread_id, NULL, execute_job, &job_queue[num_jobs]);
    num_jobs++;
}

int main() {
    char* jobs[] = {
        "./example_job1",
        "./example_job2",
        "./example_job3",
        "dereference_failure", // Intentionally invalid job command
        "./example_job4",
        "./example_job5",
        "./example_job6",
        "./example_job7",
        "./example_job8",
        "./example_job9",
        "./example_job10"
    };

    for (int i = 0; i < 11; i++) {
        add_job(jobs[i]);
    }

    pthread_exit(0);
    return 0;
}
