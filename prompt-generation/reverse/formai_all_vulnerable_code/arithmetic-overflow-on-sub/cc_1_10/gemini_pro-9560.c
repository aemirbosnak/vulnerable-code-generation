//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10

struct task {
    int id;
    time_t scheduled_time;
    void (*function)(void *);
    void *args;
};

struct task_scheduler {
    struct task tasks[MAX_TASKS];
    int num_tasks;
};

void task_scheduler_init(struct task_scheduler *scheduler) {
    scheduler->num_tasks = 0;
}

int task_scheduler_add_task(struct task_scheduler *scheduler, struct task *task) {
    if (scheduler->num_tasks >= MAX_TASKS) {
        return -1;
    }

    scheduler->tasks[scheduler->num_tasks++] = *task;
    return 0;
}

void task_scheduler_run(struct task_scheduler *scheduler) {
    while (scheduler->num_tasks > 0) {
        struct task *task = &scheduler->tasks[0];
        time_t now = time(NULL);

        if (task->scheduled_time <= now) {
            task->function(task->args);
            scheduler->num_tasks--;
            memmove(&scheduler->tasks[0], &scheduler->tasks[1], sizeof(struct task) * scheduler->num_tasks);
        } else {
            sleep(task->scheduled_time - now);
        }
    }
}

void task_function(void *args) {
    printf("Task %d executed\n", (int)args);
}

int main() {
    struct task_scheduler scheduler;
    task_scheduler_init(&scheduler);

    struct task task1 = {
        .id = 1,
        .scheduled_time = time(NULL) + 5,
        .function = task_function,
        .args = (void *)1
    };

    struct task task2 = {
        .id = 2,
        .scheduled_time = time(NULL) + 10,
        .function = task_function,
        .args = (void *)2
    };

    struct task task3 = {
        .id = 3,
        .scheduled_time = time(NULL) + 15,
        .function = task_function,
        .args = (void *)3
    };

    task_scheduler_add_task(&scheduler, &task1);
    task_scheduler_add_task(&scheduler, &task2);
    task_scheduler_add_task(&scheduler, &task3);

    task_scheduler_run(&scheduler);

    return 0;
}