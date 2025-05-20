//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Struct for a task to be scheduled
typedef struct {
    int task_id;
    char *task_name;
    int priority;
    int seconds_delay;
} Task;

// Struct for a scheduled task
typedef struct {
    Task *task;
    time_t scheduled_time;
} ScheduledTask;

// Function to initialize a new task
Task *new_task(int task_id, char *task_name, int priority, int seconds_delay) {
    Task *new_task = malloc(sizeof(Task));
    new_task->task_id = task_id;
    new_task->task_name = task_name;
    new_task->priority = priority;
    new_task->seconds_delay = seconds_delay;
    return new_task;
}

// Function to print a task
void print_task(Task *task) {
    printf("Task %d: %s (Priority: %d, Delay: %d seconds)\n", task->task_id, task->task_name, task->priority, task->seconds_delay);
}

// Function to initialize a new scheduled task
ScheduledTask *new_scheduled_task(Task *task, time_t scheduled_time) {
    ScheduledTask *new_scheduled_task = malloc(sizeof(ScheduledTask));
    new_scheduled_task->task = task;
    new_scheduled_task->scheduled_time = scheduled_time;
    return new_scheduled_task;
}

// Function to print a scheduled task
void print_scheduled_task(ScheduledTask *scheduled_task) {
    print_task(scheduled_task->task);
    char scheduled_time_str[100];
    strftime(scheduled_time_str, sizeof(scheduled_time_str), "%Y-%m-%d %H:%M:%S", localtime(&scheduled_task->scheduled_time));
    printf("Scheduled Time: %s\n", scheduled_time_str);
}

// Function to compare scheduled tasks by scheduled time
int compare_scheduled_tasks(const void *a, const void *b) {
    return ((ScheduledTask *)a)->scheduled_time - ((ScheduledTask *)b)->scheduled_time;
}

// Main function for scheduling tasks
int main() {
    // Initialize task list
    Task *task1 = new_task(1, "Task 1", 3, 10);
    Task *task2 = new_task(2, "Task 2", 1, 2);
    Task *task3 = new_task(3, "Task 3", 2, 5);
    Task *task4 = new_task(4, "Task 4", 3, 15);

    // Initialize scheduled task list
    ScheduledTask *scheduled_tasks[4];
    scheduled_tasks[0] = new_scheduled_task(task1, time(NULL) + task1->seconds_delay);
    scheduled_tasks[1] = new_scheduled_task(task2, time(NULL) + task2->seconds_delay);
    scheduled_tasks[2] = new_scheduled_task(task3, time(NULL) + task3->seconds_delay);
    scheduled_tasks[3] = new_scheduled_task(task4, time(NULL) + task4->seconds_delay);

    // Sort scheduled tasks by scheduled time
    qsort(scheduled_tasks, 4, sizeof(ScheduledTask *), compare_scheduled_tasks);

    // Schedule tasks
    while (1) {
        // Get current time
        time_t current_time = time(NULL);

        // Execute scheduled tasks
        for (int i = 0; i < 4; i++) {
            ScheduledTask *scheduled_task = scheduled_tasks[i];
            if (scheduled_task->scheduled_time <= current_time) {
                printf("Executing task:\n");
                print_scheduled_task(scheduled_task);

                // Remove scheduled task from list
                free(scheduled_task->task);
                free(scheduled_task);
                scheduled_tasks[i] = NULL;

                // Reschedule task
                if (i < 3) {
                    scheduled_tasks[i] = new_scheduled_task(scheduled_tasks[i+1]->task, current_time + scheduled_tasks[i+1]->task->seconds_delay);
                }
            }
        }

        // Sort scheduled tasks by scheduled time
        qsort(scheduled_tasks, 4, sizeof(ScheduledTask *), compare_scheduled_tasks);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}