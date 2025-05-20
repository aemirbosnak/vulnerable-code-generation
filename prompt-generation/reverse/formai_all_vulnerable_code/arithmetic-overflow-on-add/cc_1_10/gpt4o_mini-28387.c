//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 100

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execution_time; // Time to execute
    int interval;          // Interval in seconds
    int active;           // 1 for active, 0 for inactive
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    strcpy(task_list[task_count].name, name);
    task_list[task_count].execution_time = time(NULL) + interval;
    task_list[task_count].interval = interval;
    task_list[task_count].active = 1;
    task_count++;
    printf("Task '%s' added, will execute in %d seconds.\n", name, interval);
}

void remove_task(const char *name) {
    for (int i = 0; i < task_count; i++) {
        if (strcmp(task_list[i].name, name) == 0 && task_list[i].active) {
            task_list[i].active = 0; // Deactivate the task
            printf("Task '%s' has been removed.\n", name);
            return;
        }
    }
    printf("Task '%s' not found or already inactive.\n", name);
}

void execute_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].active && now >= task_list[i].execution_time) {
            printf("Executing task: %s\n", task_list[i].name);
            task_list[i].execution_time += task_list[i].interval; // Reschedule
        }
    }
}

void view_tasks() {
    printf("\nCurrent Task Schedule:\n");
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].active) {
            printf("- %s (Next execution: %s, Interval: %d seconds)\n",
                   task_list[i].name,
                   ctime(&(task_list[i].execution_time)),
                   task_list[i].interval);
        }
    }
}

int main() {
    int choice, interval;
    char name[TASK_NAME_LENGTH];
    
    while (1) {
        printf("\n=== C Task Scheduler ===\n");
        printf("1. Add Task\n2. Remove Task\n3. Execute Tasks\n4. View Tasks\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, TASK_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                printf("Enter interval in seconds: ");
                scanf("%d", &interval);
                add_task(name, interval);
                break;
            case 2:
                printf("Enter task name to remove: ");
                fgets(name, TASK_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                remove_task(name);
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                view_tasks();
                break;
            case 5:
                printf("Exiting the Task Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Prevent busy waiting
    }
    return 0;
}