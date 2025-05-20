//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct task {
    char* description;
    int priority;
    int id;
} Task;

Task tasks[100];
int numTasks = 0;

void addTask(void) {
    Task newTask;

    printf("Enter task description: ");
    scanf("%s", newTask.description);

    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);

    newTask.id = numTasks + 1;

    tasks[numTasks++] = newTask;
}

void removeTask(void) {
    int taskId;

    printf("Enter task ID to remove: ");
    scanf("%d", &taskId);

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            for (int j = i; j < numTasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            numTasks--;
            break;
        }
    }
}

void displayTasks(void) {
    int i;

    printf("Task ID\tDescription\tPriority\n");
    for (i = 0; i < numTasks; i++) {
        printf("%3d\t%-30s\t%d\n", i + 1, tasks[i].description, tasks[i].priority);
    }
}

void menu(void) {
    int choice;

    printf("1. Add task\n2. Remove task\n3. Display tasks\n4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: addTask(); break;
        case 2: removeTask(); break;
        case 3: displayTasks(); break;
        case 4: exit(0);
    }
}

int main(void) {
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice!= 4);

    return 0;
}