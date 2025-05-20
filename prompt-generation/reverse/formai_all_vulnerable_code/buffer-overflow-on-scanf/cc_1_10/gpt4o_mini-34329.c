//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int priority;
    int completed;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

// Function to add a new task
void addTask(const char *name, int priority) {
    if (taskCount < MAX_TASKS) {
        strncpy(taskList[taskCount].name, name, TASK_NAME_LENGTH - 1);
        taskList[taskCount].name[TASK_NAME_LENGTH - 1] = '\0'; // Ensure null termination
        taskList[taskCount].priority = priority;
        taskList[taskCount].completed = 0; // Task is not completed
        taskCount++;
        printf("Task '%s' added with priority %d.\n", name, priority);
    } else {
        printf("Task list is full. Cannot add new task.\n");
    }
}

// Function to complete a task
void completeTask(int index) {
    if (index >= 0 && index < taskCount) {
        taskList[index].completed = 1;
        printf("Task '%s' marked as completed.\n", taskList[index].name);
    } else {
        printf("Invalid task index.\n");
    }
}

// Function to display all tasks
void displayTasks() {
    printf("\nTask List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf(" [%d] %s (Priority: %d) - %s\n", i + 1, taskList[i].name, taskList[i].priority, 
            taskList[i].completed ? "Completed" : "Pending");
    }
}

// Function to sort tasks by priority
void sortTasksByPriority() {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = i + 1; j < taskCount; j++) {
            if (taskList[i].priority > taskList[j].priority) {
                Task temp = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = temp;
            }
        }
    }
    printf("Tasks sorted by priority.\n");
}

// Function to save tasks to a file
void saveTasksToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < taskCount; i++) {
            fprintf(file, "%s;%d;%d\n", taskList[i].name, taskList[i].priority, taskList[i].completed);
        }
        fclose(file);
        printf("Tasks saved to '%s'.\n", filename);
    } else {
        printf("Error saving tasks to file.\n");
    }
}

// Function to load tasks from a file
void loadTasksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        while (fscanf(file, "%49[^;];%d;%d\n", taskList[taskCount].name, &taskList[taskCount].priority, 
            &taskList[taskCount].completed) == 3) {
            taskCount++;
            if (taskCount >= MAX_TASKS) break; // Prevent overflow
        }
        fclose(file);
        printf("Tasks loaded from '%s'.\n", filename);
    } else {
        printf("Error loading tasks from file.\n");
    }
}

// Main function to drive the task management system
int main() {
    int choice;
    char taskName[TASK_NAME_LENGTH];
    int priority;

    while (1) {
        printf("\n--- Task Management System ---\n");
        printf("1. Add Task\n");
        printf("2. Complete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Sort Tasks by Priority\n");
        printf("5. Save Tasks to File\n");
        printf("6. Load Tasks from File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(taskName, TASK_NAME_LENGTH, stdin);
                taskName[strcspn(taskName, "\n")] = '\0'; // Remove newline
                printf("Enter task priority (1-10): ");
                scanf("%d", &priority);
                addTask(taskName, priority);
                break;
            case 2:
                printf("Enter task index to complete: ");
                int index;
                scanf("%d", &index);
                completeTask(index - 1); // Adjusting for 0-based indexing
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                sortTasksByPriority();
                break;
            case 5:
                saveTasksToFile("tasks.txt");
                break;
            case 6:
                loadTasksFromFile("tasks.txt");
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}