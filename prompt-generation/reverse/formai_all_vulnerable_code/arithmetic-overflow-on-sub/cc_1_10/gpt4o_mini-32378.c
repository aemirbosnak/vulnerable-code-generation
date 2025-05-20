//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    struct tm dueDate;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

// Function to add a task
void addTask(char *name, int year, int month, int day) {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full! Can't add more tasks.\n");
        return;
    }
    strcpy(taskList[taskCount].name, name);
    taskList[taskCount].dueDate.tm_year = year - 1900; // tm_year is years since 1900
    taskList[taskCount].dueDate.tm_mon = month - 1; // tm_mon is months since January
    taskList[taskCount].dueDate.tm_mday = day;
    taskList[taskCount].dueDate.tm_hour = 0;
    taskList[taskCount].dueDate.tm_min = 0;
    taskList[taskCount].dueDate.tm_sec = 0;
    taskList[taskCount].dueDate.tm_isdst = -1; // Daylight saving time flag
    taskCount++;
    printf("Task '%s' added for %04d-%02d-%02d!\n", name, year, month, day);
}

// Function to remove a task
void removeTask(char *name) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(taskList[i].name, name) == 0) {
            printf("Removing task '%s'...\n", taskList[i].name);
            for (int j = i; j < taskCount - 1; j++) {
                taskList[j] = taskList[j + 1];
            }
            taskCount--;
            printf("Task '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("Task '%s' not found! Can't remove it!\n", name);
}

// Function to view all tasks
void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list. Let's add some!\n");
        return;
    }
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s - Due date: %04d-%02d-%02d\n", i + 1, taskList[i].name,
               taskList[i].dueDate.tm_year + 1900,
               taskList[i].dueDate.tm_mon + 1,
               taskList[i].dueDate.tm_mday);
    }
}

int menu() {
    int choice;
    printf("\n====== Task Scheduler ======\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. View Tasks\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    printf("Welcome to the Task Scheduler!\n");
    while (1) {
        int choice = menu();
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1: {
                char taskName[TASK_NAME_LENGTH];
                int year, month, day;

                printf("Enter task name: ");
                fgets(taskName, TASK_NAME_LENGTH, stdin);
                taskName[strcspn(taskName, "\n")] = '\0'; // Remove the newline

                printf("Enter due date (YYYY MM DD): ");
                scanf("%d %d %d", &year, &month, &day);
                addTask(taskName, year, month, day);
                break;
            }
            case 2: {
                char taskName[TASK_NAME_LENGTH];

                printf("Enter task name to remove: ");
                fgets(taskName, TASK_NAME_LENGTH, stdin);
                taskName[strcspn(taskName, "\n")] = '\0'; // Remove the newline

                removeTask(taskName);
                break;
            }
            case 3:
                viewTasks();
                break;
            case 4:
                printf("Exiting the Task Scheduler! Goodbye! 🌟\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}