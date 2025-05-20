//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

typedef struct task {
    void (*func)(void *arg);
    void *arg;
    int priority;
} task_t;

void *task_runner(void *param) {
    task_t *task = (task_t *) param;
    task->func(task->arg);
    return NULL;
}

int main() {
    pthread_t threads[MAX_TASKS];
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function (or 'done' to finish): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter task priority (0-9): ");
        scanf("%d", &tasks[num_tasks].priority);

        tasks[num_tasks].func = (void *) input;
        num_tasks++;
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}