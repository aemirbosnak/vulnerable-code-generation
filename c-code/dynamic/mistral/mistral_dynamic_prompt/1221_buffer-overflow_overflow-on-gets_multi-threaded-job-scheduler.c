#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 100

typedef struct {
    char name[32];
    void (*func)(void);
    void *arg;
} Job;

Job jobs[MAX_THREADS];
pthread_t threads[MAX_THREADS];

void print_something(void) {
    char buffer[BUFFER_SIZE];
    gets(buffer);
    printf("You entered: %s\n", buffer);
}

void* execute_job(void *arg) {
    Job *job = (Job*) arg;
    job->func();
    free(job);
    return NULL;
}

int main() {
    char command[32];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        sprintf(command, "job%d", i);
        jobs[i].func = print_something;
        strcpy(jobs[i].name, command);
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
