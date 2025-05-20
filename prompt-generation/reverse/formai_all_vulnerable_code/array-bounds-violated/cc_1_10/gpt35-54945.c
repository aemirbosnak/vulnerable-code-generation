//FormAI DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Data structure for tasks
typedef struct {
    int id;
    char* name;
    int priority;
    int interval;
    int lastExecuted;
} Task;

// Array to store all tasks
Task tasks[10];

// Function to add tasks
void addTask(int id, char* name, int priority, int interval) {
    tasks[id].id = id;
    tasks[id].name = name;
    tasks[id].priority = priority;
    tasks[id].interval = interval;
    tasks[id].lastExecuted = 0;
}

// Function to remove tasks
void removeTask(int id) {
    tasks[id].id = -1;
    tasks[id].name = NULL;
    tasks[id].priority = 0;
    tasks[id].interval = 0;
    tasks[id].lastExecuted = 0;
}

// Function to execute a task
void executeTask(int id) {
    printf("Executing task %d - %s\n", tasks[id].id, tasks[id].name);
    tasks[id].lastExecuted = time(NULL);
}

// Function to find the next task to execute
int getNextTask() {
    int i;
    int highestPriority = -1;
    int nextTask = -1;

    for (i = 0; i < 10; i++) {
        if (tasks[i].id != -1 && tasks[i].lastExecuted + tasks[i].interval <= time(NULL)) {
            if (tasks[i].priority > highestPriority) {
                highestPriority = tasks[i].priority;
                nextTask = i;
            }
        }
    }

    return nextTask;
}

// Main function
int main() {
    int choice;
    int id, priority, interval;
    char* name = malloc(sizeof(char) * 20);

    // Initialize the task array
    int i;
    for (i = 0; i < 10; i++) {
        tasks[i].id = -1;
        tasks[i].name = NULL;
        tasks[i].priority = 0;
        tasks[i].interval = 0;
        tasks[i].lastExecuted = 0;
    }

    // Main loop
    while (true) {
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Execute next task\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter task id: ");
                scanf("%d", &id);

                printf("Enter task name: ");
                scanf("%s", name);

                printf("Enter task priority: ");
                scanf("%d", &priority);

                printf("Enter task interval: ");
                scanf("%d", &interval);

                addTask(id, name, priority, interval);

                break;
            case 2:
                printf("Enter task id to remove: ");
                scanf("%d", &id);

                removeTask(id);

                break;
            case 3:
                id = getNextTask();

                if (id == -1) {
                    printf("No tasks to execute\n");
                } else {
                    executeTask(id);
                }

                break;
            case 4:
                free(name);
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}