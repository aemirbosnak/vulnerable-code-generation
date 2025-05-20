//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK_LENGTH 256
#define FILE_NAME "todolist.txt"

// Function to display the menu
void displayMenu() {
    printf("\n================ To-Do List Menu ================\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
    printf("===================================================\n");
}

// Function to add a task to the file
void addTask() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    
    char task[TASK_LENGTH];
    printf("Enter the task to add: ");
    getchar(); // clear newline character from input buffer
    fgets(task, TASK_LENGTH, stdin);
    
    // Remove newline character
    task[strcspn(task, "\n")] = '\0';
    
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added successfully!\n");
}

// Function to view all tasks from the file
void viewTasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    char task[TASK_LENGTH];
    printf("\n================ Current Tasks ================\n");
    int index = 1;
    while (fgets(task, TASK_LENGTH, file)) {
        printf("[%d] %s", index++, task);
    }
    printf("===================================================\n");
    fclose(file);
}

// Function to delete a task
void deleteTask() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    // Count tasks
    char *tasks[100];
    char task[TASK_LENGTH];
    int taskCount = 0;
    while (fgets(task, TASK_LENGTH, file)) {
        tasks[taskCount] = strdup(task);
        taskCount++;
    }
    fclose(file);
    
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    // View tasks and get the task index to delete
    viewTasks();
    int taskToDelete;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskToDelete);
    
    if (taskToDelete < 1 || taskToDelete > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    // Rewrite the file without the deleted task
    file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (i != (taskToDelete - 1)) {
            fprintf(file, "%s", tasks[i]);
        }
        free(tasks[i]);
    }
    
    fclose(file);
    printf("Task deleted successfully!\n");
}

// Main function
int main() {
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}