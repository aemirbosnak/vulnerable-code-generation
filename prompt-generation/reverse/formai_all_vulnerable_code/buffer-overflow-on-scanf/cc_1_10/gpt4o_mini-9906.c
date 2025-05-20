//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256
#define FILENAME "todo_list.txt"

// Function declarations
void addTask();
void viewTasks();
void deleteTask();

int main() {
    int choice;

    while (1) {
        printf("\n--- To-Do List Manager ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Please select an option: ");
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
                printf("Exiting program. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addTask() {
    FILE *file;
    char task[MAX_TASK_LENGTH];

    printf("Enter the task you want to add: ");
    getchar(); // Clear newline left by previous input
    fgets(task, sizeof(task), stdin);
    
    // Remove newline character if present
    task[strcspn(task, "\n")] = 0; 

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added: \"%s\"\n", task);
}

void viewTasks() {
    FILE *file;
    char task[MAX_TASK_LENGTH];
    int taskNumber = 1;

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- Your To-Do List ---\n");
    while (fgets(task, sizeof(task), file)) {
        printf("%d. %s", taskNumber++, task);
    }
    
    fclose(file);
    if (taskNumber == 1) {
        printf("Your To-Do list is empty.\n");
    }
}

void deleteTask() {
    FILE *file;
    FILE *tempFile;
    char task[MAX_TASK_LENGTH];
    char tempTask[MAX_TASK_LENGTH];
    int taskNumber, currentTaskNumber = 1;

    viewTasks();
    printf("Enter the task number you want to delete: ");
    scanf("%d", &taskNumber);

    file = fopen(FILENAME, "r");
    tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(task, sizeof(task), file)) {
        if (currentTaskNumber != taskNumber) {
            fprintf(tempFile, "%s", task);
        }
        currentTaskNumber++;
    }

    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    
    if (currentTaskNumber > 1) {
        printf("Task number %d deleted successfully.\n", taskNumber);
    } else {
        printf("No task found with number %d.\n", taskNumber);
    }
}