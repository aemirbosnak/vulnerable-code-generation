//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LENGTH 256

struct task {
    int pid;
    int start_time;
    int end_time;
    char description[MAX_DESCRIPTION_LENGTH];
};

struct schedule {
    int num_tasks;
    struct task tasks[MAX_TASKS];
};

void add_task(struct schedule *schedule, char *description) {
    int i;

    for (i = 0; i < schedule->num_tasks; i++) {
        if (strcmp(schedule->tasks[i].description, description) == 0) {
            break;
        }
    }

    if (i == schedule->num_tasks) {
        schedule->tasks[i].pid = getpid();
        schedule->tasks[i].start_time = clock();
        schedule->tasks[i].end_time = clock() + 10; // 10 seconds
        strcpy(schedule->tasks[i].description, description);
        schedule->num_tasks++;
    }
}

void run_tasks(struct schedule *schedule) {
    int i;

    for (i = 0; i < schedule->num_tasks; i++) {
        if (clock() >= schedule->tasks[i].start_time && clock() <= schedule->tasks[i].end_time) {
            // Task is currently running
            printf("Task %d is running\n", schedule->tasks[i].pid);
        } else {
            // Task has finished or is not running
            printf("Task %d has finished\n", schedule->tasks[i].pid);
            schedule->tasks[i].pid = 0;
        }
    }
}

int main() {
    struct schedule schedule;

    schedule.num_tasks = 0;

    char *task_descriptions[] = {"Task 1", "Task 2", "Task 3"};
    int i;

    for (i = 0; i < sizeof(task_descriptions) / sizeof(char *); i++) {
        add_task(&schedule, task_descriptions[i]);
    }

    run_tasks(&schedule);

    return 0;
}