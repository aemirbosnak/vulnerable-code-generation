//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int hour;
    int minute;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int hour, int minute) {
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH);
        tasks[task_count].hour = hour;
        tasks[task_count].minute = minute;
        task_count++;
        printf("Yay! Task '%s' added at %02d:%02d!\n", name, hour, minute);
    } else {
        printf("Oops! Can't add more tasks! Maximum limit reached.\n");
    }
}

void list_tasks() {
    if (task_count == 0) {
        printf("Oh no! No tasks to display! Let's add some!\n");
        return;
    }
    printf("Here are your tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s at %02d:%02d\n", i + 1, tasks[i].name, tasks[i].hour, tasks[i].minute);
    }
}

void execute_tasks() {
    time_t now;
    struct tm *current_time;

    time(&now);
    current_time = localtime(&now);

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].hour == current_time->tm_hour && tasks[i].minute == current_time->tm_min) {
            printf("Executing Task: %s! Hooray!\n", tasks[i].name);
        }
    }
}

void display_menu() {
    printf("\n***** Cheerful Task Scheduler *****\n");
    printf("1. Add a Task\n");
    printf("2. List all Tasks\n");
    printf("3. Execute Tasks\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char task_name[TASK_NAME_LENGTH];
    int hour, minute;

    while (1) {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the task name: ");
                scanf("%s", task_name);
                printf("Enter the time to run the task (hour and minute): ");
                scanf("%d %d", &hour, &minute);
                if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
                    add_task(task_name, hour, minute);
                } else {
                    printf("Oops! Time must be in valid range (0-23 for hour, 0-59 for minute).\n");
                }
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                printf("Thank you for using Cheerful Task Scheduler! Goodbye! 😊\n");
                exit(0);
            default:
                printf("Oops! Invalid option. Please try again!\n");
        }
    }

    return 0;
}