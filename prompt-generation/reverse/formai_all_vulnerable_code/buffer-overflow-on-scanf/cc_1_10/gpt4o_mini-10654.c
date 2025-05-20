//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_COMMAND_LENGTH 256

typedef struct {
    int id;
    char command[MAX_COMMAND_LENGTH];
    time_t scheduled_time;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Gratitude for your enthusiasm, but task limit reached!\n");
        return;
    }

    Task new_task;
    new_task.id = task_count + 1;

    printf("Please enter the command for Task %d: ", new_task.id);
    scanf(" %[^\n]", new_task.command);

    printf("When do you want to execute this task? (Format: YYYY-MM-DD HH:MM:SS): ");
    char input_time[20];
    scanf(" %[^\n]", input_time);

    struct tm tm;
    strptime(input_time, "%Y-%m-%d %H:%M:%S", &tm);
    new_task.scheduled_time = mktime(&tm);

    if (new_task.scheduled_time == -1) {
        printf("Invalid time format. Please try again!\n");
        return;
    }

    tasks[task_count] = new_task;
    task_count++;
    printf("Task added successfully! Thank you for using our scheduler.\n");
}

void display_tasks() {
    printf("Here are the scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task ID: %d\nCommand: %s\nScheduled Time: %s", 
                tasks[i].id, 
                tasks[i].command, 
                ctime(&tasks[i].scheduled_time));
    }
}

void execute_tasks() {
    time_t now;
    while (1) {
        now = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].scheduled_time <= now) {
                printf("Executing Task ID %d: %s\n", tasks[i].id, tasks[i].command);
                system(tasks[i].command); // Execute command in a shell
                tasks[i].scheduled_time = 0; // Mark as executed
            }
        }
        sleep(1); // Check every second
    }
}

int main() {
    printf("Welcome to the Grateful Task Scheduler!\n");
    int choice;

    while (1) {
        printf("\n1. Add Task\n2. Display Tasks\n3. Start Scheduler\n4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                printf("Starting the scheduler! Thank you for trusting us to manage your tasks.\n");
                execute_tasks();
                break;
            case 4:
                printf("Exiting the Grateful Task Scheduler. Thank you and have a wonderful day!\n");
                exit(0);
            default:
                printf("Invalid option, please try again with gratitude!\n");
        }
    }

    return 0;
}