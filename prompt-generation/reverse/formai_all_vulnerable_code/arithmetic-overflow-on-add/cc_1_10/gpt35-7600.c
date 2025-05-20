//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5 // Maximum number of tasks
#define MAX_TASK_NAME_LENGTH 25 // Maximum length of task names

// Struct for a single task
typedef struct Task {
    char name[MAX_TASK_NAME_LENGTH]; // Task name
    int priority; // Task priority
    int duration; // Task duration in seconds
    time_t scheduled_time; // Time when the task is scheduled to run
} Task;

// Function to initialize a task
void initialize_task(Task *task, char *name, int priority, int duration) {
    // Copy the task name into the struct
    int i;
    for (i = 0; i < MAX_TASK_NAME_LENGTH - 1 && name[i] != '\0'; i++) {
        task->name[i] = name[i];
    }
    task->name[i] = '\0';

    // Set the task priority and duration
    task->priority = priority;
    task->duration = duration;

    // Set the scheduled time to 0
    task->scheduled_time = 0;
}

// Function to print a task
void print_task(Task task) {
    printf("Task Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d seconds\n", task.duration);
    printf("Scheduled Time: %s", ctime(&task.scheduled_time));
}

// Function to schedule a task
void schedule_task(Task *task, time_t current_time, int interval) {
    // Calculate the scheduled time for the task
    task->scheduled_time = current_time + interval;

    // Print the scheduled task
    printf("Task Scheduled at: %s", ctime(&task->scheduled_time));
}

// Function to check if a task is ready to run
int is_task_ready(Task task, time_t current_time) {
    // Check if the scheduled time for the task is less than or equal to the current time
    if (task.scheduled_time <= current_time) {
        return 1;
    } else {
        return 0;
    }
}

// Program entry point
int main() {
    // Initialize the tasks
    Task tasks[MAX_TASKS];
    initialize_task(&tasks[0], "Task 1", 1, 5);
    initialize_task(&tasks[1], "Task 2", 2, 10);
    initialize_task(&tasks[2], "Task 3", 3, 15);
    initialize_task(&tasks[3], "Task 4", 4, 20);
    initialize_task(&tasks[4], "Task 5", 5, 25);

    // Set the interval to run the tasks
    int interval = 5;

    // Set the start time for the tasks
    time_t start_time = time(NULL);

    // Loop through until all the tasks have been completed
    int i, num_tasks_completed = 0;
    while (num_tasks_completed < MAX_TASKS) {
        // Get the current time
        time_t current_time = time(NULL);

        // Check which tasks are ready to run
        for (i = 0; i < MAX_TASKS; i++) {
            if (is_task_ready(tasks[i], current_time)) {
                // Run the task and schedule it for the next run
                printf("Running task %d...\n", i+1);
                schedule_task(&tasks[i], current_time, interval);
                if (tasks[i].duration == interval) {
                    num_tasks_completed++;
                }
            }
        }
    }

    printf("All tasks completed!");

    return 0;
}