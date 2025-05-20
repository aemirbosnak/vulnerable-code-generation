#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    char name[100];
    int size;
    void (*function)(void*);
    void* argument;
} Job;

void overflow_function(void* arg) {
    char input[5];
    strcpy(input, (char*) arg);
    char temp[sizeof(input) + strlen(input) + 1];
    strcpy(temp, input);
    // Intentional integer overflow
    int i;
    for (i = 0; i > -strlen(temp); i++) {
        printf("%c", temp[i]);
    }
}

void run_job(Job* job) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, job->function, job->argument);
}

int main() {
    Job jobs[10];

    jobs[0].function = overflow_function;
    jobs[0].argument = "AAAAAA";
    jobs[0].size = strlen("AAAAAA") + 1;

    for (int i = 1; i < 10; i++) {
        jobs[i].function = run_job;
        jobs[i].argument = &jobs[i%10];
        jobs[i].size = sizeof(Job);
    }

    for (int i = 0; i < 10; i++) {
        run_job(&jobs[i]);
    }

    return 0;
}
