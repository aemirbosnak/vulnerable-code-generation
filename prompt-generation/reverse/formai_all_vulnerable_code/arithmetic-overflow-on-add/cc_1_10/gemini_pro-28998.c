//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to represent a task.
typedef struct task {
    char *name;
    int priority;
    time_t scheduled_time;
} task;

// Function to compare two tasks by priority.
int compare_tasks(const void *a, const void *b) {
    const task *task1 = (const task *)a;
    const task *task2 = (const task *)b;
    return task1->priority - task2->priority;
}

// Function to print a task.
void print_task(const task *task) {
    printf("Task: %s, Priority: %d, Scheduled Time: %s\n", task->name, task->priority, ctime(&task->scheduled_time));
}

// Function to create a new task.
task *create_task(const char *name, int priority, time_t scheduled_time) {
    task *task = malloc(sizeof(task));
    task->name = strdup(name);
    task->priority = priority;
    task->scheduled_time = scheduled_time;
    return task;
}

// Function to schedule a task for a given time.
void schedule_task(task *task, time_t scheduled_time) {
    task->scheduled_time = scheduled_time;
}

// Function to get the current time.
time_t get_current_time() {
    return time(NULL);
}

// Function to run the task scheduler.
void run_task_scheduler(task *tasks, int num_tasks) {
    // Sort the tasks by priority.
    qsort(tasks, num_tasks, sizeof(task), compare_tasks);

    // Get the current time.
    time_t current_time = get_current_time();

    // Loop through the tasks and run any that are scheduled to run.
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].scheduled_time <= current_time) {
            printf("Running task: %s\n", tasks[i].name);
            print_task(&tasks[i]);
        }
    }
}

// Main function.
int main() {
    // Create a few tasks.
    task *tasks[] = {
        create_task("Send a love letter", 1, time(NULL) + 60 * 60),
        create_task("Buy flowers", 2, time(NULL) + 60 * 60 * 2),
        create_task("Make dinner", 3, time(NULL) + 60 * 60 * 3),
        create_task("Set the mood", 4, time(NULL) + 60 * 60 * 4),
    };

    // Run the task scheduler.
    run_task_scheduler(tasks, 4);

    // Free the tasks.
    for (int i = 0; i < 4; i++) {
        free(tasks[i]->name);
        free(tasks[i]);
    }

    return 0;
}