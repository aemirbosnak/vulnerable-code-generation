//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 50

typedef struct {
    char name[MAX_TASK_NAME];
    time_t scheduled_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void display_tasks() {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s at %s", i + 1, task_list[i].name, ctime(&(task_list[i].scheduled_time)));
    }
}

void handle_sigint(int sig) {
    printf("\nExiting Task Scheduler...\n");
    exit(0);
}

void add_task(char *task_name, time_t scheduled_time) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, task_name, MAX_TASK_NAME);
        task_list[task_count].scheduled_time = scheduled_time;
        task_count++;
    } else {
        printf("Task list is full!\n");
    }
}

void execute_task(Task *task) {
    printf("Executing Task: %s\n", task->name);
    // Simulate task execution delay
    sleep(2);
    printf("Task %s completed!\n", task->name);
}

void scheduler_loop() {
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (difftime(current_time, task_list[i].scheduled_time) >= 0) {
                execute_task(&task_list[i]);
                // Remove task by shifting remaining tasks
                for (int j = i; j < task_count - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                task_count--;
                i--; // Adjust index after removal
            }
        }
        sleep(1); // Sleep for a second before checking again
    }
}

void load_tasks() {
    // For illustrative purposes, we will add some demo tasks
    time_t now = time(NULL);
    add_task("Task 1: Backup", now + 5); // 5 seconds from now
    add_task("Task 2: Cleanup", now + 10); // 10 seconds from now
    add_task("Task 3: Report Generation", now + 15); // 15 seconds from now
    add_task("Task 4: System Update", now + 20); // 20 seconds from now
}

int main() {
    signal(SIGINT, handle_sigint); // Handle Ctrl+C interrupt
    load_tasks();
    display_tasks();
    scheduler_loop();
    return 0;
}