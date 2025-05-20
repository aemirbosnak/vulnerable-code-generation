//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 32

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    time_t scheduled_time;
    void (*task)(void);
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, time_t scheduled_time, void (*task)(void)) {
    if (num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Error: Maximum number of tasks reached\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].scheduled_time = scheduled_time;
    tasks[num_tasks].task = task;

    num_tasks++;
}

void run_tasks() {
    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].scheduled_time <= current_time) {
                tasks[i].task();
                tasks[i].scheduled_time = 0;  // Mark the task as completed
            }
        }

        sleep(1);
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

void task3() {
    printf("Task 3 running\n");
}

int main() {
    add_task("Task 1", time(NULL) + 5, task1);
    add_task("Task 2", time(NULL) + 10, task2);
    add_task("Task 3", time(NULL) + 15, task3);

    run_tasks();

    return 0;
}