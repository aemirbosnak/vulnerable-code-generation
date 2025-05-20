//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t executionTime;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask(char *name, time_t executionTime) {
    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, TASK_NAME_LENGTH - 1);
        taskList[taskCount].name[TASK_NAME_LENGTH - 1] = '\0'; // Ensure null termination
        taskList[taskCount].executionTime = executionTime;
        taskCount++;
        printf("Task '%s' scheduled for execution at %s", name, ctime(&executionTime));
    } else {
        printf("Task limit reached, unable to add task '%s'.\n", name);
    }
}

void displayTasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task: %s, Execution Time: %s", taskList[i].name, ctime(&taskList[i].executionTime));
    }
}

void executeTasks() {
    time_t now;
    while (1) {
        now = time(NULL);
        for (int i = 0; i < taskCount; i++) {
            if (taskList[i].executionTime <= now) {
                printf("Executing Task: %s\n", taskList[i].name);
                // Remove the executed task by shifting others left in the array
                for (int j = i; j < taskCount - 1; j++) {
                    taskList[j] = taskList[j + 1];
                }
                taskCount--;
                i--; // Adjust index since we shifted the tasks
            }
        }
        if (taskCount == 0) {
            printf("No more tasks to execute.\n");
            break;
        }
        sleep(1); // Sleep for a while before checking tasks again
    }
}

int main() {
    char taskName[TASK_NAME_LENGTH];
    int hours, minutes, seconds;
    
    // Sample interaction to add tasks
    while (taskCount < MAX_TASKS) {
        printf("Enter task name (or type 'exit' to finish adding): ");
        fgets(taskName, TASK_NAME_LENGTH, stdin);
        taskName[strcspn(taskName, "\n")] = 0; // Remove newline

        if (strcmp(taskName, "exit") == 0) {
            break;
        }

        printf("Enter execution time in HH MM SS format: ");
        scanf("%d %d %d", &hours, &minutes, &seconds);
        getchar(); // Clear newline from buffer

        struct tm execTimeStruct = {0};
        time_t now = time(NULL);
        struct tm *currentTime = localtime(&now);

        execTimeStruct.tm_year = currentTime->tm_year;
        execTimeStruct.tm_mon = currentTime->tm_mon;
        execTimeStruct.tm_mday = currentTime->tm_mday;
        execTimeStruct.tm_hour = hours;
        execTimeStruct.tm_min = minutes;
        execTimeStruct.tm_sec = seconds;
        
        // Convert to time_t
        time_t executionTime = mktime(&execTimeStruct);
        
        // Check if the execution time is in the past
        if (executionTime < now) {
            printf("Execution time has already passed. Please enter a future time.\n");
        } else {
            addTask(taskName, executionTime);
        }
    }

    // Display all tasks
    displayTasks();

    // Start the execution loop
    executeTasks();

    return 0;
}