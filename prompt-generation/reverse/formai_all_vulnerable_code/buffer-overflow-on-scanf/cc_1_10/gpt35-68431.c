//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of tasks
#define MAX_TASKS 10

// Task structure
struct Task {
    int priority;
    int time_needed;
    char name[20];
};

// Task list
struct Task task_list[MAX_TASKS];
int num_tasks = 0;

// Add task function
void add_task(int priority, int time, char *name) {
    if (num_tasks >= MAX_TASKS) {
        printf("Task list is full\n");
        return;
    }

    // Create new task
    struct Task new_task;
    new_task.priority = priority;
    new_task.time_needed = time;
    strcpy(new_task.name, name);

    // Insert new task into task list
    int i;
    for (i = num_tasks - 1; i >= 0; i--) {
        if (new_task.priority > task_list[i].priority) {
            task_list[i + 1] = task_list[i];
        } else {
            break;
        }
    }
    task_list[i + 1] = new_task;
    num_tasks++;

    printf("Task added successfully\n");
}

// Print task list function
void print_task_list() {
    if (num_tasks == 0) {
        printf("Task list is empty\n");
        return;
    }

    printf("Task List:\n");
    printf("%-10s | %-10s | %-15s\n", "Priority", "Time", "Name");
    printf("---------------------------------------\n");
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%-10d | %-10d | %-15s\n", task_list[i].priority,
               task_list[i].time_needed, task_list[i].name);
    }
}

// Execute task function
void execute_task() {
    if (num_tasks == 0) {
        printf("Task list is empty\n");
        return;
    }

    // Determine current time
    time_t current_time;
    time(&current_time);
    struct tm *tm_info = localtime(&current_time);
    int current_hour = tm_info->tm_hour;
    int current_minute = tm_info->tm_min;

    // Determine next task to execute
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (current_hour == 9 && current_minute < 30) {
            if (task_list[i].priority >= 3) {
                printf("Executing task %s\n", task_list[i].name);
                int j;
                for (j = i; j < num_tasks - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                num_tasks--;
                return;
            }
        } else if (current_hour == 14 && current_minute < 30) {
            if (task_list[i].priority >= 2) {
                printf("Executing task %s\n", task_list[i].name);
                int j;
                for (j = i; j < num_tasks - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                num_tasks--;
                return;
            }
        } else {
            if (task_list[i].priority >= 1) {
                printf("Executing task %s\n", task_list[i].name);
                int j;
                for (j = i; j < num_tasks - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                num_tasks--;
                return;
            }
        }
    }

    printf("No tasks to execute\n");
}

int main() {
    printf("Welcome to the Task Scheduler\n");

    while (1) {
        printf("\n1. Add Task\n");
        printf("2. Print Task List\n");
        printf("3. Execute Task\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter priority (1-5): ");
                int priority;
                scanf("%d", &priority);

                printf("Enter time needed (in minutes): ");
                int time;
                scanf("%d", &time);

                printf("Enter task name: ");
                char name[20];
                scanf("%s", name);

                add_task(priority, time, name);
                break;
            }
            case 2:
                print_task_list();
                break;
            case 3:
                execute_task();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}