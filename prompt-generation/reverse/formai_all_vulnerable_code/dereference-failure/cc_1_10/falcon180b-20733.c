//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
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
} task_t;

task_t *task_list = NULL;

void add_task(void (*function)(void *arg), void *arg, int priority) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));

    if (new_task == NULL) {
        printf("Error: Unable to allocate memory for task.\n");
        exit(1);
    }

    new_task->function = function;
    new_task->arg = arg;
    new_task->priority = priority;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        task_t *current = task_list;

        while (current->next!= NULL && current->next->priority >= priority) {
            current = current->next;
        }

        new_task->next = current->next;
        current->next = new_task;
    }
}

void *task_thread(void *arg) {
    task_t *task = (task_t *) arg;

    task->function(task->arg);

    pthread_exit(NULL);
}

int main() {
    pthread_attr_t attr;
    pthread_t thread_id;
    int i, j;

    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, STACK_SIZE);

    for (i = 0; i < MAX_TASKS; i++) {
        add_task(task_thread, NULL, i);
    }

    for (j = 0; j < MAX_TASKS; j++) {
        pthread_create(&thread_id, &attr, task_thread, task_list);
        task_list = task_list->next;
    }

    for (j = 0; j < MAX_TASKS; j++) {
        pthread_join(thread_id, NULL);
    }

    return 0;
}