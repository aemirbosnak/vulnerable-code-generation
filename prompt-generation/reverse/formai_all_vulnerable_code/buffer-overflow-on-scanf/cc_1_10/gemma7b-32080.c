//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void addTask(Task** head) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    printf("Enter task name:");
    scanf("%s", newTask->name);
    printf("Enter task priority (1-10):");
    scanf("%d", &newTask->priority);
    printf("Enter task start time (HH:MM):");
    scanf("%d:%d", &newTask->start_time, &newTask->end_time);

    newTask->next = NULL;
    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("Currently executing: %s\n", currentTask->name);
        } else if (now > currentTask->end_time) {
            printf("Task %s completed.\n", currentTask->name);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    int choice;

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add Task\n");
        printf("2. Schedule Tasks\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(&head);
                break;
            case 2:
                scheduleTasks(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}