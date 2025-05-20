#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int* data;
    int size;
} Job;

void* job_function(void* arg) {
    Job* job = (Job*)arg;

    // Intentionally creating an overflow by adding a large number to the allocated memory
    job->data = realloc(job->data, job->size + 1000000000);

    for (int i = 0; i < job->size; ++i) {
        (*(job->data + i))++;
    }

    printf("Thread %ld completed job with data:\n", pthread_self());
    for (int i = 0; i < job->size; ++i) {
        printf("%d ", *(job->data + i));
    }
    printf("\n");
    free(job->data);
    free(job);

    return NULL;
}

int main() {
    int num_jobs = 10;
    int job_size = 10000000;

    Job* jobs = malloc(num_jobs * sizeof(Job));
    pthread_t threads[num_jobs];

    for (int i = 0; i < num_jobs; ++i) {
        jobs[i].data = malloc(job_size * sizeof(int));
        for (int j = 0; j < job_size; ++j) {
            jobs[i].data[j] = i;
        }
        jobs[i].size = job_size;
        pthread_create(&threads[i], NULL, job_function, &jobs[i]);
    }

    for (int i = 0; i < num_jobs; ++i) {
        pthread_join(threads[i], NULL);
    }

    free(jobs);
    return 0;
}
