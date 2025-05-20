//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct Task {
    char name[TASK_NAME_LENGTH];
    int priority;
} Task;

void printMenu() {
    printf("\nTask Manager Menu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Remove Task\n");
    printf("4. Sort Tasks by Priority\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount == MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    
    Task newTask;
    printf("Enter task name: ");
    scanf(" %49[^\n]", newTask.name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &newTask.priority);

    if (newTask.priority < 1 || newTask.priority > 10) {
        printf("Invalid priority! Please enter a value between 1 and 10.\n");
        return;
    }

    tasks[*taskCount] = newTask;
    (*taskCount)++;
    printf("Task added successfully!\n");
}

void viewTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s (Priority: %d)\n", i + 1, tasks[i].name, tasks[i].priority);
    }
}

void removeTask(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to remove.\n");
        return;
    }

    int index;
    printf("Enter the task number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = index - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--;
    printf("Task removed successfully!\n");
}

void sortTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("Tasks sorted by priority!\n");
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                removeTask(tasks, &taskCount);
                break;
            case 4:
                sortTasks(tasks, taskCount);
                break;
            case 5:
                printf("Exiting Task Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}