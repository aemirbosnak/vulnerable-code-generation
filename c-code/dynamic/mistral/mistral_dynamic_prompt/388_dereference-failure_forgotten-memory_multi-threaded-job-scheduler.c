#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Job {
    int id;
    void* data;
} Job;

void* worker(void* arg) {
    Job* job = (Job*) arg;
    printf("Worker: Processing job %d with data: %p\n", job->id, job->data);
    free(job);
    return NULL;
}

void create_job(int id, void* data) {
    Job* job = (Job*) malloc(sizeof(Job));
    job->id = id;
    job->data = data;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, worker, job);
}

int main() {
    srand(time(NULL));

    Job* jobs[10];
    for (int i = 0; i < 10; ++i) {
        jobs[i] = (Job*) malloc(sizeof(Job));
        jobs[i]->id = i;
        jobs[i]->data = malloc(rand() % 100 + 1);
        create_job(i + 10, jobs[i]->data);
    }

    // Forgotten memory - freeing memory allocated for the jobs array.
    free(jobs);

    printf("Main thread exiting...\n");
    pthread_exit(NULL);
    return 0;
}
