//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    int priority;
    void (*func)(void *);
    void *arg;
} task_t;

void *task_runner(void *arg) {
    task_t *task = arg;
    task->func(task->arg);
    pthread_exit(NULL);
}

int task_compare(const void *a, const void *b) {
    const task_t *t1 = a;
    const task_t *t2 = b;
    if (t1->priority < t2->priority) {
        return -1;
    } else if (t1->priority > t2->priority) {
        return 1;
    } else {
        return 0;
    }
}

void task_scheduler() {
    pthread_t threads[10];
    task_t tasks[10];
    int task_count = 0;

    while (task_count < 10) {
        printf("Enter task ID, priority, and function name (in that order): ");
        scanf("%d %d %s", &tasks[task_count].id, &tasks[task_count].priority, tasks[task_count].func);
        tasks[task_count].arg = NULL;
        task_count++;
    }

    qsort(tasks, task_count, sizeof(task_t), task_compare);

    for (int i = 0; i < task_count; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
    }

    for (int i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    task_scheduler();
    return 0;
}