#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define BUFFER_SIZE 64

typedef struct Job {
    char name[BUFFER_SIZE];
    int priority;
} Job;

Job job_queue[MAX_JOBS];
pthread_mutex_t job_queue_lock = PTHREAD_MUTEX_INITIALIZER;
int current_job = 0;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Executing job: %s\n", job->name);
    sleep(job->priority);
    return NULL;
}

void add_job(char* name, int priority) {
    pthread_mutex_lock(&job_queue_lock);
    if (current_job < MAX_JOBS) {
        sprintf(job_queue[current_job].name, "%s", name);
        job_queue[current_job].priority = priority;
        current_job++;
    }
    pthread_mutex_unlock(&job_queue_lock);
}

int main() {
    pthread_t threads[MAX_JOBS];

    char buffer[BUFFER_SIZE];
    int priority;

    printf("Multi-threaded Job Scheduler\n");
    printf("Enter jobs (name priority):\n");

    for (int i = 0; i < MAX_JOBS; i++) {
        fgets(buffer, BUFFER_SIZE, stdin);
        sscanf(buffer, "%s%d", buffer, &priority);
        add_job(buffer, priority);
        pthread_create(&threads[i], NULL, execute_job, &job_queue[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
