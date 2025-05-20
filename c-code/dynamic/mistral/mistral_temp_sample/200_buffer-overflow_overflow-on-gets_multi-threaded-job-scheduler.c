#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 16

typedef struct Job {
    char name[BUFFER_SIZE];
    void (*function)(void*);
    void* arguments;
} Job;

Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];

void echo_function(void* args) {
    char* input = (char*)args;
    printf("%s\n", input);
}

void add_job(char* name, void (*function)(void*), void* arguments) {
    for (int i = 0; i < MAX_JOBS; ++i) {
        if (!jobs[i].function) {
            strcpy(jobs[i].name, name);
            jobs[i].function = function;
            jobs[i].arguments = arguments;
            pthread_create(&threads[i], NULL, (void*(*)(void*))function, arguments);
            break;
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter the job name and arguments (in format: job_name args1 args2 ...):\n");

    while (1) {
        gets(buffer);
        add_job(buffer, &echo_function, NULL);
    }

    return 0;
}
