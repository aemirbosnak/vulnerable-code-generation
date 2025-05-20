#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define JOB_BUFFER_SIZE 100

typedef struct Job {
    char description[JOB_BUFFER_SIZE];
} Job;

Job jobs[MAX_JOBS];
pthread_t workers[MAX_JOBS];

void* execute_job(void* arg) {
    Job* job = (Job*) arg;
    // Job execution code...
    printf("Executing job: %s\n", job->description);
    sleep(1);
    return NULL;
}

int main() {
    int num_jobs;
    printf("Enter the number of jobs: ");
    if (scanf("%d", &num_jobs) != 1 || num_jobs > MAX_JOBS) {
        printf("Invalid number of jobs.\n");
        return 1;
    }

    for (int i = 0; i < num_jobs; ++i) {
        printf("Enter job %d description: ", i + 1);
        Job* job = &jobs[i];
        char buffer[JOB_BUFFER_SIZE];
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading job description.\n");
            return 1;
        }

        sscanf(buffer, "%100s", job->description);

        pthread_create(&workers[i], NULL, execute_job, job);
    }

    for (int i = 0; i < num_jobs; ++i) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
