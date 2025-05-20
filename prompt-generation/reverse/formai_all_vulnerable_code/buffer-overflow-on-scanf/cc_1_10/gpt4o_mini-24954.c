//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execute_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int delay_seconds) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    strcpy(task_list[task_count].name, name);
    task_list[task_count].execute_time = time(NULL) + delay_seconds;
    task_count++;
    printf("Added task: '%s', scheduled in %d seconds.\n", name, delay_seconds);
}

void display_tasks() {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s - Executes at %s", i + 1, task_list[i].name, ctime(&task_list[i].execute_time));
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (current_time >= task_list[i].execute_time) {
            printf("Executing task: %s\n", task_list[i].name);
            // Remove the task by shifting the rest
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Adjust index after removal
        }
    }
}

int main() {
    printf("Welcome to the Fun Task Scheduler!\n");

    int choice, delay;
    char task_name[TASK_NAME_LENGTH];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", task_name);
                printf("Enter delay in seconds: ");
                scanf("%d", &delay);
                add_task(task_name, delay);
                break;

            case 2:
                display_tasks();
                break;

            case 3:
                execute_tasks();
                break;

            case 4:
                printf("Exiting the Task Scheduler. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Simulate the passing of time for task execution
        printf("Waiting a moment...\n");
        sleep(1);
    }

    return 0;
}