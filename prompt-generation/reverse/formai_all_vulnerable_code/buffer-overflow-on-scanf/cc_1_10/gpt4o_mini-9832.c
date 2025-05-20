//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TASKS 100
#define TASK_DESC_LENGTH 100

typedef struct {
    char description[TASK_DESC_LENGTH];
    int hour;
    int minute;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Oh no! The task scheduler is full! Cannot add more tasks!\n");
        return;
    }

    Task newTask;

    printf("What shocking task do you want to schedule? ");
    fgets(newTask.description, TASK_DESC_LENGTH, stdin);
    newTask.description[strcspn(newTask.description, "\n")] = '\0';  // Remove trailing newline

    printf("At what hour do you want to schedule this task? (0-23): ");
    scanf("%d", &newTask.hour);
    printf("At what minute do you want to schedule this task? (0-59): ");
    scanf("%d", &newTask.minute);
    getchar();  // To consume the newline character left by scanf

    if (newTask.hour < 0 || newTask.hour >= 24 || newTask.minute < 0 || newTask.minute >= 60) {
        printf("Invalid time provided! Task scheduling failed!\n");
        return;
    }

    taskList[taskCount++] = newTask;
    printf("Task added! You scheduled: \"%s\" at %02d:%02d\n", newTask.description, newTask.hour, newTask.minute);
}

void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks scheduled! What a shocker!\n");
        return;
    }

    printf("Here are your scheduled tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task #%d: \"%s\" at %02d:%02d\n", i + 1, taskList[i].description, taskList[i].hour, taskList[i].minute);
    }
}

void removeTask() {
    if (taskCount == 0) {
        printf("Nothing to delete, the horror!\n");
        return;
    }

    int taskIndex;
    printf("Which task number do you want to remove? (1-%d): ", taskCount);
    scanf("%d", &taskIndex);
    getchar();  // To consume the newline character left by scanf

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number! No task deleted, how shocking!\n");
        return;
    }

    for (int i = taskIndex - 1; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    taskCount--;
    printf("Task #%d removed! Now that’s a dramatic twist!\n", taskIndex);
}

void displayMenu() {
    printf("\nTask Scheduler Menu:\n");
    printf("1. Add Task\n");
    printf("2. Display Tasks\n");
    printf("3. Remove Task\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting the scheduler... What a plot twist!\n");
                exit(0);
            default:
                printf("Invalid choice! Absolutely shocking!!\n");
                break;
        }
    }

    return 0;
}