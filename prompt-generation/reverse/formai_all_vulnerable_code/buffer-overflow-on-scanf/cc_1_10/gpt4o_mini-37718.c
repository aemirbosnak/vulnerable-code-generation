//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int priority;
    int is_completed;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskManager;

void initialize(TaskManager *manager) {
    manager->count = 0;
}

void add_task(TaskManager *manager, const char *name, int priority) {
    if (manager->count < MAX_TASKS) {
        strncpy(manager->tasks[manager->count].name, name, TASK_NAME_LENGTH - 1);
        manager->tasks[manager->count].name[TASK_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        manager->tasks[manager->count].priority = priority;
        manager->tasks[manager->count].is_completed = 0; // Task starts as incomplete
        manager->count++;
        printf("Added task: '%s' with priority %d\n", name, priority);
    } else {
        printf("Failed to add task: task limit reached!\n");
    }
}

void mark_task_completed(TaskManager *manager, int index) {
    if (index >= 0 && index < manager->count) {
        manager->tasks[index].is_completed = 1;
        printf("Marked task '%s' as completed.\n", manager->tasks[index].name);
    } else {
        printf("Invalid task index!\n");
    }
}

void list_tasks(const TaskManager *manager) {
    printf("=== Task List ===\n");
    for (int i = 0; i < manager->count; i++) {
        printf("[%d] %s (Priority: %d) %s\n", 
            i,
            manager->tasks[i].name,
            manager->tasks[i].priority,
            manager->tasks[i].is_completed ? "(Completed)" : "(Not Completed)");
    }
    printf("=================\n");
}

void sort_tasks(TaskManager *manager) {
    // Simple bubble sort based on priority (lower number means higher priority)
    for (int i = 0; i < manager->count - 1; i++) {
        for (int j = 0; j < manager->count - i - 1; j++) {
            if (manager->tasks[j].priority > manager->tasks[j + 1].priority) {
                // Swap tasks
                Task temp = manager->tasks[j];
                manager->tasks[j] = manager->tasks[j + 1];
                manager->tasks[j + 1] = temp;
            }
        }
    }
    printf("Tasks sorted by priority.\n");
}

void delete_task(TaskManager *manager, int index) {
    if (index < 0 || index >= manager->count) {
        printf("Invalid task index!\n");
        return;
    }
    for (int i = index; i < manager->count - 1; i++) {
        manager->tasks[i] = manager->tasks[i + 1];
    }
    manager->count--;
    printf("Deleted task at index %d.\n", index);
}

int main() {
    TaskManager manager;
    initialize(&manager);
    int choice;
    char task_name[TASK_NAME_LENGTH];
    int priority;

    do {
        printf("\n=== Task Manager ===\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. List Tasks\n");
        printf("4. Sort Tasks by Priority\n");
        printf("5. Delete Task\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]", task_name); // Read a line including spaces
                printf("Enter task priority (1-5): ");
                scanf("%d", &priority);
                add_task(&manager, task_name, priority);
                break;
            case 2:
                list_tasks(&manager);
                printf("Enter task index to mark as completed: ");
                scanf("%d", &priority);
                mark_task_completed(&manager, priority);
                break;
            case 3:
                list_tasks(&manager);
                break;
            case 4:
                sort_tasks(&manager);
                break;
            case 5:
                list_tasks(&manager);
                printf("Enter task index to delete: ");
                scanf("%d", &priority);
                delete_task(&manager, priority);
                break;
            case 0:
                printf("Exiting Task Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}