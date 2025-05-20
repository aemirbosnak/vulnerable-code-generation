//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define NAME_MAX_LEN 50

typedef struct {
    char name[NAME_MAX_LEN];
    time_t start_time;
    time_t duration;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskScheduler;

void initializeScheduler(TaskScheduler *scheduler) {
    scheduler->count = 0;
}

int addTask(TaskScheduler *scheduler, const char *name, int duration) {
    if (scheduler->count >= MAX_TASKS) {
        printf("Task Scheduler is full. Cannot add more tasks.\n");
        return -1;
    }
    
    Task new_task;
    strncpy(new_task.name, name, NAME_MAX_LEN);
    new_task.start_time = time(NULL);
    new_task.duration = duration;
    scheduler->tasks[scheduler->count++] = new_task;
    
    printf("Added task: %s with duration %d seconds\n", new_task.name, new_task.duration);
    return 0;
}

void executeTasks(TaskScheduler *scheduler) {
    for (int i = 0; i < scheduler->count; ++i) {
        printf("Executing task: %s\n", scheduler->tasks[i].name);
        sleep(scheduler->tasks[i].duration);
        printf("Task %s completed.\n", scheduler->tasks[i].name);
    }
}

void displayTasks(TaskScheduler *scheduler) {
    printf("Current Tasks in Scheduler:\n");
    for (int i = 0; i < scheduler->count; ++i) {
        printf("%d: %s - Duration: %d seconds\n", i + 1, scheduler->tasks[i].name, scheduler->tasks[i].duration);
    }
}

int main() {
    TaskScheduler scheduler;
    initializeScheduler(&scheduler);
    
    int choice, duration;
    char name[NAME_MAX_LEN];
    
    do {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter task duration in seconds: ");
                scanf("%d", &duration);
                addTask(&scheduler, name, duration);
                break;
            case 2:
                executeTasks(&scheduler);
                break;
            case 3:
                displayTasks(&scheduler);
                break;
            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}