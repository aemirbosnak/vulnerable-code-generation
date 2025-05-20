//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    time_t execTime;
    int isActive;
} Task;

// Global array to hold tasks
Task taskList[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void addTask(const char *name, time_t execTime);
void removeTask(const char *name);
void executeTasks();
void printTasks();
void sigHandler(int signo);

// Main function
int main() {
    signal(SIGINT, sigHandler); // Register signal handler for termination

    while (1) {
        int choice;
        char name[MAX_NAME_LEN];
        time_t execTime;

        printf("Task Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Execute Tasks\n");
        printf("4. Print Scheduled Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter execution time (YYYY-MM-DD HH:MM:SS): ");
                char dateTimeStr[20];
                fgets(dateTimeStr, sizeof(dateTimeStr), stdin);
                struct tm tm = {0};
                strptime(dateTimeStr, "%Y-%m-%d %H:%M:%S", &tm);
                execTime = mktime(&tm);

                addTask(name, execTime);
                break;

            case 2:
                printf("Enter task name to remove: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                removeTask(name);
                break;

            case 3:
                executeTasks();
                break;

            case 4:
                printTasks();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a task
void addTask(const char *name, time_t execTime) {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (strcmp(taskList[i].name, name) == 0) {
            printf("Task with this name already exists.\n");
            return;
        }
    }

    strcpy(taskList[taskCount].name, name);
    taskList[taskCount].execTime = execTime;
    taskList[taskCount].isActive = 1;
    taskCount++;

    printf("Task '%s' scheduled for %s", name, ctime(&execTime));
}

// Function to remove a task
void removeTask(const char *name) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(taskList[i].name, name) == 0 && taskList[i].isActive) {
            taskList[i].isActive = 0; // Mark task as inactive
            printf("Task '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("Task '%s' not found.\n", name);
}

// Function to execute tasks
void executeTasks() {
    time_t now = time(NULL);
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].isActive && taskList[i].execTime <= now) {
            printf("Executing task: '%s' at %s", taskList[i].name, ctime(&now));
            taskList[i].isActive = 0; // Mark task as executed
        }
    }
}

// Function to print scheduled tasks
void printTasks() {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].isActive) {
            printf("Task: '%s', Execution Time: %s", taskList[i].name, ctime(&taskList[i].execTime));
        }
    }
    printf("\n");
}

// Signal handler for cleanup
void sigHandler(int signo) {
    printf("\nExiting Task Scheduler.\n");
    exit(0);
}