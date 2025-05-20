//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define MAX_CMD_LEN 100

typedef struct {
    char name[TASK_NAME_LEN];
    char command[MAX_CMD_LEN];
    time_t execute_time;
} Task;

// Global array to hold the scheduled tasks
Task tasks[MAX_TASKS];
int task_count = 0;

// Function to add a new task
void add_task(char *name, char *command, time_t execute_time) {
    if (task_count < MAX_TASKS) {
        strcpy(tasks[task_count].name, name);
        strcpy(tasks[task_count].command, command);
        tasks[task_count].execute_time = execute_time;
        task_count++;
        printf("Task '%s' scheduled successfully.\n", name);
    } else {
        printf("Maximum task limit reached. Cannot schedule more tasks.\n");
    }
}

// Function to display all scheduled tasks
void display_tasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s\nCommand: %s\nExecute Time: %s",
               i + 1, tasks[i].name, tasks[i].command, ctime(&tasks[i].execute_time));
    }
}

// Function to execute tasks if their scheduled time has arrived
void execute_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].execute_time <= now) {
            printf("Executing task '%s': ", tasks[i].name);
            system(tasks[i].command);
            // Remove the executed task by shifting tasks down
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            task_count--;
            i--; // Adjust index since we shifted tasks
        }
    }
}

void show_menu() {
    printf("Task Scheduler Menu:\n");
    printf("1. Add Task\n");
    printf("2. Display Tasks\n");
    printf("3. Execute Tasks\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char name[TASK_NAME_LEN], command[MAX_CMD_LEN];
    struct tm tm;
    time_t execute_time;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character after number input

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, TASK_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter command to execute: ");
                fgets(command, MAX_CMD_LEN, stdin);
                command[strcspn(command, "\n")] = 0; // Remove newline

                printf("Enter execution time (YYYY-MM-DD HH:MM): ");
                scanf("%d-%d-%d %d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
                tm.tm_year -= 1900; // Adjust the year
                tm.tm_mon -= 1; // Adjust the month
                tm.tm_sec = 0;
                tm.tm_isdst = -1; // Not considering daylight saving time
                execute_time = mktime(&tm);

                add_task(name, command, execute_time);
                break;

            case 2:
                display_tasks();
                break;

            case 3:
                execute_tasks();
                break;

            case 4:
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}