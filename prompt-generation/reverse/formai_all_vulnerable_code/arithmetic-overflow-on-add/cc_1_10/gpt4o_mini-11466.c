//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    time_t execute_time;
    void (*task_function)();
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(char *name, time_t execute_time, void (*task_function)()) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    strncpy(tasks[task_count].name, name, TASK_NAME_LEN - 1);
    tasks[task_count].execute_time = execute_time;
    tasks[task_count].task_function = task_function;
    task_count++;
}

void remove_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid task index!\n");
        return;
    }
    for (int i = index; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
}

void list_tasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("[%d] %s - Scheduled at: %s", i, tasks[i].name, ctime(&tasks[i].execute_time));
    }
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    task->task_function();
}

void dummy_task() {
    printf("This is a dummy task running!\n");
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nShutting down the task scheduler... Goodbye!\n");
        exit(0);
    }
}

void scheduler_loop() {
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].execute_time <= current_time) {
                execute_task(&tasks[i]);
                remove_task(i);
                i--; // Adjust index after removing
            }
        }
        sleep(1); // Check every second
    }
}

int main() {
    signal(SIGINT, signal_handler);
    
    printf("Welcome to the Configurable Task Scheduler!\n");

    // Example tasks
    time_t now = time(NULL);
    
    add_task("Dummy Task 1", now + 5, dummy_task);
    add_task("Dummy Task 2", now + 10, dummy_task);
    add_task("Dummy Task 3", now + 15, dummy_task);
    
    list_tasks();

    printf("Starting the scheduler...\n");
    scheduler_loop();

    return 0;
}