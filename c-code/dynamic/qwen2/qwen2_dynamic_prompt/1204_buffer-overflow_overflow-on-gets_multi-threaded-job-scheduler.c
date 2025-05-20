#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_JOB_SIZE 1024

typedef struct {
    char job[MAX_JOB_SIZE];
} Job;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Executing job: %s\n", job->job);
    return NULL;
}

int main() {
    pthread_t threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; i++) {
        memset(&jobs[i], 0, sizeof(Job));
        snprintf(jobs[i].job, MAX_JOB_SIZE - 1, "Job %d", i);
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Intentional buffer overflow vulnerability
    char input[10];
    printf("Enter a job description: ");
    gets(input); // Vulnerable function

    return 0;
}
