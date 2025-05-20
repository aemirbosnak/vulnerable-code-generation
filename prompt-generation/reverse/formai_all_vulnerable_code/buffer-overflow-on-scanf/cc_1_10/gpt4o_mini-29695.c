//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char description[100];
    struct Task *next;
} Task;

Task *head = NULL;
int taskIdCounter = 1;

void addTask(const char *description) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->id = taskIdCounter++;
    strncpy(newTask->description, description, sizeof(newTask->description) - 1);
    newTask->description[sizeof(newTask->description) - 1] = '\0';
    newTask->next = head;
    head = newTask;
}

void viewTasks() {
    Task *current = head;
    if (current == NULL) {
        printf("No tasks available.\n");
        return;
    }
    printf("Tasks List:\n");
    while (current != NULL) {
        printf("Task ID: %d, Description: %s\n", current->id, current->description);
        current = current->next;
    }
}

void deleteTask(int id) {
    Task *current = head;
    Task *previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Task ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the first task
    } else {
        previous->next = current->next; // Bypass the current task
    }

    free(current);
    printf("Task ID %d has been deleted.\n", id);
}

void freeTasks() {
    Task *current = head;
    Task *nextTask;
    while (current != NULL) {
        nextTask = current->next;
        free(current);
        current = nextTask;
    }
    head = NULL;
}

int main() {
    int choice;
    char description[100];
    int id;

    while (1) {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                getchar(); // To consume newline left in buffer
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                addTask(description);
                printf("Task added!\n");
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter Task ID to delete: ");
                scanf("%d", &id);
                deleteTask(id);
                break;
            case 4:
                freeTasks();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}