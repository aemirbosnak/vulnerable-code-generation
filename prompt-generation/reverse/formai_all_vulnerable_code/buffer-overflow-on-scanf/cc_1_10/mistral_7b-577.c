//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 10

typedef struct task {
    int id;
    int priority;
    struct task *next;
} Task;

Task *head = NULL;
Task *pqueue = NULL;

void enqueue(int id, int priority) {
    Task *new_task = (Task*)malloc(sizeof(Task));
    new_task->id = id;
    new_task->priority = priority;
    new_task->next = NULL;

    if (pqueue == NULL) {
        pqueue = new_task;
        head = new_task;
    } else {
        Task *current = pqueue;
        while (current->next != NULL && current->next->priority < new_task->priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;

        if (current == pqueue && new_task->priority < current->priority) {
            Task *temp = pqueue;
            pqueue = new_task;
            free(temp);
        }
    }
}

void dequeue() {
    if (pqueue == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Task *current = pqueue;
    pqueue = pqueue->next;

    free(current);
}

void print_queue() {
    Task *current = pqueue;
    while (current != NULL) {
        printf("Task %d with priority %d\n", current->id, current->priority);
        current = current->next;
    }
}

int main() {
    int choice, id, priority;

    while (1) {
        printf("\nTask Scheduler\n");
        printf("1. Enqueue a task\n");
        printf("2. Dequeue a task\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task ID: ");
                scanf("%d", &id);
                printf("Enter task priority: ");
                scanf("%d", &priority);
                enqueue(id, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print_queue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}