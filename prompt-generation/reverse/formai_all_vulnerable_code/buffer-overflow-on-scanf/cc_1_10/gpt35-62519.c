//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int taskId;
    char taskName[20];
    int priorityLevel;
    time_t startTime;
    time_t finishTime;
} Task;

int numTasks = 0;
Task taskList[MAX_TASKS];

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }

    Task newTask;

    printf("Enter task name: ");
    scanf("%s", newTask.taskName);

    printf("Enter task priority level (1-10): ");
    scanf("%d", &newTask.priorityLevel);

    newTask.taskId = ++numTasks;
    newTask.startTime = time(NULL);
    newTask.finishTime = 0;

    taskList[numTasks - 1] = newTask;

    printf("Task added successfully.\n");
}

void completeTask() {
    int taskId;

    printf("Enter task ID to complete: ");
    scanf("%d", &taskId);

    if (taskId <= 0 || taskId > numTasks) {
        printf("Invalid task ID.\n");
        return;
    }

    Task task = taskList[taskId - 1];

    task.finishTime = time(NULL);

    printf("Task %d (%s) completed successfully.\n", taskId, task.taskName);
}

void printTaskList() {
    printf("Task List:\n");

    for (int i = 0; i < numTasks; i++) {
        Task task = taskList[i];

        printf("%d. %s (Priority: %d, Start Time: %ld", task.taskId, task.taskName, task.priorityLevel, task.startTime);

        if (task.finishTime > 0) {
            printf(", Finish Time: %ld", task.finishTime);
        }

        printf(")\n");
    }
}

void simulateTime() {
    time_t currentTime = time(NULL);

    for (int i = 0; i < numTasks; i++) {
        Task task = taskList[i];

        if (task.finishTime > 0) {
            continue;
        }

        int timeElapsed = (int) (currentTime - task.startTime);

        if (timeElapsed >= task.priorityLevel * 5) {
            task.finishTime = currentTime;
            printf("Task %d (%s) timed out.\n", task.taskId, task.taskName);
        }
    }
}

int main() {
    int choice;
    
    do {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Complete Task\n");
        printf("3. Print Task List\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                completeTask();
                break;
            case 3:
                printTaskList();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        simulateTime();
    } while (choice != 4);

    return 0;
}