#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 16

typedef struct {
    char name[BUFFER_SIZE];
    char command[BUFFER_SIZE];
} Job;

Job jobs[MAX_JOBS];
pthread_mutex_t jobs_mutex = PTHREAD_MUTEX_INITIALIZER;
int num_jobs = 0;

void *execute_job(void *arg) {
    printf("Executing job: %s\n", ((Job *)arg)->command);
    sleep(3);
    printf("Finished executing job: %s\n", ((Job *)arg)->command);
    pthread_exit(NULL);
}

void add_job(const char *name, const char *command) {
    pthread_mutex_lock(&jobs_mutex);
    if (num_jobs < MAX_JOBS) {
        strcpy(jobs[num_jobs].name, name);
        strcpy(jobs[num_jobs].command, command);
        num_jobs++;
    }
    pthread_mutex_unlock(&jobs_mutex);
}

int main(int argc, char *argv[]) {
    int i;
    pthread_t threads[MAX_JOBS];

    for (i = 1; i < argc; ++i) {
        Job new_job;
        fscanf(stdin, "Name: %s\nCommand: %s", new_job.name, new_job.command);
        add_job(new_job.name, new_job.command);
        pthread_create(&threads[i - 1], NULL, execute_job, &jobs[i - 1]);
    }

    for (i = 0; i < argc - 1; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
