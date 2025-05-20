//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 32
#define TASK_INTERVAL_MAX 1000

typedef struct task {
    char name[MAX_NAME_LEN];
    time_t next_run;
    int interval;
    void (*func)(void);
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int interval, void (*func)(void)) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Too many tasks\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].func = func;
    tasks[num_tasks].next_run = time(NULL) + interval;

    num_tasks++;
}

void run_tasks() {
    time_t now = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].next_run <= now) {
            tasks[i].func();
            tasks[i].next_run = now + tasks[i].interval;
        }
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
    add_task("task1", 1000, task1);
    add_task("task2", 2000, task2);
    add_task("task3", 3000, task3);

    while (1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}