//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int priority;
    void (*func)(void *);
    void *arg;
} Task;

void execute_task(void *arg) {
    Task task = *(Task *)arg;
    task.func(task.arg);
}

int compare_priority(const void *a, const void *b) {
    Task task_a = *(Task *)a;
    Task task_b = *(Task *)b;
    if (task_a.priority > task_b.priority) {
        return 1;
    } else if (task_a.priority < task_b.priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    pthread_t threads[MAX_TASKS];
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task ID and priority (0-9): ");
        scanf("%d%d", &tasks[num_tasks].id, &tasks[num_tasks].priority);
        printf("Enter task function and argument: ");
        scanf("%p%p", &tasks[num_tasks].func, &tasks[num_tasks].arg);
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, execute_task, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}