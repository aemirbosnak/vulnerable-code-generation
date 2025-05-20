//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 100

typedef struct {
    char name[TASK_NAME_LEN];
    time_t time; // Storing time for the task
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask();
void removeTask();
void listTasks();
void clearInputBuffer();
void displayMenu();
void executeScheduledTasks();

int main() {
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                listTasks();
                break;
            case 4:
                executeScheduledTasks();
                break;
            case 0:
                printf("Exiting Task Scheduler.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addTask() {
    if(taskCount >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    Task newTask;
    printf("Enter task name: ");
    fgets(newTask.name, TASK_NAME_LEN, stdin);
    newTask.name[strcspn(newTask.name, "\n")] = 0; // Remove newline character

    printf("Enter time for task (YYYY-MM-DD HH:MM:SS): ");
    struct tm tm;
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);
    strptime(buffer, "%Y-%m-%d %H:%M:%S", &tm);
    
    newTask.time = mktime(&tm);
    if (newTask.time == -1) {
        printf("Invalid time format. Task not added.\n");
        return;
    }
    
    taskList[taskCount++] = newTask;
    printf("Task '%s' added successfully!\n", newTask.name);
}

void removeTask() {
    listTasks();
    if(taskCount == 0) return;

    printf("Enter the index of the task to remove: ");
    int idx;
    scanf("%d", &idx);
    clearInputBuffer();

    if (idx < 0 || idx >= taskCount) {
        printf("Invalid index. Task not removed.\n");
        return;
    }

    for (int i = idx; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    taskCount--;
    printf("Task removed successfully.\n");
}

void listTasks() {
    if(taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        char timeBuffer[20];
        struct tm *tm_info = localtime(&taskList[i].time);
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%d: %s at %s\n", i, taskList[i].name, timeBuffer);
    }
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void displayMenu() {
    printf("\n--- Task Scheduler ---\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. List Tasks\n");
    printf("4. Execute Scheduled Tasks\n");
    printf("0. Exit\n");
}

void executeScheduledTasks() {
    time_t now = time(NULL);
    printf("Executing Tasks...\n");
    
    for (int i = 0; i < taskCount; i++) {
        if (difftime(taskList[i].time, now) <= 0) {
            printf("Executing task: %s\n", taskList[i].name);
            // Here you could trigger an actual task execution
            // For simulation, let's just print it
            removeTask(); // Remove the task afterward
            i--; // Adjust index after removal
        }
    }
}