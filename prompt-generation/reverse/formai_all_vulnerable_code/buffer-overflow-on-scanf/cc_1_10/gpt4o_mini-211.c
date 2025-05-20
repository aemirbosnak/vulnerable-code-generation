//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
} Task;

typedef struct TaskManager {
    Task *tasks;
    int size;
    int capacity;
} TaskManager;

// Function prototypes
TaskManager *createTaskManager(int capacity);
void addTask(TaskManager *manager, const char *title);
void removeTask(TaskManager *manager, int taskId);
void listTasks(const TaskManager *manager);
void freeTaskManager(TaskManager *manager);

int main() {
    // Create a Task Manager with an initial capacity of 2
    TaskManager *manager = createTaskManager(2);
    int choice;
    char title[100];
    int taskId;

    while (1) {
        printf("\nTask Manager:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. List Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                printf("Enter task title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                addTask(manager, title);
                break;
            case 2:
                printf("Enter task ID to remove: ");
                scanf("%d", &taskId);
                removeTask(manager, taskId);
                break;
            case 3:
                listTasks(manager);
                break;
            case 4:
                freeTaskManager(manager);
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

// Function to create a TaskManager
TaskManager *createTaskManager(int capacity) {
    TaskManager *manager = (TaskManager *)malloc(sizeof(TaskManager));
    manager->tasks = (Task *)malloc(capacity * sizeof(Task));
    manager->size = 0;
    manager->capacity = capacity;
    return manager;
}

// Function to add a task to the manager
void addTask(TaskManager *manager, const char *title) {
    if (manager->size >= manager->capacity) {
        manager->capacity *= 2; // Double the capacity
        manager->tasks = (Task *)realloc(manager->tasks, manager->capacity * sizeof(Task));
        if (!manager->tasks) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    manager->tasks[manager->size].id = manager->size + 1; // Simple ID assignment
    strcpy(manager->tasks[manager->size].title, title);
    manager->size++;
    printf("Task added: ID %d, Title: '%s'\n", manager->tasks[manager->size - 1].id, title);
}

// Function to remove a task from the manager
void removeTask(TaskManager *manager, int taskId) {
    if (taskId <= 0 || taskId > manager->size) {
        printf("Invalid task ID.\n");
        return;
    }
    int index = taskId - 1; // Convert ID to index
    for (int i = index; i < manager->size - 1; i++) {
        manager->tasks[i] = manager->tasks[i + 1]; // Shift tasks left
    }
    manager->size--;
    printf("Task ID %d removed.\n", taskId);
}

// Function to list all tasks
void listTasks(const TaskManager *manager) {
    if (manager->size == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; i < manager->size; i++) {
        printf("ID: %d, Title: '%s'\n", manager->tasks[i].id, manager->tasks[i].title);
    }
}

// Function to free the TaskManager and its tasks
void freeTaskManager(TaskManager *manager) {
    free(manager->tasks);
    free(manager);
    printf("Task Manager freed successfully.\n");
}