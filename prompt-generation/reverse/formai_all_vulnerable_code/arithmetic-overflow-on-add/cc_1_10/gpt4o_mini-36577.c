//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    time_t execute_time;
    void (*task_function)(void);
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

TaskScheduler scheduler;

// Function to print the current time
void print_current_time() {
    time_t now = time(NULL);
    printf("Current Time: %s", ctime(&now));
}

// Example task functions
void task_one() {
    printf("Executing Task One: %s\n", ctime(&(scheduler.tasks[0].execute_time)));
}

void task_two() {
    printf("Executing Task Two: %s\n", ctime(&(scheduler.tasks[1].execute_time)));
}

// Adds a new task to the scheduler
void add_task(char *name, time_t execute_time, void (*task_function)(void)) {
    if (scheduler.task_count < MAX_TASKS) {
        strcpy(scheduler.tasks[scheduler.task_count].name, name);
        scheduler.tasks[scheduler.task_count].execute_time = execute_time;
        scheduler.tasks[scheduler.task_count].task_function = task_function;
        scheduler.task_count++;
        printf("Task '%s' scheduled for execution at %s", name, ctime(&execute_time));
    } else {
        printf("Task limit reached! Cannot add more tasks.\n");
    }
}

// Execute the tasks whose time has come
void execute_tasks() {
    time_t now;
    while (scheduler.task_count > 0) {
        now = time(NULL);
        for (int i = 0; i < scheduler.task_count; i++) {
            if (scheduler.tasks[i].execute_time <= now) {
                scheduler.tasks[i].task_function();
                // Shift remaining tasks forward
                for (int j = i; j < scheduler.task_count - 1; j++) {
                    scheduler.tasks[j] = scheduler.tasks[j + 1];
                }
                scheduler.task_count--;
                i--;  // Decrement i to check the next task
            }
        }
        sleep(1);  // Sleep for a while to prevent busy waiting
    }
}

// Main function
int main() {
    scheduler.task_count = 0;

    // Schedule tasks
    time_t current_time = time(NULL);
    add_task("Sample Task One", current_time + 5, task_one);
    add_task("Sample Task Two", current_time + 10, task_two);

    // Print the initial time and scheduled tasks
    print_current_time();
    printf("Scheduled tasks:\n");
    for (int i = 0; i < scheduler.task_count; i++) {
        printf(" - %s at %s", scheduler.tasks[i].name, ctime(&(scheduler.tasks[i].execute_time)));
    }

    execute_tasks();
    return 0;
}