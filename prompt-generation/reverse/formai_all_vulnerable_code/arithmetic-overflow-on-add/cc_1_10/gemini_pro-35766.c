//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    int id;
    char *name;
    time_t start_time;
    time_t end_time;
    int status; // 0: not started, 1: running, 2: completed
} task;

task tasks[MAX_TASKS];
int num_tasks = 0;

void create_task(char *name, time_t start_time, time_t end_time) {
    if (num_tasks == MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }
    
    task *new_task = &tasks[num_tasks++];
    new_task->id = num_tasks;
    new_task->name = strdup(name);
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->status = 0;

    printf("Task %s created.\n", name);
}

void print_tasks() {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        task *task = &tasks[i];
        printf("  %d: %s (start: %s, end: %s, status: %d)\n", 
               task->id, task->name, ctime(&task->start_time), ctime(&task->end_time), task->status);
    }
}

void run_scheduler() {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        task *task = &tasks[i];

        if (task->status == 0 && task->start_time <= current_time) {
            task->status = 1;
            printf("Task %s started.\n", task->name);
        }

        if (task->status == 1 && task->end_time <= current_time) {
            task->status = 2;
            printf("Task %s completed.\n", task->name);
        }
    }
}

int main() {
    create_task("Task 1", time(NULL) + 60, time(NULL) + 120);
    create_task("Task 2", time(NULL) + 120, time(NULL) + 180);
    create_task("Task 3", time(NULL) + 180, time(NULL) + 240);

    print_tasks();

    while (1) {
        run_scheduler();
        sleep(1);
    }

    return 0;
}