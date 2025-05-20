#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_JOBS 10
#define BUFF_SIZE 100

struct Job {
    char name[BUFF_SIZE];
    void (*func)(void*);
    void* arg;
};

struct Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];

void echo(void* args) {
    char* msg = (char*)args;
    write(STDOUT_FILENO, msg, strlen(msg) + 1);
}

void* run_job(void* job) {
    struct Job* job_data = (struct Job*)job;
    job_data->func(job_data->arg);
    return NULL;
}

void add_job(char* name, void (*func)(void*), void* arg) {
    for (int i = 0; i < MAX_JOBS; ++i) {
        if (!jobs[i].func) {
            strcpy(jobs[i].name, name);
            jobs[i].func = func;
            jobs[i].arg = arg;
            pthread_create(&threads[i], NULL, run_job, &jobs[i]);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    char buffer[BUFF_SIZE];
    while (1) {
        printf("Enter command: ");
        gets(buffer);
        add_job(buffer, &echo, NULL);
    }
    return 0;
}
