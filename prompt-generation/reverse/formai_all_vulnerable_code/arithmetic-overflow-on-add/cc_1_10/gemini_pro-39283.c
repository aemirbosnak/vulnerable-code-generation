//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char *name;
    int interval; // in seconds
    int next_run; // in seconds since epoch
    void (*task)(void);
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int interval, void (*task)(void)) {
    if (num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Error: too many tasks\n");
        return;
    }

    tasks[num_tasks].name = strdup(name);
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].next_run = time(NULL) + interval;
    tasks[num_tasks].task = task;
    num_tasks++;
}

void run_tasks() {
    while (1) {
        int i;
        time_t now = time(NULL);

        // Check if any tasks need to be run
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].next_run <= now) {
                tasks[i].task();
                tasks[i].next_run += tasks[i].interval;
            }
        }

        // Sleep for one second
        sleep(1);
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

int main() {
    add_task("task1", 5, task1);
    add_task("task2", 10, task2);

    run_tasks();

    return 0;
}