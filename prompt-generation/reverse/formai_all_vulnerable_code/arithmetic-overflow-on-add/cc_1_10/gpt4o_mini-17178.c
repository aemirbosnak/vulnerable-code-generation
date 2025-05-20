//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t scheduled_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int seconds_from_now) {
    if (task_count < MAX_TASKS) {
        strcpy(task_list[task_count].name, name);
        task_list[task_count].scheduled_time = time(NULL) + seconds_from_now;
        task_count++;
        printf("Task '%s' scheduled for %d seconds from now.\n", name, seconds_from_now);
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
}

void list_tasks() {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf(" [%d] %s at %s", i + 1, task_list[i].name, ctime(&task_list[i].scheduled_time));
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].scheduled_time <= current_time) {
            printf("Executing Task: %s\n", task_list[i].name);
            // Shift tasks down to overwrite completed task
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Check the same index again after shift
        }
    }
}

int main() {
    int choice, time;
    char name[TASK_NAME_LENGTH];

    while (1) {
        printf("\n--- Task Scheduler ---\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear enter from buffer

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, TASK_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter time in seconds from now: ");
                scanf("%d", &time);
                add_task(name, time);
                break;

            case 2:
                list_tasks();
                break;

            case 3:
                execute_tasks();
                break;

            case 4:
                printf("Exiting the Task Scheduler. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        sleep(1); // Check for task execution every second
    }

    return 0;
}