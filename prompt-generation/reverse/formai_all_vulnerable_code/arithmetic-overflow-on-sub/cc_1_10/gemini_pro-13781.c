//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_INTERVAL 1

typedef struct {
    int id;
    int interval;
    time_t last_run;
    void (*func)(void*);
    void* arg;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(int interval, void (*func)(void*), void* arg) {
    if (num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Error: Maximum number of tasks reached\n");
        return;
    }

    tasks[num_tasks].id = num_tasks;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].last_run = time(NULL);
    tasks[num_tasks].func = func;
    tasks[num_tasks].arg = arg;

    num_tasks++;
}

void run_tasks() {
    while (1) {
        // Get the current time
        time_t now = time(NULL);

        // Check each task to see if it needs to be run
        for (int i = 0; i < num_tasks; i++) {
            if (now - tasks[i].last_run >= tasks[i].interval) {
                // Run the task
                tasks[i].func(tasks[i].arg);

                // Update the last run time
                tasks[i].last_run = now;
            }
        }

        // Sleep for TASK_INTERVAL seconds
        sleep(TASK_INTERVAL);
    }
}

void task1(void* arg) {
    printf("Task 1 running\n");
}

void task2(void* arg) {
    printf("Task 2 running\n");
}

int main() {
    // Add some tasks to the scheduler
    add_task(5, task1, NULL);
    add_task(10, task2, NULL);

    // Run the task scheduler
    run_tasks();

    return 0;
}