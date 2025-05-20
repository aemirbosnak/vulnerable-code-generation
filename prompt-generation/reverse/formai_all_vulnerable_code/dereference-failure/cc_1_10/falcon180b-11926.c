//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    char *name;
    int priority;
    void (*func)(void *arg);
    void *arg;
};

struct task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, void (*func)(void *arg), void *arg) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Too many tasks\n");
        return;
    }

    tasks[num_tasks].name = name;
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].func = func;
    tasks[num_tasks].arg = arg;

    num_tasks++;
}

void run_tasks() {
    pthread_t threads[MAX_TASKS];
    int i;

    for (i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, (void *)tasks[i].func, tasks[i].arg);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }
}

int compare_priorities(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

void sort_tasks() {
    qsort(tasks, num_tasks, sizeof(struct task), compare_priorities);
}

void task_func(void *arg) {
    printf("Running task: %s\n", ((struct task *)arg)->name);
}

int main() {
    add_task("Task A", 1, task_func, NULL);
    add_task("Task B", 2, task_func, NULL);
    add_task("Task C", 3, task_func, NULL);

    sort_tasks();

    run_tasks();

    return 0;
}