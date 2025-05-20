#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define JOB_SIZE 2048

typedef struct {
    int id;
    char task[JOB_SIZE];
} Job;

Job jobs[MAX_JOBS];
pthread_mutex_t jobs_lock;
int job_count = 0;

void *job_function(void *arg) {
    int i;
    char *job = (char *) arg;

    for (i = 0; i < JOB_SIZE - 1; ++i)
        job[i] += job[i]; // Intentional integer overflow

    pthread_mutex_lock(&jobs_lock);
    jobs[job_count].id = pthread_self();
    strncpy(jobs[job_count].task, job, JOB_SIZE - 1);
    job_count++;
    pthread_mutex_unlock(&jobs_lock);

    printf("Job ID: %lu with task: %s executed\n", pthread_self(), jobs[job_count - 1].task);

    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    char jobs[][JOB_SIZE] = {
        "A large task",
        "Another large task",
        "Yet another large task",
        "Etc. (many large tasks)"
    };

    pthread_mutex_init(&jobs_lock, NULL);

    for (int i = 0; i < 5; ++i)
        pthread_create(&threads[i], NULL, job_function, jobs[i]);

    for (int i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&jobs_lock);

    return 0;
}
