//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 10
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    time_t execution_time;
    bool executed;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *description, time_t time_offset);
void execute_tasks();
void display_tasks();
void clear_tasks();

int main() {
    int choice;
    char description[MAX_DESC_LENGTH];
    int seconds;

    while (1) {
        printf("\n=== C Task Scheduler ===\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Display Tasks\n");
        printf("4. Clear Tasks\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                if (task_count >= MAX_TASKS) {
                    printf("Task list is full!\n");
                    break;
                }
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline

                printf("Enter time offset in seconds: ");
                scanf("%d", &seconds);

                add_task(description, seconds);
                break;

            case 2:
                execute_tasks();
                break;

            case 3:
                display_tasks();
                break;

            case 4:
                clear_tasks();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void add_task(const char *description, time_t time_offset) {
    task_list[task_count].execution_time = time(NULL) + time_offset;
    strncpy(task_list[task_count].description, description, MAX_DESC_LENGTH);
    task_list[task_count].executed = false;
    task_count++;
    printf("Task added: '%s', scheduled in %ld seconds.\n", description, time_offset);
}

void execute_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (!task_list[i].executed && now >= task_list[i].execution_time) {
            printf("Executing task: %s\n", task_list[i].description);
            task_list[i].executed = true;
        }
    }
}

void display_tasks() {
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: '%s', Scheduled for: %s", 
                i + 1, task_list[i].description, 
                ctime(&task_list[i].execution_time));
    }
}

void clear_tasks() {
    task_count = 0;
    printf("All tasks cleared!\n");
}