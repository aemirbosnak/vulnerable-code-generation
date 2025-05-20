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
    char description[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* schedule_job(void* arg) {
    int job_id = *(int*)arg;
    printf("Enter job %d description: ", job_id);
    scanf("%s", jobs[job_id].description);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i;
        if (pthread_create(&threads[i], NULL, schedule_job, &jobs[i].id) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        printf("Job %d: %s\n", jobs[i].id, jobs[i].description);
    }

    return 0;
}
