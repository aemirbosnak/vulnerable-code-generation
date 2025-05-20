//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store a task
typedef struct Task {
    int id;             // Unique ID of the task
    char *name;          // Name of the task
    int priority;       // Priority of the task (higher number means higher priority)
    time_t scheduled_time; // Time when the task is scheduled to run
} Task;

// Array to store all the tasks
Task tasks[100];

// Number of tasks
int num_tasks = 0;

// Function to add a task
void add_task(char *name, int priority, time_t scheduled_time) {
    // Create a new task
    Task task;
    task.id = num_tasks++;
    task.name = name;
    task.priority = priority;
    task.scheduled_time = scheduled_time;

    // Add the task to the array
    tasks[num_tasks - 1] = task;
}

// Function to print all the tasks
void print_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: %s (priority %d, scheduled at %s)\n", 
               tasks[i].id, tasks[i].name, tasks[i].priority, ctime(&tasks[i].scheduled_time));
    }
}

// Function to run the task scheduler
void run_scheduler() {
    // Get the current time
    time_t current_time = time(NULL);

    // Loop through all the tasks
    for (int i = 0; i < num_tasks; i++) {
        // If the task is scheduled to run now, run it
        if (tasks[i].scheduled_time == current_time) {
            printf("Running task %s\n", tasks[i].name);
            // Simulate running the task
            sleep(1);
        }
    }
}

int main() {
    // Add some tasks
    add_task("Task 1", 1, time(NULL) + 5);
    add_task("Task 2", 3, time(NULL) + 10);
    add_task("Task 3", 2, time(NULL) + 15);

    // Print the tasks
    print_tasks();

    // Run the scheduler
    run_scheduler();

    return 0;
}