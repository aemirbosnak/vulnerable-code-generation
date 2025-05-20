//FormAI DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be scheduled
#define MAX_TASK_NAME_LENGTH 20 // Maximum length of task name

// Struct to store a single task
typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    int duration;
    int estimated_time_left;
} Task;

// Array of tasks to be scheduled
Task tasks[MAX_TASKS];

// Function to prompt the user for task information
void prompt_user_for_task_info(Task* task) {
    printf("Enter task name: ");
    scanf("%s", task->name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &task->priority);
    printf("Enter task duration (in minutes): ");
    scanf("%d", &task->duration);

    task->estimated_time_left = task->duration;
}

// Function to print task information
void print_task_info(Task* task) {
    printf("Task: %s\n", task->name);
    printf("Priority: %d\n", task->priority);
    printf("Duration: %d minutes\n", task->duration);
}

int main() {
    int num_tasks;
    printf("How many tasks would you like to schedule? (up to %d) ", MAX_TASKS);
    scanf("%d", &num_tasks);

    // Prompt the user for task information and store in tasks array
    for (int i = 0; i < num_tasks; i++) {
        Task task;
        prompt_user_for_task_info(&task);
        tasks[i] = task;
    }

    // Sort the tasks by priority (highest first)
    for (int i = 0; i < num_tasks; i++) {
        for (int j = i+1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Print out the schedule
    int current_time = 0;
    printf("Scheduled tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].estimated_time_left > 0) {
            printf("Task %d:\n", i+1);
            print_task_info(&tasks[i]);
            printf("Start time: %d minutes\n", current_time);
            current_time += tasks[i].duration;
            printf("End time: %d minutes\n\n", current_time);
        }
    }

    return 0;
}