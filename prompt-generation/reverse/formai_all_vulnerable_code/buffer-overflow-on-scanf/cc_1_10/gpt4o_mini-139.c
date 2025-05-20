//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256

void addTask(const char *task);
void listTasks();
void deleteTask(int taskNumber);
void clearBuffer();

int main() {
    int choice;
    char task[TASK_LENGTH];
    
    printf("🎉 Welcome to the Task Manager! 🎉\n");
    
    while (1) {
        printf("\n1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter your task: ");
                fgets(task, TASK_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove the newline character
                addTask(task);
                break;
            case 2:
                listTasks();
                break;
            case 3: {
                int taskNumber;
                printf("Enter task number to delete: ");
                scanf("%d", &taskNumber);
                deleteTask(taskNumber);
                break;
            }
            case 4:
                printf("Exiting Task Manager... Goodbye! 👋\n");
                exit(0);
            default:
                printf("🚨 Invalid Choice! Please select between 1 to 4.\n");
        }
    }
    
    return 0;
}

void addTask(const char *task) {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("⚠️ Error opening the file for writing!\n");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("✅ Task added successfully!\n");
}

void listTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("⚠️ Error opening the file for reading!\n");
        return;
    }
    
    char task[TASK_LENGTH];
    int taskNumber = 1;
    printf("\n📝 Your Tasks:\n");
    
    while (fgets(task, TASK_LENGTH, file) != NULL) {
        printf("%d. %s", taskNumber, task);
        taskNumber++;
    }
    fclose(file);
    
    if (taskNumber == 1) {
        printf("🗑️ No tasks found! Add some tasks to your list!\n");
    }
}

void deleteTask(int taskNumber) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("⚠️ Error opening the file!\n");
        return;
    }
    
    char tasks[MAX_TASKS][TASK_LENGTH];
    int count = 0;
    
    while (fgets(tasks[count], TASK_LENGTH, file) != NULL && count < MAX_TASKS) {
        count++;
    }
    fclose(file);
    
    if (taskNumber < 1 || taskNumber > count) {
        printf("🚨 Invalid Task Number!\n");
        return;
    }
    
    file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("⚠️ Error opening the file for writing!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (i != taskNumber - 1) {
            fprintf(file, "%s", tasks[i]);
        }
    }
    fclose(file);
    
    printf("✅ Task number %d deleted successfully!\n", taskNumber);
}

void clearBuffer() {
    while (getchar() != '\n');
}