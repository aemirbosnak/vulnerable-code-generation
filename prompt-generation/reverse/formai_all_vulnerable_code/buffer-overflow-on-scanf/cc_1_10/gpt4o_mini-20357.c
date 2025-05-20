//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256
#define FILENAME "todo.txt"

// Function to display the menu
void display_menu() {
    printf("To-Do List Manager\n");
    printf("-------------------\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Save Tasks to File\n");
    printf("4. Load Tasks from File\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

// Function to add task
void add_task(char tasks[MAX_TASKS][TASK_LENGTH], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Task limit reached! Cannot add more tasks.\n");
        return;
    }
    printf("Enter the task: ");
    getchar(); // Consume newline character left in buffer
    fgets(tasks[*task_count], TASK_LENGTH, stdin);
    tasks[*task_count][strcspn(tasks[*task_count], "\n")] = 0; // Remove newline
    (*task_count)++;
    printf("Task added successfully!\n");
}

// Function to view tasks
void view_tasks(char tasks[MAX_TASKS][TASK_LENGTH], int task_count) {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("Your Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

// Function to save tasks to a file
void save_tasks(const char tasks[MAX_TASKS][TASK_LENGTH], int task_count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%s\n", tasks[i]);
    }
    fclose(file);
    printf("Tasks saved to %s successfully!\n", FILENAME);
}

// Function to load tasks from a file
void load_tasks(char tasks[MAX_TASKS][TASK_LENGTH], int *task_count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    while (fgets(tasks[*task_count], TASK_LENGTH, file) != NULL && *task_count < MAX_TASKS) {
        tasks[*task_count][strcspn(tasks[*task_count], "\n")] = 0; // Remove newline
        (*task_count)++;
    }
    fclose(file);
    printf("Tasks loaded successfully!\n");
}

int main() {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int task_count = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                view_tasks(tasks, task_count);
                break;
            case 3:
                save_tasks(tasks, task_count);
                break;
            case 4:
                load_tasks(tasks, &task_count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}