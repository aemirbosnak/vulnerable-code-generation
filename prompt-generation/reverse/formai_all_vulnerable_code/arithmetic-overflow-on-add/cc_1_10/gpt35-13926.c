//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of tasks in the scheduler
#define MAX_TASKS 10

// Struct definition for each task
typedef struct {
    char name[100];
    int priority;
    time_t deadline;
    bool completed;
} Task;

// Struct definition for the task scheduler
typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} TaskScheduler;

// Function to add a task to the scheduler
void add_task(TaskScheduler *scheduler, char* name, int priority, time_t deadline) {
    if (scheduler->num_tasks < MAX_TASKS) {
        Task new_task;
        strcpy(new_task.name, name);
        new_task.priority = priority;
        new_task.deadline = deadline;
        new_task.completed = false;
        
        scheduler->tasks[scheduler->num_tasks] = new_task;
        scheduler->num_tasks++;
        printf("Task added: %s\n", name);
    } else {
        printf("Error: Maximum number of tasks reached.\n");
    }
}

// Function to remove a task from the scheduler
void remove_task(TaskScheduler *scheduler, int task_index) {
    if (task_index >= 0 && task_index < scheduler->num_tasks) {
        for (int i = task_index; i < scheduler->num_tasks - 1; i++) {
            scheduler->tasks[i] = scheduler->tasks[i+1];
        }
        scheduler->num_tasks--;
        printf("Task removed.\n");
    } else {
        printf("Error: Invalid task index.\n");
    }
}

// Function to print the list of tasks in the scheduler
void print_tasks(TaskScheduler *scheduler) {
    printf("\nTask list:\n");
    for (int i = 0; i < scheduler->num_tasks; i++) {
        Task task = scheduler->tasks[i];
        char* status = task.completed ? "Completed" : "Incomplete";
        
        char deadline_str[50];
        strftime(deadline_str, sizeof(deadline_str), "%Y-%m-%d %H:%M:%S", localtime(&task.deadline));
        
        printf("%d. %s (Priority: %d, Deadline: %s, Status: %s)\n", i+1, task.name, task.priority, deadline_str, status);
    }
}

// Function to mark a task as completed
void complete_task(TaskScheduler *scheduler, int task_index) {
    if (task_index >= 0 && task_index < scheduler->num_tasks) {
        scheduler->tasks[task_index].completed = true;
        printf("Task completed.\n");
    } else {
        printf("Error: Invalid task index.\n");
    }
}

int main() {
    TaskScheduler scheduler;
    scheduler.num_tasks = 0;
    
    // Add some tasks to the scheduler
    add_task(&scheduler, "Finish project", 2, time(NULL) + 86400);
    add_task(&scheduler, "Buy groceries", 1, time(NULL) + 7200);
    add_task(&scheduler, "Feed the cat", 3, time(NULL) + 3600);
     
    // Print the list of tasks
    print_tasks(&scheduler);
    
    // Complete task #2
    complete_task(&scheduler, 1);
    
    // Print the updated list of tasks
    print_tasks(&scheduler);
    
    // Remove task #3
    remove_task(&scheduler, 2);
    
    // Print the updated list of tasks
    print_tasks(&scheduler);
    
    return 0;
}