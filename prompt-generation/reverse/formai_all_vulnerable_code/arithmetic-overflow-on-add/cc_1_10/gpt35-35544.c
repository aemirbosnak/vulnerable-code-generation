//FormAI DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks
#define MAX_TASKS 100

// Define the maximum length of task names
#define MAX_TASK_NAME_LENGTH 50

// Define the Task structure
typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    int frequency; // in seconds
    bool active;
    time_t last_execution;
    void (*task_function)(void); // function pointer to the task function
} Task;

// Define an array to hold tasks
Task tasks[MAX_TASKS];

// Define the number of tasks currently in the scheduler
int num_tasks = 0;

// Define helper function declarations
void add_task(void (*task_func)(void), char *task_name, int task_priority, int task_frequency);
bool remove_task(char *task_name);
void execute_tasks(void);
void task1(void);
void task2(void);
void task3(void);


int main() {
    // Add some example tasks
    add_task(task1, "Task 1", 1, 5);
    add_task(task2, "Task 2", 2, 10);
    add_task(task3, "Task 3", 3, 15);

    // Execute tasks repeatedly
    while (true) {
        execute_tasks();
    }
    return 0;
}

void add_task(void (*task_func)(void), char *task_name, int task_priority, int task_frequency) {
    // Check if there is space for a new task
    if (num_tasks == MAX_TASKS) {
        printf("Cannot add task. Maximum number of tasks reached.\n");
        return;
    }

    // Add the task
    Task new_task;
    strcpy(new_task.name, task_name);
    new_task.priority = task_priority;
    new_task.frequency = task_frequency;
    new_task.active = true;
    new_task.last_execution = time(NULL); // set last_execution to current time
    new_task.task_function = task_func;
    tasks[num_tasks++] = new_task;
}

bool remove_task(char *task_name) {
    // Find the task with the given name
    int task_index = -1;
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, task_name) == 0) {
            task_index = i;
            break;
        }
    }

    // If task not found, return false
    if (task_index == -1) {
        printf("Task not found.\n");
        return false;
    }

    // Remove the task by shifting the remaining tasks one position to the left
    for (int i = task_index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    num_tasks--;
    printf("Task \"%s\" removed.\n", task_name);

    return true;
}

void execute_tasks(void) {
    // Loop through all tasks
    for (int i = 0; i < num_tasks; i++) {
        // Check if task is active and its frequency has passed since its last execution
        if (tasks[i].active && time(NULL) >= tasks[i].last_execution + tasks[i].frequency) {
            // Execute the task
            tasks[i].task_function();
            // Update the last_execution time of the task
            tasks[i].last_execution = time(NULL);
        }
    }
}

void task1(void) {
    printf("Executing Task 1...\n");
}

void task2(void) {
    printf("Executing Task 2...\n");
}

void task3(void) {
    printf("Executing Task 3...\n");
}