//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

typedef struct task {
    void (*function)(void *arg);
    void *arg;
    int priority;
    struct task *next;
} Task;

Task *task_list = NULL;

void add_task(void (*function)(void *), void *arg, int priority) {
    Task *new_task = malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    new_task->function = function;
    new_task->arg = arg;
    new_task->priority = priority;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        Task *current = task_list;
        while (current->next!= NULL && current->next->priority >= priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
    }
}

void *task_thread(void *param) {
    Task *task = param;
    task->function(task->arg);
    free(task);
    return NULL;
}

int main() {
    add_task(task_thread, NULL, 0);
    add_task(task_thread, NULL, 1);
    add_task(task_thread, NULL, 2);

    pthread_t threads[MAX_TASKS];
    int i = 0;

    while (i < MAX_TASKS && task_list!= NULL) {
        Task *task = task_list;
        task_list = task_list->next;
        pthread_create(&threads[i], NULL, task_thread, task);
        i++;
    }

    for (int j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}