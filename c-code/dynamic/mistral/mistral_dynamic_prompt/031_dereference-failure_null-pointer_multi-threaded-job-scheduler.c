#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    int id;
    char *job;
} Job;

void *exec_job(void *arg) {
    Job *job = (Job *)arg;
    printf("Executing job: %s\n", job->job);
    free(job);
    return NULL;
}

int main() {
    pthread_t threads[5];
    Job jobs[5] = {
        {1, "Printing null"},
        {2, NULL},
        {3, "Printing more stuff"},
        {4, "Another job"},
        {5, "And one more"}
    };

    for (int i = 0; i < 5; ++i) {
        pthread_create(&threads[i], NULL, exec_job, &jobs[i]);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
