//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: relaxed
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

void *thread_func(void *arg) {
    task_t *task = (task_t *) arg;
    task->func(task->arg);
    return NULL;
}

int task_compare(const void *a, const void *b) {
    task_t *task1 = (task_t *) a;
    task_t *task2 = (task_t *) b;
    return task1->priority - task2->priority;
}

void task_scheduler() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;
    pthread_t threads[MAX_TASKS];

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function and priority (0-9): ");
        void (*func)(void *arg) = NULL;
        int priority = 0;
        scanf("%p %d", &func, &priority);
        if (func == NULL || priority < 0 || priority > 9) {
            printf("Invalid input.\n");
            continue;
        }
        tasks[num_tasks].func = func;
        tasks[num_tasks].arg = NULL;
        tasks[num_tasks].priority = priority;
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(task_t), task_compare);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, thread_func, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    task_scheduler();
    return 0;
}