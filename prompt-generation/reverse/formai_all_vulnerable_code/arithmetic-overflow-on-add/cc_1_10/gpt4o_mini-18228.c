//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <string.h>

#define MAX_TASKS 10
#define BUFFER_SIZE 256

typedef struct {
    char name[50];
    time_t schedule_time;
    int interval; // in seconds
    int active;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int interval) {
    if (task_count < MAX_TASKS) {
        strcpy(tasks[task_count].name, name);
        tasks[task_count].schedule_time = time(NULL) + interval;
        tasks[task_count].interval = interval;
        tasks[task_count].active = 1;
        task_count++;
        printf("Task '%s' added. Schedule in %d seconds.\n", name, interval);
    } else {
        printf("Task Limit Reached! Cannot add more tasks.\n");
    }
}

void remove_task(const char *name) {
    for (int i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].name, name) == 0 && tasks[i].active) {
            tasks[i].active = 0;
            printf("Task '%s' removed.\n", name);
            return;
        }
    }
    printf("Task '%s' not found!\n", name);
}

void execute_task(Task *task) {
    if (task->active) {
        printf("Executing task: %s\n", task->name);
        // Simulate task execution duration
        sleep(2);
        printf("Task '%s' executed successfully!\n", task->name);
        task->schedule_time = time(NULL) + task->interval; // Reschedule
    }
}

void display_tasks() {
    printf("Current Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].active) {
            printf(" - %s (Scheduled at: %ld, Interval: %d seconds)\n",
                   tasks[i].name, (long)tasks[i].schedule_time, tasks[i].interval);
        }
    }
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nScheduler terminating...\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);
    
    add_task("Task1", 5);
    add_task("Task2", 10);
    add_task("Task3", 7);
    add_task("Task4", 3);
    
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].active && current_time >= tasks[i].schedule_time) {
                execute_task(&tasks[i]);
            }
        }
        
        display_tasks();
        printf("Waiting for tasks...\n");
        sleep(1); // Sleep for a second to avoid busy waiting
    }

    return 0;
}