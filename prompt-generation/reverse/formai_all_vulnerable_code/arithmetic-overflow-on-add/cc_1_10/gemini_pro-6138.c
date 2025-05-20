//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100

typedef struct task {
    int id;
    time_t scheduled_time;
    void (*func)(void *);
    void *args;
} task_t;

typedef struct scheduler {
    task_t tasks[MAX_TASKS];
    int num_tasks;
} scheduler_t;

scheduler_t *scheduler_create() {
    scheduler_t *scheduler = malloc(sizeof(scheduler_t));
    if (scheduler == NULL) {
        return NULL;
    }
    scheduler->num_tasks = 0;
    return scheduler;
}

void scheduler_destroy(scheduler_t *scheduler) {
    free(scheduler);
}

int scheduler_add_task(scheduler_t *scheduler, time_t scheduled_time, void (*func)(void *), void *args) {
    if (scheduler->num_tasks >= MAX_TASKS) {
        return -1;
    }
    task_t *task = &scheduler->tasks[scheduler->num_tasks++];
    task->id = scheduler->num_tasks;
    task->scheduled_time = scheduled_time;
    task->func = func;
    task->args = args;
    return 0;
}

void scheduler_run(scheduler_t *scheduler) {
    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < scheduler->num_tasks; i++) {
            task_t *task = &scheduler->tasks[i];
            if (task->scheduled_time <= now) {
                task->func(task->args);
                scheduler->num_tasks--;
                for (int j = i; j < scheduler->num_tasks; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                i--;
            }
        }
        sleep(1);
    }
}

void task1(void *args) {
    printf("Task 1: Hello, world!\n");
}

void task2(void *args) {
    printf("Task 2: Goodbye, world!\n");
}

int main() {
    scheduler_t *scheduler = scheduler_create();
    scheduler_add_task(scheduler, time(NULL) + 1, task1, NULL);
    scheduler_add_task(scheduler, time(NULL) + 5, task2, NULL);
    scheduler_run(scheduler);
    scheduler_destroy(scheduler);
    return 0;
}