//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of tasks and their priority levels
#define N_TASKS 5
#define PRIORITY_LEVELS 3

// Define a task struct to hold the task's name and priority level
typedef struct {
    char name[20];
    int priority;
} task_t;

// Define an array to hold the tasks
task_t tasks[N_TASKS];

// Initialize the tasks and their priority levels
void init_tasks() {
    int i;
    for (i = 0; i < N_TASKS; i++) {
        tasks[i].name[0] = 'T'; // Task name starts with 'T'
        tasks[i].priority = i % PRIORITY_LEVELS; // Priority level is 0, 1, or 2
    }
}

// Schedule the tasks based on their priority levels
void schedule_tasks() {
    int i, j;
    for (i = 0; i < N_TASKS; i++) {
        // Calculate the task's position in the schedule based on its priority level
        int position = tasks[i].priority * 3 + i;
        // Print the task name and its position in the schedule
        printf("Task %d: %s (priority %d) at position %d\n", i + 1, tasks[i].name, tasks[i].priority, position);
        // Add the task to the schedule at its calculated position
        tasks[position] = tasks[i];
    }
}

// Print the scheduled tasks
void print_schedule() {
    int i;
    for (i = 0; i < N_TASKS; i++) {
        printf("Task %d: %s (priority %d)\n", i + 1, tasks[i].name, tasks[i].priority);
    }
}

// Main program
int main() {
    srand(time(NULL)); // Seed the random number generator
    init_tasks(); // Initialize the tasks and their priority levels
    schedule_tasks(); // Schedule the tasks based on their priority levels
    print_schedule(); // Print the scheduled tasks
    return 0;
}