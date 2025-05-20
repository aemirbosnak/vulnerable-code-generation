//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void *(*func)(void *);
    void *arg;
    int period;
    int remaining;
};

void *task_runner(void *arg) {
    struct task *task = (struct task *) arg;
    while (1) {
        usleep(task->period * 1000);
        task->remaining--;
        if (task->remaining == 0) {
            task->remaining = task->period;
            task->func(task->arg);
        }
    }
    return NULL;
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *) a;
    struct task *task_b = (struct task *) b;
    return task_a->priority - task_b->priority;
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    if (num_tasks > MAX_TASKS) {
        printf("Error: Maximum number of tasks is %d\n", MAX_TASKS);
        return 1;
    }

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task function: ");
        scanf("%p", &tasks[i].func);
        printf("Enter task argument: ");
        scanf("%p", &tasks[i].arg);
        printf("Enter task period (in milliseconds): ");
        scanf("%d", &tasks[i].period);
        tasks[i].remaining = tasks[i].period;
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}