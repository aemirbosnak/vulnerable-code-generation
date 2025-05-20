//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100
#define MAX_TASKS 100
#define FILE_NAME "todo_list.txt"

void addTask();
void viewTasks();
void clearBuffer();

int main() {
    int choice;

    printf("🎉 Welcome to the TADA To-Do List Manager! 🎉\n");

    do {
        printf("\n===== Main Menu =====\n");
        printf("1. Add a Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);
        
        clearBuffer();  // Clear buffer to avoid any trash input
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("🎈 Thank you for using TADA. See you next time! 🎈\n");
                break;
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void addTask() {
    char task[MAX_TASK_LENGTH];
    FILE *file;

    printf("✨ Enter your task (max %d characters): ", MAX_TASK_LENGTH - 1);
    fgets(task, sizeof(task), stdin);
    task[strcspn(task, "\n")] = 0;  // Remove trailing newline

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("❌ Error opening file! Could not add task.\n");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);

    printf("✔️ Task added successfully: \"%s\"\n", task);
}

void viewTasks() {
    char task[MAX_TASK_LENGTH];
    FILE *file;

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("📄 No tasks found! Your to-do list is empty. 📄\n");
        return;
    }

    printf("\n🌟 Your To-Do List 🌟\n");
    int taskCount = 1;
    while (fgets(task, sizeof(task), file)) {
        printf("%d. %s", taskCount++, task);
    }
    fclose(file);
    printf("✨ End of list!\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}