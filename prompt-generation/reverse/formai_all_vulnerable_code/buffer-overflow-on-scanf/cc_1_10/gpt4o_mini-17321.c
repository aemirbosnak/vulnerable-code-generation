//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int id;
} Task;

Task *taskList[MAX_TASKS];
int taskCount = 0;

void addTask(const char *title) {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    
    Task *newTask = (Task *)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    strncpy(newTask->title, title, MAX_TITLE_LENGTH);
    newTask->id = taskCount + 1;
    
    taskList[taskCount] = newTask;
    taskCount++;
    
    printf("Task added: [%d] %s\n", newTask->id, newTask->title);
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    printf("Current Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("[%d] %s\n", taskList[i]->id, taskList[i]->title);
    }
}

void deleteTask(int id) {
    if (id <= 0 || id > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }
    
    int index = id - 1;
    
    free(taskList[index]);
    for (int i = index; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    
    taskCount--;
    printf("Task [%d] deleted.\n", id);
}

void freeTasks() {
    for (int i = 0; i < taskCount; i++) {
        free(taskList[i]);
    }
    taskCount = 0;
    printf("All tasks cleared.\n");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    
    while (1) {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task title: ");
                scanf(" %[^\n]%*c", title); // Read a line with spaces
                addTask(title);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task ID to delete: ");
                int id;
                scanf("%d", &id);
                deleteTask(id);
                break;
            case 4:
                freeTasks();
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}