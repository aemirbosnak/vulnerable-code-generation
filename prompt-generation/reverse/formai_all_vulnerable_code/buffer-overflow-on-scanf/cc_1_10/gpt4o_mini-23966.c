//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t scheduled_time;
    int repeat_interval; // in seconds
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char* name, time_t scheduled_time, int repeat_interval) {
    if (task_count < MAX_TASKS) {
        strcpy(task_list[task_count].name, name);
        task_list[task_count].scheduled_time = scheduled_time;
        task_list[task_count].repeat_interval = repeat_interval;
        task_count++;
    } else {
        printf("Task limit reached! Unable to add more tasks.\n");
    }
}

void display_tasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        struct tm *tm_info = localtime(&task_list[i].scheduled_time);
        char buffer[26];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Task %d: Name: %s, Scheduled Time: %s, Repeat Interval: %d seconds\n",
               i + 1, task_list[i].name, buffer, task_list[i].repeat_interval);
    }
}

void execute_tasks() {
    time_t current_time;
    while (1) {
        current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (difftime(current_time, task_list[i].scheduled_time) >= 0) {
                printf("Executing: %s\n", task_list[i].name);
                // Reschedule the task if it has a repeat interval
                task_list[i].scheduled_time += task_list[i].repeat_interval;
            }
        }
        sleep(1);  // Reduce CPU usage
    }
}

void remove_task(int task_index) {
    if (task_index >= 0 && task_index < task_count) {
        for (int i = task_index; i < task_count - 1; i++) {
            task_list[i] = task_list[i + 1];
        }
        task_count--;
        printf("Task removed.\n");
    } else {
        printf("Invalid task index!\n");
    }
}

int main() {
    time_t now = time(NULL);
    int choice;
    char task_name[MAX_NAME_LENGTH];
    int repeat_interval;

    while (1) {
        printf("\nSimple Task Scheduler\n");
        printf("1. Add a task\n");
        printf("2. Display tasks\n");
        printf("3. Remove a task\n");
        printf("4. Run the scheduler\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(task_name, sizeof(task_name), stdin);
                task_name[strcspn(task_name, "\n")] = '\0'; // Remove newline

                printf("Enter scheduled time (in seconds from now): ");
                int seconds;
                scanf("%d", &seconds);
                
                printf("Enter repeat interval (seconds, 0 for no repeat): ");
                scanf("%d", &repeat_interval);
                
                add_task(task_name, now + seconds, repeat_interval);
                break;

            case 2:
                display_tasks();
                break;

            case 3:
                printf("Enter task index to remove (1 to %d): ", task_count);
                int task_index;
                scanf("%d", &task_index);
                remove_task(task_index - 1);
                break;

            case 4:
                printf("Starting scheduler...\n");
                execute_tasks();
                break;

            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}