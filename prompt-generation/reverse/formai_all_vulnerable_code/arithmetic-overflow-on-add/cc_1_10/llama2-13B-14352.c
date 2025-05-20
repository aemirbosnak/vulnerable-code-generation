//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 3

// Task structure
typedef struct {
    char *name;
    void (*function)(void);
    int priority;
    time_t start_time;
    time_t due_time;
} task_t;

// Global variables
task_t tasks[MAX_TASKS];
int task_count = 0;

// Function to add a task
void add_task(char *name, void (*function)(void), int priority) {
    task_t *new_task = (task_t *)calloc(1, sizeof(task_t));
    new_task->name = name;
    new_task->function = function;
    new_task->priority = priority;
    new_task->start_time = time(NULL);
    new_task->due_time = time(NULL) + (priority * 3600); // 3600 seconds per hour
    tasks[task_count++] = *new_task;
}

// Function to remove a task
void remove_task(char *name) {
    int i;
    for (i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            tasks[i].function = NULL;
            tasks[i].due_time = 0;
            break;
        }
    }
    if (i < task_count) {
        task_count--;
    }
}

// Function to check if a task is due
int is_task_due(char *name) {
    int i;
    for (i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            return (time(NULL) >= tasks[i].due_time);
        }
    }
    return 0;
}

// Function to print the list of tasks
void print_tasks() {
    int i;
    for (i = 0; i < task_count; i++) {
        printf("%s (%d): Due at %s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].due_time));
    }
}

// Main function
int main() {
    // Add some tasks
    add_task("Task 1", print_tasks, 1);
    add_task("Task 2", sleep(30), 2);
    add_task("Task 3", print_tasks, 3);

    // Start the task scheduler
    while (1) {
        // Check if any tasks are due
        if (is_task_due("Task 1")) {
            // Print the list of tasks
            print_tasks();
            // Execute the task
            tasks[0].function();
        }

        // Check if any tasks have been removed
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].function == NULL) {
                // Remove the task from the list
                memmove(&tasks[i], &tasks[i + 1], (task_count - i - 1) * sizeof(task_t));
                task_count--;
                break;
            }
        }

        // Sleep for a while
        sleep(1);
    }

    return 0;
}