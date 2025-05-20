#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_NAME_LENGTH 256
#define MAX_TASK_COUNT 100

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    void (*func)(void* arg);
    void* arg;
} Task;

Task tasks[MAX_TASK_COUNT];
pthread_t thread_ids[MAX_TASK_COUNT];

void job_function(void* arg) {
    printf("Running job: %s\n", ((Task*)arg)->name);
}

void schedule_job(Task* task) {
    pthread_create(&thread_ids[task - tasks], NULL, job_function, task);
}

void parse_command_line(int argc, char* argv[]) {
    int i;
    for (i = 1; i < argc; ++i) {
        Task* task = &tasks[i - 1];
        strcpy(task->name, argv[i]);
        task->func = job_function;
        task->arg = task;
        schedule_job(task);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s JOB1 [JOB2 ...]\n", argv[0]);
        return 1;
    }
    parse_command_line(argc, argv);

    // Buffer overflow vulnerability intentionally introduced
    char input[10];
    fscanf(stdin, "%9s", input);

    return 0;
}
