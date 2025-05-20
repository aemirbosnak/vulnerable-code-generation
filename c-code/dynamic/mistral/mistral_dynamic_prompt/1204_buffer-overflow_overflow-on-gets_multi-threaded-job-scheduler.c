#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 16

typedef struct Job {
    char command[BUFFER_SIZE];
    pthread_t thread_id;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    Job* job = (Job*) arg;
    system(job->command);
    pthread_exit(0);
}

void add_job(char* command) {
    if (job_count == MAX_JOBS) {
        printf("Job queue is full.\n");
        return;
    }

    strcpy(jobs[job_count].command, command);
    printf("Added job: %s\n", jobs[job_count].command);
    job_count++;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, execute_job, &jobs[job_count - 1]);
}

int main() {
    while (1) {
        char command[BUFFER_SIZE];
        printf("Enter command: ");
        gets(command);
        add_job(command);
    }

    return 0;
}
