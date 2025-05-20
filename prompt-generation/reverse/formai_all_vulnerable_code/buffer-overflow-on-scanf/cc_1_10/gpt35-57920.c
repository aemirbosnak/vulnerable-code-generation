//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be scheduled
#define MAX_PRIORITY 5 // Maximum priority level for a task
#define MAX_DURATION 100 // Maximum duration in seconds for a task

// Structure for holding information about each task
typedef struct {
    int id;
    int priority;
    int duration;
} Task;

// Function to generate a random integer in the given range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to initialize the task list with random values
void initialize_tasks(Task* tasks, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = get_random_number(1, MAX_PRIORITY);
        tasks[i].duration = get_random_number(1, MAX_DURATION);
    }
}

// Function to print the current task list
void print_task_list(Task* tasks, int num_tasks) {
    printf("Current Task List:\n");
    printf("==================\n");
    printf("ID  | Priority | Duration\n");
    printf("=========================\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%2d  |     %2d   |    %3d   \n", tasks[i].id, tasks[i].priority, tasks[i].duration);
    }
}

// Function to execute a task and return the time taken to execute it
int execute_task(Task* task) {
    printf("Executing Task ID: %d (Priority %d, Duration %d seconds)\n", task->id, task->priority, task->duration);
    int start_time = time(NULL);
    while (time(NULL) - start_time < task->duration) {
        // Do nothing
    }
    printf("Task ID: %d completed.\n", task->id);
    return task->duration;
}

// Function to schedule and execute the tasks
void schedule_tasks(Task* tasks, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        print_task_list(tasks, num_tasks);
        Task* current_task = &tasks[i];
        int time_taken = execute_task(current_task);
        printf("Time taken to execute Task ID %d: %d seconds.\n", current_task->id, time_taken);
    }
    printf("All tasks completed successfully.\n");
}

int main() {
    srand(time(NULL)); // Initialize the random number generator
    Task tasks[MAX_TASKS];
    int num_tasks;
    printf("Enter the number of tasks to schedule (1-10): ");
    scanf("%d", &num_tasks);
    if (num_tasks < 1 || num_tasks > 10) {
        printf("Invalid number of tasks entered. Program terminated.");
        return 0;
    }
    initialize_tasks(tasks, num_tasks);
    printf("Task initialization complete.\n");
    schedule_tasks(tasks, num_tasks);
    return 0;
}