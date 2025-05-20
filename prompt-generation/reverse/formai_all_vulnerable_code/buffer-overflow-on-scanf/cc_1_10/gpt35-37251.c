//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 50

int TaskScheduler();
void addTask();
void removeTask();
void displayTasks();
void clear();

struct Task {
    char name[50];
    int priority;
    int time;
    int id;
};

struct Task taskList[MAX_TASKS];
int numTasks = 0;

int main() {
    printf("Welcome to Task Scheduler!\n");
    TaskScheduler();
    return 0;
}

int TaskScheduler() {
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add a task\n");
        printf("2. Remove a task\n");
        printf("3. Display tasks\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        clear();
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
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

void addTask() {
    if (numTasks == MAX_TASKS) {
        printf("The task list is full!\n");
        return;
    }
    struct Task newTask;
    printf("Enter the task name: ");
    fgets(newTask.name, 50, stdin);
    printf("Enter the task priority (1-10): ");
    scanf("%d", &newTask.priority);
    printf("Enter the task time in minutes: ");
    scanf("%d", &newTask.time);
    newTask.id = numTasks + 1;
    taskList[numTasks++] = newTask;
    printf("Task added!\n");
}

void removeTask() {
    if (numTasks == 0) {
        printf("There are no tasks to remove!\n");
        return;
    }
    int taskID;
    printf("Enter the task ID to remove: ");
    scanf("%d", &taskID);
    int index = -1;
    for (int i = 0; i < numTasks; i++) {
        if (taskList[i].id == taskID) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Task not found!\n");
        return;
    }
    for (int i = index; i < numTasks - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    numTasks--;
    printf("Task removed!\n");
}

void displayTasks() {
    if (numTasks == 0) {
        printf("There are no tasks to display!\n");
        return;
    }
    struct Task task;
    printf("ID\tName\tPriority\tTime (min)\n");
    for (int i = 0; i < numTasks; i++) {
        task = taskList[i];
        printf("%d\t%s\t%d\t\t%d\n", task.id, task.name, task.priority, task.time);
    }
}

void clear() {
    while (getchar() != '\n');
}