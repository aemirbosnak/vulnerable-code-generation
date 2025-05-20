//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100
#define MAX_TASKS 50
#define FILENAME "todo.txt"

void clearScreen() {
    // Clear the console screen for a fresher view
    printf("\033[H\033[J");
}

void addTask() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    char task[MAX_TASK_LENGTH];
    printf("Enter your task: ");
    getchar(); // Consume the newline left by previous input
    fgets(task, MAX_TASK_LENGTH, stdin);
    task[strcspn(task, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added successfully!\n");
}

void viewTasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No tasks found! Please add some tasks first.\n");
        return;
    }

    char task[MAX_TASK_LENGTH];
    int taskCount = 1;
    printf("\nYour Todo List:\n");
    while (fgets(task, sizeof(task), file)) {
        task[strcspn(task, "\n")] = 0; // Remove newline character
        printf("%d. %s\n", taskCount++, task);
    }
    fclose(file);
}

void deleteTask() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No tasks to delete! Please add some tasks first.\n");
        return;
    }

    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int taskCount = 0;

    while (fgets(tasks[taskCount], sizeof(tasks[taskCount]), file)) {
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; // Remove newline
        taskCount++;
    }
    fclose(file);

    if (taskCount == 0) {
        printf("No tasks to delete!\n");
        return;
    }

    printf("\nYour Todo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }

    int taskNum;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNum);

    if (taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    FILE *newFile = fopen(FILENAME, "w");
    if (newFile == NULL) {
        printf("Error creating a new file!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (i != (taskNum - 1)) {
            fprintf(newFile, "%s\n", tasks[i]);
        }
    }

    fclose(newFile);
    printf("Task %d deleted successfully!\n", taskNum);
}

int main() {
    int choice;
    do {
        clearScreen();
        printf("===================================\n");
        printf("           Todo List Menu         \n");
        printf("===================================\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("Press Enter to continue...");
        getchar(); // Clear newline from input buffer
        getchar(); // Wait for Enter
    } while (choice != 4);

    return 0;
}