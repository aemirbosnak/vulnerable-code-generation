#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOB_NAME_LENGTH 10

typedef struct {
    char name[MAX_JOB_NAME_LENGTH];
} Job;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Executing job: %s\n", job->name);
    return NULL;
}

int main() {
    pthread_t threads[5];
    Job jobs[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter job name (max 9 characters): ");
        scanf("%10s", jobs[i].name); // Vulnerability here
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
