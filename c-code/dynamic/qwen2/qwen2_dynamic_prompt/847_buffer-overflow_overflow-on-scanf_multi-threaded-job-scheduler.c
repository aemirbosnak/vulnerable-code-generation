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
    char command[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    printf("Executing job %d: %s\n", jobs[index].id, jobs[index].command);
    // Simulate job execution time
    sleep(2);
    printf("Job %d completed\n", jobs[index].id);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        printf("Enter command for job %d: ", i + 1);
        scanf("%255s", jobs[i].command); // Vulnerable to buffer overflow
        pthread_create(&threads[i], NULL, execute_job, &i);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
