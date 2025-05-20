//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int priority; // Lower number indicates higher priority
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskScheduler;

// Function to initialize the task scheduler
void initScheduler(TaskScheduler *scheduler) {
    scheduler->count = 0;
}

// Function to add a task
void addTask(TaskScheduler *scheduler, const char *name, int priority) {
    if (scheduler->count < MAX_TASKS) {
        strncpy(scheduler->tasks[scheduler->count].name, name, TASK_NAME_LENGTH);
        scheduler->tasks[scheduler->count].priority = priority;
        scheduler->count++;
        printf("Task '%s' added with priority %d.\n", name, priority);
    } else {
        printf("Task scheduler is full. Can't add new task.\n");
    }
}

// Function to display all tasks
void displayTasks(TaskScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nPending Tasks:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("Task: '%s', Priority: %d\n", scheduler->tasks[i].name, scheduler->tasks[i].priority);
    }
}

// Function to compare tasks by priority for sorting
int compareTasks(const void *a, const void *b) {
    return ((Task *)a)->priority - ((Task *)b)->priority;
}

// Function to execute tasks in priority order
void executeTasks(TaskScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks to execute.\n");
        return;
    }
    // Sort tasks by priority
    qsort(scheduler->tasks, scheduler->count, sizeof(Task), compareTasks);
    
    printf("\nExecuting Tasks in order of priority:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("Executing task: '%s' with priority %d...\n", scheduler->tasks[i].name, scheduler->tasks[i].priority);
        // Simulate task execution
        // In a real application, you might call a function or perform an operation here
    }
    // Reset task count after execution
    scheduler->count = 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTask Scheduler Menu:\n");
    printf("1. Add Task\n");
    printf("2. Display Tasks\n");
    printf("3. Execute Tasks\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    TaskScheduler scheduler;
    initScheduler(&scheduler);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1: {
                char taskName[TASK_NAME_LENGTH];
                int priority;
                printf("Enter task name: ");
                fgets(taskName, TASK_NAME_LENGTH, stdin);
                taskName[strcspn(taskName, "\n")] = 0; // Remove newline character
                printf("Enter task priority (lower number for higher priority): ");
                scanf("%d", &priority);
                addTask(&scheduler, taskName, priority);
                break;
            }
            case 2:
                displayTasks(&scheduler);
                break;
            case 3:
                executeTasks(&scheduler);
                break;
            case 4:
                printf("Exiting Task Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}