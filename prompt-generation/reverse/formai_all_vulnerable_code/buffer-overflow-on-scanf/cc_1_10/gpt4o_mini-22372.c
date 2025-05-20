//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_DESC_LENGTH 256

typedef struct {
    char description[TASK_DESC_LENGTH];
    int delay;  // delay in seconds
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void initialize_scheduler(TaskScheduler* scheduler) {
    scheduler->task_count = 0;
}

int add_task(TaskScheduler* scheduler, const char* description, int delay) {
    if (scheduler->task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return -1;
    }
    
    Task new_task;
    strncpy(new_task.description, description, TASK_DESC_LENGTH);
    new_task.delay = delay;

    scheduler->tasks[scheduler->task_count] = new_task;
    scheduler->task_count++;

    return 0;
}

void execute_task(const Task* task) {
    printf("Executing task: %s\n", task->description);
}

void run_scheduler(TaskScheduler* scheduler) {
    for (int i = 0; i < scheduler->task_count; i++) {
        Task current_task = scheduler->tasks[i];

        printf("Scheduling task: %s to run in %d seconds...\n", current_task.description, current_task.delay);
        sleep(current_task.delay);
        execute_task(&current_task);
    }
}

void display_tasks(TaskScheduler* scheduler) {
    if (scheduler->task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    printf("Scheduled tasks:\n");
    for (int i = 0; i < scheduler->task_count; i++) {
        printf("%d: %s (in %d seconds)\n", i + 1, scheduler->tasks[i].description, scheduler->tasks[i].delay);
    }
}

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    int option;
    char description[TASK_DESC_LENGTH];
    int delay;

    while (1) {
        printf("\nTask Scheduler Menu\n");
        printf("1. Add a Task\n");
        printf("2. Run Scheduler\n");
        printf("3. Display Scheduled Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter task description: ");
                getchar();  // Clear newline character from buffer
                fgets(description, TASK_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0;  // Remove newline
                
                printf("Enter delay (seconds): ");
                scanf("%d", &delay);
                
                add_task(&scheduler, description, delay);
                break;
            case 2:
                run_scheduler(&scheduler);
                break;
            case 3:
                display_tasks(&scheduler);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}