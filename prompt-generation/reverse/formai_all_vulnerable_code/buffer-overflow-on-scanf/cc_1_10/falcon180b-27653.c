//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void add_task(Task tasks[], int size, char name[], int priority, int burst_time) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("Task %s already exists!\n", name);
            return;
        }
    }
    tasks[size].name[0] = '\0';
    strcpy(tasks[size].name, name);
    tasks[size].priority = priority;
    tasks[size].burst_time = burst_time;
    size++;
}

void display_tasks(Task tasks[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Task %d: %s\n", i+1, tasks[i].name);
    }
}

int main() {
    int i, j, n, choice, max_index;
    char name[20];
    Task tasks[MAX_TASKS];
    int size = 0;
    int quantum = 2;

    printf("Welcome to the Cheerful Task Scheduler!\n");

    while (1) {
        printf("\n");
        printf("1. Add a task\n");
        printf("2. Display tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task priority: ");
                scanf("%d", &n);
                printf("Enter task burst time: ");
                scanf("%d", &n);
                add_task(tasks, size, name, n, n);
                size++;
                break;
            case 2:
                display_tasks(tasks, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}