//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    time_t scheduled_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, time_t schedule) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, TASK_NAME_LEN - 1);
        task_list[task_count].scheduled_time = schedule;
        task_count++;
        printf("Task '%s' has been scheduled for %s", name, ctime(&schedule));
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (current_time >= task_list[i].scheduled_time) {
            printf("Executing task: %s\n", task_list[i].name);
            // This is where the task action would take place.
            // Mark the task as executed could be done here.
            printf("Task '%s' has been executed.\n", task_list[i].name);
            // Shift tasks to remove executed task
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Decrement to check the next task at the same index
        }
    }
}

void show_tasks() {
    if (task_count == 0) {
        printf("No tasks are currently scheduled.\n");
        return;
    }
    printf("Scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. Task: '%s' at %s", i + 1, task_list[i].name, ctime(&task_list[i].scheduled_time));
    }
}

void wait_for_next_execution() {
    while (1) {
        execute_tasks();
        sleep(5); // Sleep for 5 seconds before checking tasks again
    }
}

void display_menu() {
    printf("Welcome to the Sherlock Holmes Task Scheduler!\n");
    printf("1. Add Task\n");
    printf("2. Show Tasks\n");
    printf("3. Start Scheduler\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    
    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); // consume newline character

        if (option == 1) {
            char task_name[TASK_NAME_LEN];
            int hours, minutes;
            time_t scheduled_time;

            printf("Enter the task name: ");
            fgets(task_name, TASK_NAME_LEN, stdin);
            task_name[strcspn(task_name, "\n")] = 0; // Remove newline

            printf("Enter hours for scheduling (0-23): ");
            scanf("%d", &hours);
            printf("Enter minutes for scheduling (0-59): ");
            scanf("%d", &minutes);

            // Set scheduled time for today
            time_t raw_time;
            struct tm *time_info;

            time(&raw_time);
            time_info = localtime(&raw_time);
            time_info->tm_hour = hours;
            time_info->tm_min = minutes;
            time_info->tm_sec = 0;

            scheduled_time = mktime(time_info);
            if (scheduled_time < raw_time) {
                // If the time is in the past, schedule for the next day
                time_info->tm_mday += 1;
                scheduled_time = mktime(time_info);
            }

            add_task(task_name, scheduled_time);
        } else if (option == 2) {
            show_tasks();
        } else if (option == 3) {
            wait_for_next_execution();
        } else if (option == 4) {
            printf("Exiting the Task Scheduler. Good day!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}