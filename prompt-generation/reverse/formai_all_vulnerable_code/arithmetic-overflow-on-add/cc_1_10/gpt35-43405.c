//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 30

typedef struct Task {
    char name[MAX_TASK_NAME];
    int priority;
    time_t time_interval;
    time_t next_run;
} Task;

int num_tasks = 0;
Task tasks[MAX_TASKS];

void add_task(char name[], int priority, time_t time_interval) {
    if (num_tasks >= MAX_TASKS) {
        printf("Max number of tasks reached!\n");
        return;
    }

    Task task;
    strcpy(task.name, name);
    task.priority = priority;
    task.time_interval = time_interval;
    task.next_run = time(NULL);

    tasks[num_tasks] = task;
    num_tasks++;
    printf("Task '%s' added successfully!\n", task.name);
}

void execute_task(Task *task) {
    printf("Executing task '%s'...\n", task->name);
    // Do some task here
    time_t current_time = time(NULL);
    task->next_run = current_time + task->time_interval;
}

void run_scheduler() {
    printf("Task Scheduler running...\n");
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < num_tasks; i++) {
            Task *task = &tasks[i];
            if (task->next_run <= current_time) {
                execute_task(task);
            }
        }
        // Sleep for 1 second
        sleep(1);
    }
}

int main() {
    add_task("Task 1", 1, 5); // Execute every 5 seconds
    add_task("Task 2", 2, 10); // Execute every 10 seconds
    add_task("Task 3", 3, 15); // Execute every 15 seconds

    run_scheduler(); // Start the scheduler
    return 0;
}