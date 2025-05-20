//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    int completed;
} Task;

typedef struct {
    Task *tasks;
    int size;
    int capacity;
} TaskManager;

void initTaskManager(TaskManager *tm) {
    tm->size = 0;
    tm->capacity = 2;
    tm->tasks = (Task *)malloc(sizeof(Task) * tm->capacity);
    if (tm->tasks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void freeTaskManager(TaskManager *tm) {
    for (int i = 0; i < tm->size; i++) {
        free(tm->tasks[i].description);
    }
    free(tm->tasks);
}

void resizeTaskManager(TaskManager *tm) {
    tm->capacity *= 2;
    tm->tasks = (Task *)realloc(tm->tasks, sizeof(Task) * tm->capacity);
    if (tm->tasks == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void addTask(TaskManager *tm, const char *description) {
    if (tm->size == tm->capacity) {
        resizeTaskManager(tm);
    }
    tm->tasks[tm->size].description = strdup(description);
    tm->tasks[tm->size].completed = 0;
    tm->size++;
}

void viewTasks(const TaskManager *tm) {
    if (tm->size == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < tm->size; i++) {
        printf("[%d] %s [%s]\n", i + 1, tm->tasks[i].description, 
               tm->tasks[i].completed ? "Completed" : "Pending");
    }
}

void markTaskCompleted(TaskManager *tm, int index) {
    if (index >= 0 && index < tm->size) {
        tm->tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void deleteTask(TaskManager *tm, int index) {
    if (index < 0 || index >= tm->size) {
        printf("Invalid task index.\n");
        return;
    }
    free(tm->tasks[index].description);

    for (int i = index; i < tm->size - 1; i++) {
        tm->tasks[i] = tm->tasks[i + 1];
    }
    tm->size--;
    printf("Task deleted successfully.\n");
}

int main() {
    TaskManager tm;
    initTaskManager(&tm);
    
    int choice;
    char description[256];
    
    do {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline
        
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                addTask(&tm, description);
                printf("Task added successfully.\n");
                break;
            case 2:
                viewTasks(&tm);
                break;
            case 3:
                printf("Enter task number to mark as completed: ");
                int completeIndex;
                scanf("%d", &completeIndex);
                markTaskCompleted(&tm, completeIndex - 1);
                break;
            case 4:
                printf("Enter task number to delete: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                deleteTask(&tm, deleteIndex - 1);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    freeTaskManager(&tm);
    return 0;
}