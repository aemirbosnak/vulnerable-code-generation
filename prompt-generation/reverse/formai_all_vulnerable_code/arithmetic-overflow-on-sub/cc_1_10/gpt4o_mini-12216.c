//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t due_time;
    int completed; // 0 for not completed, 1 for completed
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void initialize_scheduler(TaskScheduler *scheduler) {
    scheduler->task_count = 0;
}

void add_task(TaskScheduler *scheduler, const char *name, time_t due_time) {
    if (scheduler->task_count < MAX_TASKS) {
        strcpy(scheduler->tasks[scheduler->task_count].name, name);
        scheduler->tasks[scheduler->task_count].due_time = due_time;
        scheduler->tasks[scheduler->task_count].completed = 0;
        scheduler->task_count++;
    } else {
        printf("Task Scheduler is full, cannot add more tasks.\n");
    }
}

void list_tasks(TaskScheduler *scheduler) {
    printf("\n== Current Tasks ==\n");
    for (int i = 0; i < scheduler->task_count; i++) {
        char buff[26];
        struct tm *tm_info;

        tm_info = localtime(&scheduler->tasks[i].due_time);
        strftime(buff, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("%d. [%s] %s (Due: %s)\n", i + 1,
               scheduler->tasks[i].completed ? "✓" : "✗",
               scheduler->tasks[i].name,
               buff);
    }
}

void mark_task_completed(TaskScheduler *scheduler, int task_number) {
    if (task_number < 1 || task_number > scheduler->task_count) {
        printf("Invalid task number.\n");
    } else {
        scheduler->tasks[task_number - 1].completed = 1;
        printf("Task '%s' marked as completed.\n", scheduler->tasks[task_number - 1].name);
    }
}

void display_menu() {
    printf("\n=== Task Scheduler Menu ===\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Mark Task Completed\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char task_name[TASK_NAME_LENGTH];
            int year, month, day, hour, minute;

            printf("Enter task name: ");
            getchar(); // Consume the newline character left by scanf
            fgets(task_name, TASK_NAME_LENGTH, stdin);
            task_name[strcspn(task_name, "\n")] = 0; // Remove trailing newline

            printf("Enter due date (YYYY MM DD HH MM): ");
            scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);

            struct tm due_time = {0};
            due_time.tm_year = year - 1900; // Year since 1900
            due_time.tm_mon = month - 1; // Months since January
            due_time.tm_mday = day;
            due_time.tm_hour = hour;
            due_time.tm_min = minute;
            time_t due_timestamp = mktime(&due_time);

            add_task(&scheduler, task_name, due_timestamp);
            printf("Task added successfully!\n");
        } else if (choice == 2) {
            list_tasks(&scheduler);
        } else if (choice == 3) {
            int task_number;
            printf("Enter task number to mark as completed: ");
            scanf("%d", &task_number);
            mark_task_completed(&scheduler, task_number);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Exiting Task Scheduler. Goodbye!\n");
    return 0;
}