//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t time_to_run;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void initialize_scheduler(TaskScheduler *scheduler);
void add_task(TaskScheduler *scheduler);
void display_tasks(TaskScheduler *scheduler);
void execute_tasks(TaskScheduler *scheduler);
void wait_for_next_execution(TaskScheduler *scheduler);

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    int choice;
    do {
        printf("\n🎉 Welcome to the Exciting Task Scheduler! 🎉\n");
        printf("1. Add a Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_task(&scheduler);
                break;
            case 2:
                display_tasks(&scheduler);
                break;
            case 3:
                wait_for_next_execution(&scheduler);
                break;
            case 4:
                printf("Exiting the Task Scheduler. Goodbye! 👋\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void initialize_scheduler(TaskScheduler *scheduler) {
    scheduler->task_count = 0;
}

void add_task(TaskScheduler *scheduler) {
    if (scheduler->task_count >= MAX_TASKS) {
        printf("😱 Task limit reached! Can't add more tasks.\n");
        return;
    }

    Task new_task;
    printf("Enter task name: ");
    fgets(new_task.name, TASK_NAME_LENGTH, stdin);
    new_task.name[strcspn(new_task.name, "\n")] = 0;  // Remove newline character

    printf("Enter time to run (in seconds from now): ");
    int delay;
    scanf("%d", &delay);
    getchar(); // Consume newline character
    new_task.time_to_run = time(NULL) + delay;

    scheduler->tasks[scheduler->task_count++] = new_task;
    printf("🎉 Task '%s' scheduled to run in %d seconds!\n", new_task.name, delay);
}

void display_tasks(TaskScheduler *scheduler) {
    if (scheduler->task_count == 0) {
        printf("No tasks scheduled yet! Add some tasks! 🌟\n");
        return;
    }

    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < scheduler->task_count; i++) {
        printf("%d. %s - Scheduled time: %ld seconds from now\n", 
               i + 1, scheduler->tasks[i].name, 
               (long)(scheduler->tasks[i].time_to_run - time(NULL)));
    }
}

void execute_tasks(TaskScheduler *scheduler) {
    printf("🔍 Executing Scheduled Tasks:\n");
    time_t current_time = time(NULL);
    
    for (int i = 0; i < scheduler->task_count; i++) {
        if (scheduler->tasks[i].time_to_run <= current_time) {
            printf("🚀 Executing Task: %s!\n", scheduler->tasks[i].name);
            // Here you can add the logic to run the actual task
            // Currently, we only print the execution message
            // After executing, shift the remaining tasks up
            for (int j = i; j < scheduler->task_count - 1; j++) {
                scheduler->tasks[j] = scheduler->tasks[j + 1];
            }
            scheduler->task_count--;
            i--; // Adjust index as tasks were shifted
        }
    }

    if (scheduler->task_count == 0) {
        printf("🌈 All tasks executed! No more tasks to execute!\n");
    }
}

void wait_for_next_execution(TaskScheduler *scheduler) {
    while (1) {
        execute_tasks(scheduler);
        if (scheduler->task_count == 0) {
            break;
        }
        sleep(1); // Wait for 1 second before checking tasks again
    }
}