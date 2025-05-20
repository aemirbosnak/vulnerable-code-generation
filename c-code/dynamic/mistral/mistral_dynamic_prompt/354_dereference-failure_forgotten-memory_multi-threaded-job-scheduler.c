#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *job;
} Job;

Job *jobs;
int num_jobs = 10;
pthread_mutex_t jobs_mutex;

void *execute_job(void *arg) {
    int i = *(int *)arg;
    pthread_mutex_lock(&jobs_mutex);
    printf("Starting job: %s (Thread ID: %lu)\n", jobs[i].job, pthread_self());
    free(jobs[i].job);
    pthread_mutex_unlock(&jobs_mutex);
    // Dereference null pointer after freeing the memory
    printf("Processing job: %s (Thread ID: %lu)\n", jobs[i].job, pthread_self());
    pthread_exit(0);
}

int main() {
    pthread_t threads[num_jobs];
    srand(time(NULL));

    jobs = malloc(num_jobs * sizeof(Job));
    for (int i = 0; i < num_jobs; i++) {
        jobs[i].id = i;
        jobs[i].job = malloc(20 * sizeof(char));
        snprintf(jobs[i].job, 20, "Job %d", i);
    }

    pthread_mutex_init(&jobs_mutex, NULL);

    for (int i = 0; i < num_jobs; i++) {
        pthread_create(&threads[i], NULL, execute_job, &i);
    }

    for (int i = 0; i < num_jobs; i++) {
        pthread_join(threads[i], NULL);
    }

    free(jobs);
    pthread_mutex_destroy(&jobs_mutex);

    return 0;
}
