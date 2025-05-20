//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 32
#define MAX_TASK_DESCRIPTION_LENGTH 256

typedef struct {
    int id;
    char name[MAX_TASK_NAME_LENGTH];
    char description[MAX_TASK_DESCRIPTION_LENGTH];
    time_t scheduled_time;
    int priority;
    int status;
} task_t;

typedef struct {
    int num_tasks;
    task_t tasks[MAX_TASKS];
} task_scheduler_t;

task_scheduler_t task_scheduler;

void task_scheduler_init() {
    task_scheduler.num_tasks = 0;
}

int task_scheduler_add_task(task_t *task) {
    if (task_scheduler.num_tasks >= MAX_TASKS) {
        return -1;
    }

    task_scheduler.tasks[task_scheduler.num_tasks++] = *task;

    return 0;
}

task_t *task_scheduler_get_next_task() {
    int i;
    task_t *task = NULL;

    for (i = 0; i < task_scheduler.num_tasks; i++) {
        if (task_scheduler.tasks[i].status == 0 && task_scheduler.tasks[i].scheduled_time <= time(NULL)) {
            task = &task_scheduler.tasks[i];
            break;
        }
    }

    return task;
}

void task_scheduler_run_task(task_t *task) {
    printf("Running task: %s\n", task->name);
    printf("Task description: %s\n", task->description);

    task->status = 1;
}

void task_scheduler_loop() {
    task_t *task;

    while (1) {
        task = task_scheduler_get_next_task();

        if (task == NULL) {
            printf("No tasks to run.\n");
            sleep(1);
            continue;
        }

        task_scheduler_run_task(task);
    }
}

int main() {
    task_t task1 = {
        .id = 1,
        .name = "Task 1",
        .description = "This is task 1.",
        .scheduled_time = time(NULL) + 10,
        .priority = 1,
        .status = 0
    };

    task_t task2 = {
        .id = 2,
        .name = "Task 2",
        .description = "This is task 2.",
        .scheduled_time = time(NULL) + 20,
        .priority = 2,
        .status = 0
    };

    task_t task3 = {
        .id = 3,
        .name = "Task 3",
        .description = "This is task 3.",
        .scheduled_time = time(NULL) + 30,
        .priority = 3,
        .status = 0
    };

    task_scheduler_init();
    task_scheduler_add_task(&task1);
    task_scheduler_add_task(&task2);
    task_scheduler_add_task(&task3);

    task_scheduler_loop();

    return 0;
}