//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; // in seconds
    time_t next_run; // when it should be run next
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    Task new_task;

    printf("Enter task name: ");
    scanf("%s", new_task.name);
    printf("Enter task interval in seconds: ");
    scanf("%d", &new_task.interval);

    // Calculate the next run time
    new_task.next_run = time(NULL) + new_task.interval;
    task_list[task_count++] = new_task;

    printf("Task '%s' added with an interval of %d seconds.\n", new_task.name, new_task.interval);
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. Name: %s, Interval: %d seconds, Next Run: %s", 
               i + 1, 
               task_list[i].name, 
               task_list[i].interval, 
               ctime(&(task_list[i].next_run)));
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);

    for (int i = 0; i < task_count; i++) {
        if (current_time >= task_list[i].next_run) {
            printf("Executing task: %s\n", task_list[i].name);
            // Simulate task execution by printing a message
            // In a real scenario, you would execute some function here
            
            // Schedule the next run
            task_list[i].next_run = current_time + task_list[i].interval;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n2. View Tasks\n3. Execute Tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Sleep for a while before showing the menu again
        sleep(1);
    }

    return 0;
}