//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_SIZE 255
#define FILE_NAME "todo_list.txt"

void add_task(const char *task);
void view_tasks();
void delete_task(int task_number);
void clear_buffer();

int main() {
    int choice;
    char task[MAX_TASK_SIZE];

    while (1) {
        printf("\n--- To-Do List Manager ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                fgets(task, MAX_TASK_SIZE, stdin);
                task[strcspn(task, "\n")] = '\0'; // Remove the newline character
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
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void add_task(const char *task) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Failed to open file for adding task");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added: %s\n", task);
}

void view_tasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Failed to open file for reading tasks");
        return;
    }

    char task[MAX_TASK_SIZE];
    int task_number = 1;
    printf("\n--- Your Tasks ---\n");
    while (fgets(task, sizeof(task), file)) {
        printf("%d: %s", task_number++, task);
    }
    fclose(file);

    if (task_number == 1) {
        printf("No tasks found!\n");
    }
}

void delete_task(int task_number) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Failed to open file for reading tasks");
        return;
    }

    char tasks[100][MAX_TASK_SIZE];
    int count = 0;
    while (fgets(tasks[count], sizeof(tasks[count]), file)) {
        count++;
    }
    fclose(file);

    if (task_number > count || task_number < 1) {
        printf("Invalid task number!\n");
        return;
    }

    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Failed to open file for deleting task");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != task_number - 1) {
            fprintf(file, "%s", tasks[i]);
        }
    }
    fclose(file);
    printf("Task %d deleted successfully!\n", task_number);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}