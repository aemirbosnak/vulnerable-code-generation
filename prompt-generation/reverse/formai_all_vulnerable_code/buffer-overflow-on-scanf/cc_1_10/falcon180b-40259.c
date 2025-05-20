//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    void (*task_func)(void *);
    void *task_arg;
} Task;

void *task_runner(void *arg) {
    Task *task = (Task *) arg;
    task->task_func(task->task_arg);
    return NULL;
}

int main() {
    pthread_t threads[MAX_TASKS];
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    if (num_tasks > MAX_TASKS) {
        printf("Error: Maximum number of tasks is %d\n", MAX_TASKS);
        return 1;
    }

    printf("Enter task IDs, functions, and arguments:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].task_id);
        printf("Function: ");
        void (*func)(void *) = NULL;
        scanf("%p", &func);
        tasks[i].task_func = func;
        printf("Argument: ");
        tasks[i].task_arg = NULL;
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}