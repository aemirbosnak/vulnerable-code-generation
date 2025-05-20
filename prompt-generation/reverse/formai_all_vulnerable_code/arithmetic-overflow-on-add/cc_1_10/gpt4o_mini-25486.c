//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 32

typedef void (*task_func)();

typedef struct {
    char name[TASK_NAME_LEN];
    task_func func;
    int interval; // in seconds
    int next_run; // time to next run in seconds since epoch
} Task;

Task scheduler[MAX_TASKS];
int task_count = 0;
int running = 1;

void add_task(const char *name, task_func func, int interval) {
    if (task_count < MAX_TASKS) {
        strcpy(scheduler[task_count].name, name);
        scheduler[task_count].func = func;
        scheduler[task_count].interval = interval;
        scheduler[task_count].next_run = time(NULL) + interval;
        task_count++;
    } else {
        printf("Max tasks reached. Cannot add task: %s\n", name);
    }
}

void remove_task(const char *name) {
    for (int i = 0; i < task_count; i++) {
        if (strcmp(scheduler[i].name, name) == 0) {
            for (int j = i; j < task_count - 1; j++) {
                scheduler[j] = scheduler[j + 1];
            }
            task_count--;
            printf("Removed task: %s\n", name);
            return;
        }
    }
    printf("Task not found: %s\n", name);
}

void run_tasks() {
    while (running) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (current_time >= scheduler[i].next_run) {
                printf("Running task: %s\n", scheduler[i].name);
                scheduler[i].func();
                scheduler[i].next_run = current_time + scheduler[i].interval;
            }
        }
        sleep(1); // Sleep for a second before re-evaluating
    }
}

void interrupt_handler(int sig) {
    printf("Stopping scheduler... \n");
    running = 0;
}

void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void task3() {
    printf("Task 3 executed\n");
}

int main() {
    // Register interruption handler
    signal(SIGINT, interrupt_handler);
    
    // Add tasks to the scheduler
    add_task("Task 1", task1, 2); // Runs every 2 seconds
    add_task("Task 2", task2, 3); // Runs every 3 seconds
    add_task("Task 3", task3, 5); // Runs every 5 seconds
    
    printf("Starting task scheduler...\n");
    
    // Run the task scheduler
    run_tasks();

    // Cleanup actions if any
    printf("Scheduler exited.\n");
    return 0;
}