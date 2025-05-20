//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256

void display_menu() {
    printf("\n--- Peaceful To-Do List ---\n");
    printf("1. Add a Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete a Task\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
    printf("Select an option (1-4): ");
}

void add_task() {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    
    char task[TASK_LENGTH];
    printf("Enter the task: ");
    getchar(); // To consume newline character from previous input
    fgets(task, TASK_LENGTH, stdin);
    
    // Remove newline character from the end of the task
    task[strcspn(task, "\n")] = '\0';

    fprintf(file, "%s\n", task);
    fclose(file);
    
    printf("Task added peacefully.\n");
}

void view_tasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    
    char task[TASK_LENGTH];
    int task_number = 1;
    printf("\n--- Your To-Do List ---\n");
    
    while (fgets(task, TASK_LENGTH, file) != NULL) {
        printf("%d. %s", task_number++, task);
    }
    
    if (task_number == 1) {
        printf("Your list is empty. Add some tasks!\n");
    }
    
    fclose(file);
}

void delete_task() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    char tasks[MAX_TASKS][TASK_LENGTH];
    int count = 0;

    // Read all tasks into an array
    while (fgets(tasks[count], TASK_LENGTH, file) != NULL && count < MAX_TASKS) {
        count++;
    }
    
    fclose(file);

    // Display current tasks
    view_tasks();
    
    int task_to_delete;
    printf("Enter the task number to delete: ");
    scanf("%d", &task_to_delete);

    // Validate task number
    if (task_to_delete < 1 || task_to_delete > count) {
        printf("Invalid task number. No task deleted.\n");
        return;
    }

    // Re-open file for writing and overwrite with remaining tasks
    file = fopen("tasks.txt", "w");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (i != task_to_delete - 1) {
            fprintf(file, "%s", tasks[i]);
        }
    }
    
    fclose(file);
    printf("Task %d has been deleted peacefully.\n", task_to_delete);
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                printf("Thank you for using the Peaceful To-Do List. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}