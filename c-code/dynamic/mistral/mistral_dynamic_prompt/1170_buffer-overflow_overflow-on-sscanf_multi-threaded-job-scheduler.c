#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define BUFFER_SIZE 16

typedef struct Task {
    char name[BUFFER_SIZE];
    void (*function)(void* arg);
    void* arg;
} Task;

Task tasks[MAX_TASKS];
pthread_mutex_t tasks_mutex;

void run_task(void *arg) {
    Task *task = (Task *)arg;
    task->function(task->arg);
}

void enqueue_task(Task task) {
    pthread_mutex_lock(&tasks_mutex);
    for (int i = 0; i < MAX_TASKS; ++i) {
        if (tasks[i].function == NULL) {
            tasks[i] = task;
            pthread_create(&tasks[i].function, NULL, &run_task, &tasks[i]);
            break;
        }
    }
    pthread_mutex_unlock(&tasks_mutex);
}

int main() {
    pthread_mutex_init(&tasks_mutex, NULL);

    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i].function = NULL;
    }

    char buffer[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%s", buffer);
        Task task = { buffer, NULL, NULL };
        sscanf(buffer, "%*s %d", &task.function); // Vulnerable sscanf with no checks on buffer size
        enqueue_task(task);
    }

    // Other main application code (not included)

    return 0;
}
