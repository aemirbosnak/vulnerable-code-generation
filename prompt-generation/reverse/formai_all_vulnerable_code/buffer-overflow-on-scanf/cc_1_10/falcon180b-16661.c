//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void (*func)(void *);
    void *arg;
};

void *task_runner(void *param) {
    struct task *task = (struct task *)param;
    task->func(task->arg);
    return NULL;
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int i, j, max_priority = 0;

    for (i = 0; i < MAX_TASKS; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority (0-9): ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task function: ");
        scanf("%p", &tasks[i].func);
        printf("Enter task argument: ");
        scanf("%p", &tasks[i].arg);

        if (tasks[i].priority > max_priority) {
            max_priority = tasks[i].priority;
        }
    }

    for (i = 0; i < MAX_TASKS; i++) {
        for (j = 0; j < MAX_TASKS - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                struct task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
        printf("Task %s (priority %d) started\n", tasks[i].name, tasks[i].priority);
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}