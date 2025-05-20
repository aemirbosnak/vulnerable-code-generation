#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 64

typedef struct {
    char name[32];
    void* (*func)(void*);
    void* arg;
} Task;

void* worker(void* arg) {
    Task* task = (Task*)arg;
    return task->func(task->arg);
}

void schedule(Task* tasks, int count) {
    pthread_t workers[MAX_THREADS];

    for (int i = 0; i < count; ++i) {
        pthread_create(&workers[i], NULL, worker, tasks + i);
    }

    for (int i = 0; i < count; ++i) {
        pthread_join(workers[i], NULL);
    }
}

void task_print(void* arg) {
    char input[BUFFER_SIZE];
    printf("Enter a task: ");
    scanf("%s", input);
    printf("Task: %s\n", input);
}

int main() {
    Task tasks[] = {
        {"Print task", task_print, NULL}
    };

    schedule(tasks, sizeof(tasks) / sizeof(Task));

    return 0;
}
