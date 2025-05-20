//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    time_t execution_time;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void add_task(TaskScheduler *scheduler, const char *name, time_t execution_time) {
    if (scheduler->task_count < MAX_TASKS) {
        strcpy(scheduler->tasks[scheduler->task_count].name, name);
        scheduler->tasks[scheduler->task_count].execution_time = execution_time;
        scheduler->task_count++;
    } else {
        printf("Task limit reached!\n");
    }
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
}

void run_scheduled_tasks(TaskScheduler *scheduler, time_t current_time) {
    if (scheduler->task_count == 0) {
        printf("No tasks to execute.\n");
        return;
    }

    int executed_tasks = 0;

    for (int i = 0; i < scheduler->task_count; i++) {
        if (scheduler->tasks[i].execution_time <= current_time) {
            execute_task(&scheduler->tasks[i]);
            executed_tasks++;
        }
    }

    if (executed_tasks > 0) {
        // Adjust the task list by removing executed tasks
        for (int i = 0; i < scheduler->task_count; i++) {
            if (scheduler->tasks[i].execution_time <= current_time) {
                for (int j = i; j < scheduler->task_count - 1; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                scheduler->task_count--;
                i--; // Check the same index again after removal
            }
        }
    }

    // Recursive call to continue executing any remaining tasks after a second
    sleep(1); // Simulate waiting for one second
    run_scheduled_tasks(scheduler, time(NULL));
}

int main() {
    TaskScheduler scheduler;
    scheduler.task_count = 0;

    time_t current_time = time(NULL);
    add_task(&scheduler, "Task 1", current_time + 3); // Execute after 3 seconds
    add_task(&scheduler, "Task 2", current_time + 5); // Execute after 5 seconds
    add_task(&scheduler, "Task 3", current_time + 10); // Execute after 10 seconds
    add_task(&scheduler, "Task 4", current_time + 2); // Execute after 2 seconds

    printf("Starting Task Scheduler...\n");
    run_scheduled_tasks(&scheduler, current_time);

    return 0;
}