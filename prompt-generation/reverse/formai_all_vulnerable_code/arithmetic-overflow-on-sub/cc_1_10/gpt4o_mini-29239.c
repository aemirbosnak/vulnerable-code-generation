//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_DESC_LENGTH 256

typedef struct {
    int id;
    char description[TASK_DESC_LENGTH];
    struct tm time;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Oops! Unable to add more tasks. Maximum limit reached!\n");
        return;
    }
    
    Task newTask;
    newTask.id = taskCount + 1;

    printf("Enter the task description: ");
    getchar(); // Clear the newline character from previous input
    fgets(newTask.description, TASK_DESC_LENGTH, stdin);
    newTask.description[strcspn(newTask.description, "\n")] = 0; // Remove newline character

    printf("Enter the date and time for the task (YYYY-MM-DD HH:MM): ");
    scanf("%d-%d-%d %d:%d", &newTask.time.tm_year, &newTask.time.tm_mon, &newTask.time.tm_mday, 
           &newTask.time.tm_hour, &newTask.time.tm_min);
    newTask.time.tm_year -= 1900; // Adjust year
    newTask.time.tm_mon -= 1; // Adjust month from 1-12 to 0-11

    tasks[taskCount] = newTask;
    taskCount++;

    printf("Yay! Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("Oh no! You have no tasks scheduled!\n");
        return;
    }

    printf("\nYour Scheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task ID: %d\n", tasks[i].id);
        printf("Description: %s\n", tasks[i].description);
        printf("Scheduled Time: %04d-%02d-%02d %02d:%02d\n",
               tasks[i].time.tm_year + 1900, tasks[i].time.tm_mon + 1, tasks[i].time.tm_mday,
               tasks[i].time.tm_hour, tasks[i].time.tm_min);
        printf("--------------------------\n");
    }
}

void deleteTask() {
    if (taskCount == 0) {
        printf("Oh no! You have no tasks to delete!\n");
        return;
    }

    int taskId;
    printf("Enter the Task ID you wish to delete: ");
    scanf("%d", &taskId);

    if (taskId <= 0 || taskId > taskCount) {
        printf("Invalid Task ID! Please try again.\n");
        return;
    }

    for (int i = taskId - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;

    printf("Hooray! Task ID %d deleted successfully!\n", taskId);
}

void showMenu() {
    printf("\n--- Happy Task Scheduler ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;

    do {
        showMenu();
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
                printf("Thank you for using Happy Task Scheduler! Have a wonderful day!\n");
                break;
            default:
                printf("Oops! Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}