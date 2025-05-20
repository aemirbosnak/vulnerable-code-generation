//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50
#define TIME_BUFFER 26

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t time_to_run;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void add_task(TaskScheduler *scheduler, const char *name, int seconds_from_now) {
    if (scheduler->task_count < MAX_TASKS) {
        time_t now;
        time(&now);
        scheduler->tasks[scheduler->task_count].time_to_run = now + seconds_from_now;
        strncpy(scheduler->tasks[scheduler->task_count].name, name, TASK_NAME_LENGTH - 1);
        scheduler->tasks[scheduler->task_count].name[TASK_NAME_LENGTH - 1] = '\0'; // Null-terminate
        scheduler->task_count++;
        printf("Task \"%s\" scheduled to run in %d seconds.\n", name, seconds_from_now);
    } else {
        printf("Task Scheduler is full. Cannot add more tasks.\n");
    }
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
}

void check_tasks(TaskScheduler *scheduler) {
    time_t now;
    time(&now);
    for (int i = 0; i < scheduler->task_count; i++) {
        if (scheduler->tasks[i].time_to_run <= now) {
            execute_task(&scheduler->tasks[i]);
            // Remove the task and compact the array
            for (int j = i; j < scheduler->task_count - 1; j++) {
                scheduler->tasks[j] = scheduler->tasks[j + 1];
            }
            scheduler->task_count--;
            i--; // Stay at the same index for the next iteration
        }
    }
}

void display_tasks(TaskScheduler *scheduler) {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < scheduler->task_count; i++) {
        char time_buf[TIME_BUFFER];
        struct tm *tm_info;
        tm_info = localtime(&scheduler->tasks[i].time_to_run);
        strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
        printf(" - [%s] %s\n", time_buf, scheduler->tasks[i].name);
    }
}

void signal_handler(int signal) {
    printf("\nSignal received: %d. Stopping the scheduler.\n", signal);
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);

    TaskScheduler scheduler;
    scheduler.task_count = 0;

    int choice;
    char task_name[TASK_NAME_LENGTH];
    int delay;

    while (1) {
        printf("Task Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Check Executions\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(task_name, TASK_NAME_LENGTH, stdin);
                task_name[strcspn(task_name, "\n")] = 0; // Remove newline character
                printf("Enter delay in seconds: ");
                scanf("%d", &delay);
                add_task(&scheduler, task_name, delay);
                break;
            case 2:
                display_tasks(&scheduler);
                break;
            case 3:
                printf("Checking tasks...\n");
                check_tasks(&scheduler);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
        sleep(1); // Avoid busy-waiting
    }
    return 0;
}