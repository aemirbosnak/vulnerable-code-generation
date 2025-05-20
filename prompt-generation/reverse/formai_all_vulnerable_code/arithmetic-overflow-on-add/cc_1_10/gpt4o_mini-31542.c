//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t scheduled_time;
    int interval; // in seconds
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, time_t schedule_time, int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }
    
    strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH);
    task_list[task_count].scheduled_time = schedule_time;
    task_list[task_count].interval = interval;
    task_count++;
    
    printf("Task '%s' added. Scheduled for %s", name, ctime(&schedule_time));
}

void execute_task(const Task *task) {
    printf("Executing task: %s\n", task->name);
}

void run_scheduler() {
    while (1) {
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (difftime(current_time, task_list[i].scheduled_time) >= 0) {
                execute_task(&task_list[i]);
                task_list[i].scheduled_time += task_list[i].interval; // Reschedule for next interval
            }
        }

        sleep(1); // Sleep for a second before the next check
    }
}

void print_tasks() {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d: %s at %s (interval: %d seconds)\n", 
                i + 1, task_list[i].name, ctime(&task_list[i].scheduled_time), task_list[i].interval);
    }
}

int main() {
    time_t now = time(NULL);
    
    // Adding test tasks
    add_task("Task 1", now + 5, 10); // Schedule in 5 seconds, repeat every 10 seconds
    add_task("Task 2", now + 3, 15); // Schedule in 3 seconds, repeat every 15 seconds
    add_task("Task 3", now + 8, 20); // Schedule in 8 seconds, repeat every 20 seconds

    print_tasks();
    
    run_scheduler(); // Start the scheduler
    
    return 0;
}