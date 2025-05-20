//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    int priority;
    char name[20];
    time_t time;
} Task;

Task taskQueue[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task queue is full!\n");
        return;
    }

    Task newTask;
    newTask.id = taskCount + 1;
    printf("Enter the name of the task: ");
    scanf("%s", newTask.name);
    printf("Enter the priority of the task (1-10): ");
    scanf("%d", &newTask.priority);
    newTask.time = time(NULL);
    
    taskQueue[taskCount++] = newTask;
    printf("Task added successfully!\n");
}

void removeTask() {
    if (taskCount == 0) {
        printf("Task queue is empty!\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < taskCount; i++) {
        if (taskQueue[i].priority > taskQueue[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    printf("Removed task %d (%s)\n", taskQueue[highestPriorityIndex].id, taskQueue[highestPriorityIndex].name);

    // Shift tasks to fill removed task
    for (int i = highestPriorityIndex; i < taskCount - 1; i++) {
        taskQueue[i] = taskQueue[i + 1];
    }

    taskCount--;
}

void displayTasks() {
    if (taskCount == 0) {
        printf("Task queue is empty!\n");
        return;
    }

    printf("Task Queue:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s (priority %d, added %s)", taskQueue[i].id, taskQueue[i].name, taskQueue[i].priority, ctime(&taskQueue[i].time));
    }
}

int main() {
    int choice;

    do {
        printf("Menu:\n1. Add Task\n2. Remove Highest Priority Task\n3. Display Tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        sleep(2); // Wait for 2 seconds before clearing the terminal
        system("clear"); // Clear the terminal
    } while (choice != 4);

    return 0;
}