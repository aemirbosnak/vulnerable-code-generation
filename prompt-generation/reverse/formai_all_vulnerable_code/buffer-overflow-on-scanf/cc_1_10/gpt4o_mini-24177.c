//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 256
#define FILENAME "todo_list.txt"

void add_task(const char *task);
void view_tasks();
void delete_task(int task_number);
void display_menu();
void clear_buffer();

int main() {
    int choice;
    char task[MAX_TASK_LENGTH];

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear the buffer to avoid reading leftover new line

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                fgets(task, sizeof(task), stdin);
                task[strcspn(task, "\n")] = 0; // Remove the newline character
                add_task(task);
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                printf("Enter the task number to delete: ");
                scanf("%d", &choice);
                delete_task(choice);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void add_task(const char *task) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added: %s\n", task);
}

void view_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_TASK_LENGTH];
    int task_number = 1;
    printf("\nTo-Do List:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", task_number++, line);
    }
    fclose(file);

    if (task_number == 1) {
        printf("No tasks found.\n");
    }
}

void delete_task(int task_number) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    char line[MAX_TASK_LENGTH];
    int current_task = 1;

    while (fgets(line, sizeof(line), file)) {
        if (current_task != task_number) {
            fputs(line, temp_file);
        }
        current_task++;
    }

    fclose(file);
    fclose(temp_file);
    
    if (remove(FILENAME) == 0 && rename("temp.txt", FILENAME) == 0) {
        printf("Task %d deleted successfully.\n", task_number);
    } else {
        perror("Error deleting task");
    }
}

void display_menu() {
    printf("\n--- To-Do List Menu ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
}

void clear_buffer() {
    while (getchar() != '\n') ; // Clear input buffer
}