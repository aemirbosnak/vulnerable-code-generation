//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 32

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t delay; // Delay in seconds before starting the task
    void (*task_func)(); // Pointer to the task function
    time_t next_run; // Time for next execution
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

// Function declarations
void add_task(const char *name, time_t delay, void (*task_func)());
void execute_task(Task *task);
void sample_task1();
void sample_task2();
void display_tasks();

void signal_handler(int signum) {
    printf("\nReceived signal %d. Exiting...\n", signum);
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    add_task("Task 1", 5, sample_task1);
    add_task("Task 2", 10, sample_task2);
    
    while (1) {
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run) {
                execute_task(&task_list[i]);
                task_list[i].next_run = current_time + task_list[i].delay;
            }
        }

        sleep(1); // Main loop sleeps to reduce CPU usage
    }

    return 0;
}

void add_task(const char *name, time_t delay, void (*task_func)()) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH);
        task_list[task_count].delay = delay;
        task_list[task_count].task_func = task_func;
        task_list[task_count].next_run = time(NULL) + delay;
        task_count++;
        printf("Added: %s | Delay: %ld seconds\n", name, delay);
    } else {
        fprintf(stderr, "Error: Maximum number of tasks reached.\n");
    }
}

void execute_task(Task *task) {
    printf("Executing %s...\n", task->name);
    task->task_func();
}

void sample_task1() {
    printf("Sample Task 1 is running.\n");
}

void sample_task2() {
    printf("Sample Task 2 is running.\n");
}

void display_tasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task Name: %s | Next Run: %ld\n", 
               task_list[i].name, 
               task_list[i].next_run);
    }
}