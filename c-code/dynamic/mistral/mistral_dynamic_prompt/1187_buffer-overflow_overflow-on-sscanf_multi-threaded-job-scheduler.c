#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 100

typedef struct Job {
    char command[BUFFER_SIZE];
} Job;

Job jobs[MAX_JOBS];
pthread_mutex_t jobs_lock;
int job_count = 0;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    // Execute the job command here (e.g. system(job->command))
    printf("Executing job: %s\n", job->command);
    return NULL;
}

void add_job(const char* command) {
    pthread_mutex_lock(&jobs_lock);
    strcpy(jobs[job_count].command, command);
    job_count++;
    pthread_mutex_unlock(&jobs_lock);
}

int main() {
    pthread_t threads[MAX_JOBS];

    for (int i = 0; i < 10; i++) {
        char buffer[BUFFER_SIZE];
        printf("Enter command for job %d: ", i);
        fgets(buffer, BUFFER_SIZE, stdin);

        // Vulnerable sscanf leading to buffer overflow
        sscanf(buffer, "%s", jobs[i].command);

        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
