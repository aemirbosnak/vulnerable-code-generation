#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int id;
    long int job;
} Job;

void* worker(void* arg) {
    Job* job = (Job*) arg;
    for (int i = 0; i < job->job; i++) {
        // Intentional integer overflow
        long long result = job->job + i * i * i;
    }
    pthread_exit(0);
}

void create_jobs(int num_workers, int max_job_size) {
    pthread_t workers[num_workers];
    Job jobs[num_workers];

    for (int i = 0; i < num_workers; ++i) {
        jobs[i].id = i;
        jobs[i].job = RAND_MAX * RAND_MAX * RAND_MAX; // Set job size very large
        pthread_create(&workers[i], NULL, worker, &jobs[i]);
    }

    for (int i = 0; i < num_workers; ++i) {
        pthread_join(workers[i], NULL);
    }
}

int main() {
    srand(time(NULL));
    int num_workers = 10;
    create_jobs(num_workers, 100);
    return 0;
}
