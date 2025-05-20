//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256
#define FILENAME "tasks.txt"

void addTask(const char* task) {
    FILE* file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file for adding task");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Added task: %s\n", task);
}

void viewTasks() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file for reading tasks");
        return;
    }
    
    char task[TASK_LENGTH];
    int count = 0;
    printf("Tasks:\n");
    while (fgets(task, sizeof(task), file)) {
        printf("%d: %s", ++count, task);
    }
    if (count == 0) {
        printf("No tasks available.\n");
    }
    fclose(file);
}

void deleteTask(int taskNumber) {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file for reading tasks");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        perror("Unable to open temporary file");
        fclose(file);
        return;
    }

    char task[TASK_LENGTH];
    int count = 0;
    while (fgets(task, sizeof(task), file)) {
        count++;
        if (count != taskNumber) {
            fputs(task, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);
    printf("Deleted task number: %d\n", taskNumber);
}

void displayMenu() {
    printf("\n--- Task Manager ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char task[TASK_LENGTH];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter your task: ");
                fgets(task, sizeof(task), stdin);
                task[strcspn(task, "\n")] = '\0'; // remove newline from task
                addTask(task);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task number to delete: ");
                int taskNumber;
                scanf("%d", &taskNumber);
                deleteTask(taskNumber);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}