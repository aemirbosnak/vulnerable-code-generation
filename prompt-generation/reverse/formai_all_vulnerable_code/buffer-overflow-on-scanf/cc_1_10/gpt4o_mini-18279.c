//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: complete
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
    int interval; // in seconds
    int active;   // whether the task is active
} Task;

void add_task(Task tasks[], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Cannot add more tasks. Maximum limit reached.\n");
        return;
    }

    Task new_task;
    printf("Enter task name: ");
    scanf("%s", new_task.name);
    printf("Enter task interval in seconds: ");
    scanf("%d", &new_task.interval);
    new_task.scheduled_time = time(NULL) + new_task.interval;
    new_task.active = 1;

    tasks[*task_count] = new_task;
    (*task_count)++;
    printf("Task added: %s (every %d seconds)\n", new_task.name, new_task.interval);
}

void display_tasks(Task tasks[], int task_count) {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s - Next run: %s", i + 1, tasks[i].name, ctime(&tasks[i].scheduled_time));
    }
}

void run_tasks(Task tasks[], int task_count) {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].active && current_time >= tasks[i].scheduled_time) {
            printf("Running task: %s\n", tasks[i].name);
            tasks[i].scheduled_time = current_time + tasks[i].interval;
        }
    }
}

void deactivate_task(Task tasks[], int *task_count) {
    int task_number;
    printf("Enter task number to deactivate: ");
    scanf("%d", &task_number);
    if (task_number > 0 && task_number <= *task_count) {
        tasks[task_number - 1].active = 0;
        printf("Task %s deactivated.\n", tasks[task_number - 1].name);
    } else {
        printf("Invalid task number.\n");
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;

    while (1) {
        int choice;
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Run Tasks\n");
        printf("4. Deactivate Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                display_tasks(tasks, task_count);
                break;
            case 3:
                run_tasks(tasks, task_count);
                break;
            case 4:
                deactivate_task(tasks, &task_count);
                break;
            case 5:
                printf("Exiting scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        sleep(1); // Pause for a second before the next iteration
    }

    return 0;
}