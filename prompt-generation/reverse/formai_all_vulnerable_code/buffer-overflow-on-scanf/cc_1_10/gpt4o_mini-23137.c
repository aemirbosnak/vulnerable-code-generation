//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    int priority; // A value from 1 (highest) to 5 (lowest)
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskScheduler;

// Function prototypes
void initScheduler(TaskScheduler *scheduler);
void displayMenu();
void addTask(TaskScheduler *scheduler);
void viewTasks(const TaskScheduler *scheduler);
void deleteTask(TaskScheduler *scheduler);
void prioritizeTasks(TaskScheduler *scheduler);
void clearBuffer();

int main() {
    TaskScheduler scheduler;
    initScheduler(&scheduler);
    
    int choice;
    do {
        displayMenu();
        printf("Make your choice (1-5): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear any buffer to avoid input issues

        switch (choice) {
            case 1: addTask(&scheduler); break;
            case 2: viewTasks(&scheduler); break;
            case 3: deleteTask(&scheduler); break;
            case 4: prioritizeTasks(&scheduler); break;
            case 5: printf("Exiting the Task Scheduler. Have a great day!\n"); break;
            default: printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initScheduler(TaskScheduler *scheduler) {
    scheduler->count = 0;
    printf("Welcome to the Task Scheduler! Get ready to organize your life!\n");
}

void displayMenu() {
    printf("\n==== Task Scheduler Menu ====\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Prioritize Tasks\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

void addTask(TaskScheduler *scheduler) {
    if (scheduler->count >= MAX_TASKS) {
        printf("Task list is full! Can't add more tasks.\n");
        return;
    }
    Task newTask;
    printf("Enter task title: ");
    fgets(newTask.title, MAX_TITLE_LENGTH, stdin);
    strtok(newTask.title, "\n"); // Remove newline character

    printf("Enter task description: ");
    fgets(newTask.description, MAX_DESC_LENGTH, stdin);
    strtok(newTask.description, "\n");

    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);
    clearBuffer();

    if (newTask.priority < 1 || newTask.priority > 5) {
        printf("Invalid priority! Please choose a value between 1 and 5.\n");
        return;
    }

    scheduler->tasks[scheduler->count++] = newTask;
    printf("Task '%s' added successfully!\n", newTask.title);
}

void viewTasks(const TaskScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks available! Time to create some!\n");
        return;
    }
    printf("\n===== List of Tasks =====\n");
    for (int i = 0; i < scheduler->count; i++) {
        Task currentTask = scheduler->tasks[i];
        printf("Task %d: %s\n", i + 1, currentTask.title);
        printf(" Description: %s\n", currentTask.description);
        printf(" Priority: %d\n", currentTask.priority);
    }
    printf("=========================\n");
}

void deleteTask(TaskScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks to delete!\n");
        return;
    }
    viewTasks(scheduler);
    int index;
    printf("Enter the task number to delete: ");
    scanf("%d", &index);
    clearBuffer();

    if (index < 1 || index > scheduler->count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = index - 1; i < scheduler->count - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }
    scheduler->count--;
    printf("Task %d deleted successfully!\n", index);
}

void prioritizeTasks(TaskScheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("There are no tasks to prioritize!\n");
        return;
    }
    for (int i = 0; i < scheduler->count - 1; i++) {
        for (int j = 0; j < scheduler->count - i - 1; j++) {
            if (scheduler->tasks[j].priority > scheduler->tasks[j + 1].priority) {
                Task temp = scheduler->tasks[j];
                scheduler->tasks[j] = scheduler->tasks[j + 1];
                scheduler->tasks[j + 1] = temp;
            }
        }
    }
    printf("Tasks have been prioritized based on the priority levels!\n");
}

void clearBuffer() {
    while(getchar() != '\n'); // Clear the input buffer
}