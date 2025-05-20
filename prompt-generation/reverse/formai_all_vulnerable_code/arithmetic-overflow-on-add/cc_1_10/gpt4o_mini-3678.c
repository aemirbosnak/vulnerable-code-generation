//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME 50
#define NAME_LEN sizeof("Task Name")

typedef struct {
    char name[MAX_NAME];
    int interval; // in seconds
    int next_run; // time when the task should next run
    void (*task_function)(); // function pointer for task execution
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    task->task_function();
}

void schedule_task(const char *name, int interval, void (*task_function)()) {
    if (task_count >= MAX_TASKS) {
        printf("Unable to schedule task. Max tasks reached!\n");
        return;
    }

    strcpy(task_list[task_count].name, name);
    task_list[task_count].interval = interval;
    task_list[task_count].next_run = time(NULL) + interval;
    task_list[task_count].task_function = task_function;
    task_count++;

    printf("Scheduled task: %s every %d seconds.\n", name, interval);
}

void task1() {
    printf("Task 1 is running: Checking system status!\n");
}

void task2() {
    printf("Task 2 is running: Performing cleanup!\n");
}

void task3() {
    printf("Task 3 is running: Updating references!\n");
}

void time_to_execute() {
    int current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (current_time >= task_list[i].next_run) {
            execute_task(&task_list[i]);
            task_list[i].next_run = current_time + task_list[i].interval; 
        }
    }
}

void signal_handler(int signum) {
    printf("\nCaught signal %d. Exiting gracefully...\n", signum);
    exit(0);
}

int main() {
    // Set up signal handling
    signal(SIGINT, signal_handler);
    
    printf("Shockingly Simple Task Scheduler!\n");
    schedule_task("System Status Checker", 2, task1);
    schedule_task("Periodic Cleanup", 5, task2);
    schedule_task("Reference Updater", 10, task3);

    // Main loop
    while (1) {
        time_to_execute();
        sleep(1); // Wait for 1 second before checking again
    }

    return 0;
}