//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; // in seconds
    int next_run; // time for the next run
    void (*task_function)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void greet_task() {
    printf("Hello, this is Task Greeting at %ld\n", time(NULL));
}

void compute_task() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Sum of the first 100 numbers: %d at %ld\n", sum, time(NULL));
}

void schedule_task(const char *name, int interval, void (*task_function)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Maximum number of tasks reached!\n");
        return;
    }
    
    strcpy(task_list[task_count].name, name);
    task_list[task_count].interval = interval;
    task_list[task_count].next_run = time(NULL) + interval;
    task_list[task_count].task_function = task_function;
    task_count++;
    printf("Scheduled task: %s every %d seconds\n", name, interval);
}

void run_tasks() {
    while (1) {
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run) {
                task_list[i].task_function();
                task_list[i].next_run = current_time + task_list[i].interval;
            }
        }
        
        sleep(1); // Sleep for a second to prevent busy waiting
    }
}

int main() {
    printf("Welcome to the C Task Scheduler!\n");

    // Schedule some tasks
    schedule_task("Greeting Task", 5, greet_task);    // Every 5 seconds
    schedule_task("Compute Task", 10, compute_task);   // Every 10 seconds

    // Run the scheduler
    run_tasks();

    return 0;
}