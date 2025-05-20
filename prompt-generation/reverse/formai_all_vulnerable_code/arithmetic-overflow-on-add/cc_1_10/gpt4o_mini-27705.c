//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    time_t execute_time;
    int interval; // in seconds
    int is_periodic; // 1 for periodic, 0 for one-time
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, time_t execute_time, int interval, int is_periodic) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    strncpy(tasks[task_count].name, name, NAME_LENGTH);
    tasks[task_count].execute_time = execute_time;
    tasks[task_count].interval = interval;
    tasks[task_count].is_periodic = is_periodic;
    task_count++;
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    // Here you can put the logic for the task to be executed
}

void remove_task(int index) {
    for (int i = index; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nTerminating Task Scheduler...\n");
        exit(0);
    }
}

void scheduler_loop() {
    while (1) {
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= tasks[i].execute_time) {
                execute_task(&tasks[i]);
                if (tasks[i].is_periodic) {
                    tasks[i].execute_time += tasks[i].interval;
                } else {
                    remove_task(i);
                    i--; // Adjust index after removal
                }
            }
        }

        sleep(1); // Sleep to avoid tight loop
    }
}

int main() {
    signal(SIGINT, signal_handler);

    // Adding some example tasks
    time_t now = time(NULL);
    add_task("Task 1", now + 5, 0, 0); // One-time task
    add_task("Task 2", now + 10, 0, 0); // One-time task
    add_task("Task 3", now + 2, 3, 1);  // Periodic task every 3 seconds
    add_task("Task 4", now + 4, 6, 1);  // Periodic task every 6 seconds

    printf("Task Scheduler started...\n");

    scheduler_loop(); // Start scheduling tasks

    return 0;
}