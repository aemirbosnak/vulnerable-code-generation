//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; // interval in seconds
    time_t last_run;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char* name, int interval) {
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH);
        tasks[task_count].interval = interval;
        tasks[task_count].last_run = 0; // Not run yet
        task_count++;
        printf("Task '%s' added with interval %d seconds.\n", name, interval);
    } else {
        printf("Task limit reached! Cannot add more tasks.\n");
    }
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s, Interval: %d seconds, Last Run: %s", 
               i + 1, tasks[i].name, tasks[i].interval, 
               tasks[i].last_run ? ctime(&tasks[i].last_run) : "Never run\n");
    }
}

void run_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (difftime(current_time, tasks[i].last_run) >= tasks[i].interval) {
            printf("Running task: %s\n", tasks[i].name);
            tasks[i].last_run = current_time; // Update last run time
        }
    }
}

void menu() {
    printf("\nTask Scheduler Menu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Run Tasks\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char name[TASK_NAME_LENGTH];
    int interval;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]%*c", name); // Read string with spaces
                printf("Enter interval in seconds: ");
                scanf("%d", &interval);
                add_task(name, interval);
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                run_tasks();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        sleep(1); // Sleep for 1 second before showing the menu again
    }

    return 0;
}