#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    char *job;
    char *args;
} Job;

void *exec_job(void *data) {
    Job *job = (Job *)data;
    char *command = malloc(strlen(job->job) + strlen(job->args) + 2);
    sprintf(command, "%s %s", job->job, job->args);
    system(command);
    free(command);
    free(job);
    pthread_exit(NULL);
}

int main() {
    const char *jobs[] = {"cat", "echo", "ls", "grep", "top"};
    const char *args[] = {"/nonexistent/file", "Hello, World!", "./logs", ".bashrc", NULL};

    pthread_t threads[5];
    Job jobs_data[5];

    for (int i = 0; i < 5; ++i) {
        jobs_data[i].job = jobs[i];
        jobs_data[i].args = args[i];
        sscanf(jobs_data[i].args, "%[^\n]", jobs_data[i].args);
        pthread_create(&threads[i], NULL, exec_job, &jobs_data[i]);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
