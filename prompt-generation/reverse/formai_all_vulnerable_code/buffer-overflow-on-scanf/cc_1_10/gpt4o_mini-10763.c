//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 256
#define MAX_TASKS 100
#define FILENAME "todo_list.txt"

void add_task(const char *task);
void view_tasks();
void delete_task(int index);
void print_menu();
int get_choice();

int main() {
    int choice;
    
    // Creating or opening the file
    FILE *file = fopen(FILENAME, "a+");
    if (file == NULL) {
        printf("Could not open file %s for reading and writing.\n", FILENAME);
        return 1; // Exit if the file cannot be opened
    }
    fclose(file); // Close the file after check

    do {
        print_menu(); // Display the menu
        choice = get_choice(); // Get the user's choice

        switch (choice) {
            case 1: {
                char task[MAX_TASK_LENGTH];
                printf("Enter a task: ");
                getchar(); // Consume the newline character remaining in the buffer
                fgets(task, MAX_TASK_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove the newline character
                add_task(task);
                break;
            }
            case 2:
                view_tasks();
                break;
            case 3: {
                int task_number;
                printf("Enter the task number to delete: ");
                scanf("%d", &task_number);
                delete_task(task_number);
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a task
void add_task(const char *task) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Could not open file %s for appending.\n", FILENAME);
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added: %s\n", task);
}

// Function to view tasks
void view_tasks() {
    char line[MAX_TASK_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", FILENAME);
        return;
    }

    printf("To-Do List:\n");
    int index = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", index++, line);
    }
    fclose(file);
}

// Function to delete a task
void delete_task(int index) {
    char line[MAX_TASK_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", FILENAME);
        return;
    }

    // Create a temporary file
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Could not open temporary file for writing.\n");
        fclose(file);
        return;
    }

    int current_line = 1;
    while (fgets(line, sizeof(line), file)) {
        if (current_line != index) {
            fprintf(temp_file, "%s", line); // Write to temp file if not the task to delete
        }
        current_line++;
    }

    fclose(file);
    fclose(temp_file);

    // Replace the old file with the new one
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    printf("Task %d deleted successfully.\n", index);
}

// Function to print the menu
void print_menu() {
    printf("\n--- To-Do List Menu ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
}

// Function to get user choice
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}