//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int priority;          // Lower number means higher priority
    time_t scheduled_time; // Time when the task is scheduled
} Task;

// Function definitions
void add_task(Task tasks[], int *task_count);
void view_tasks(Task tasks[], int task_count);
void execute_tasks(Task tasks[], int *task_count);
void sort_tasks(Task tasks[], int task_count);

// Main function
int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice;

    while (1) {
        printf("\n--- Simple Task Scheduler ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                view_tasks(tasks, task_count);
                break;
            case 3:
                execute_tasks(tasks, &task_count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a task
void add_task(Task tasks[], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Task limit reached! Cannot add more tasks.\n");
        return;
    }

    Task new_task;
    printf("Enter task name: ");
    getchar(); // Consume the leftover newline
    fgets(new_task.name, TASK_NAME_LENGTH, stdin);
    new_task.name[strcspn(new_task.name, "\n")] = 0; // Remove newline

    printf("Enter task priority (lower number means higher priority): ");
    scanf("%d", &new_task.priority);

    new_task.scheduled_time = time(NULL); // Set current time as scheduled time
    tasks[*task_count] = new_task;
    (*task_count)++;
    printf("Task added successfully!\n");
}

// Function to view all tasks
void view_tasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    printf("\n--- Scheduled Tasks ---\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s | Priority: %d | Scheduled Time: %s", 
               i + 1, tasks[i].name, tasks[i].priority, ctime(&tasks[i].scheduled_time));
    }
}

// Function to execute tasks based on priority
void execute_tasks(Task tasks[], int *task_count) {
    if (*task_count == 0) {
        printf("No tasks to execute.\n");
        return;
    }

    sort_tasks(tasks, *task_count); // Sort tasks by priority

    printf("\n--- Executing Tasks ---\n");
    for (int i = 0; i < *task_count; i++) {
        printf("Executing task: %s\n", tasks[i].name);
        sleep(1); // Simulates task execution
    }

    *task_count = 0; // Clear all tasks after execution
    printf("All tasks executed successfully!\n");
}

// Function to sort tasks based on priority
void sort_tasks(Task tasks[], int task_count) {
    for (int i = 0; i < task_count - 1; i++) {
        for (int j = i + 1; j < task_count; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}