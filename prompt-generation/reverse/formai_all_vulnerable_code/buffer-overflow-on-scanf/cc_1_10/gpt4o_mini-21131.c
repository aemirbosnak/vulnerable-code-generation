//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    int id;
    char name[TASK_NAME_LENGTH];
} Task;

void addTask(Task tasks[], int *taskCount);
void viewTasks(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int *taskCount);
int findTaskIndex(Task tasks[], int taskCount, int id);
void clearBuffer();

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        printf("\n=== Task Management System ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline left in the buffer

        switch(choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }

    Task newTask;
    newTask.id = *taskCount + 1; // simple auto-incrementing id
    printf("Enter task name: ");
    fgets(newTask.name, TASK_NAME_LENGTH, stdin);
    newTask.name[strcspn(newTask.name, "\n")] = '\0'; // Remove newline character

    tasks[*taskCount] = newTask;
    (*taskCount)++;
    printf("Task added with ID %d\n", newTask.id);
}

void viewTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- List of Tasks ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("ID: %d, Task Name: %s\n", tasks[i].id, tasks[i].name);
    }
}

void deleteTask(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &id);
    clearBuffer();

    int index = findTaskIndex(tasks, *taskCount, id);
    if (index == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    // Shift tasks to remove the deleted task
    for (int i = index; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--; // Reduce task count
    printf("Task with ID %d deleted successfully.\n", id);
}

int findTaskIndex(Task tasks[], int taskCount, int id) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            return i;
        }
    }
    return -1; // Task not found
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}