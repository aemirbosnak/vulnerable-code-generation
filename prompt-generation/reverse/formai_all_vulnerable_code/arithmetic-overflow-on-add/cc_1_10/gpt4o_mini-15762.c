//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 50
#define TASK_NAME_LEN 20

typedef struct {
    char name[TASK_NAME_LEN];
    time_t time_to_run;
    int periodic; // 0 for non-periodic, 1 for periodic
    int interval; // interval in seconds for periodic tasks
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
volatile int running = 1;

void signal_handler(int signum) {
    running = 0;
}

void add_task(const char *name, time_t time_to_run, int periodic, int interval) {
    if (task_count < MAX_TASKS) {
        snprintf(task_list[task_count].name, TASK_NAME_LEN, "%s", name);
        task_list[task_count].time_to_run = time_to_run;
        task_list[task_count].periodic = periodic;
        task_list[task_count].interval = interval;

        task_count++;
        printf("Task \"%s\" added to the scheduler.\n", name);
    } else {
        printf("Error: Maximum task limit reached!\n");
    }
}

void run_task(Task task) {
    char command[50];
    snprintf(command, sizeof(command), "echo \"%s executed at %s\"", task.name, ctime(&task.time_to_run));
    system(command);
}

void check_tasks() {
    time_t current_time;
    time(&current_time);

    for (int i = 0; i < task_count; i++) {
        if (task_list[i].time_to_run <= current_time) {
            run_task(task_list[i]);

            if (task_list[i].periodic) {
                task_list[i].time_to_run += task_list[i].interval;
            } else {
                // Move the last task to this position and decrease count
                task_list[i] = task_list[task_count - 1];
                task_count--;
                i--; // Check this position again
            }
        }
    }
}

void print_tasks() {
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task: %s, Scheduled Time: %s", task_list[i].name, ctime(&task_list[i].time_to_run));
    }
    printf("\n");
}

int main() {
    signal(SIGINT, signal_handler);

    printf("=== Post-Apocalyptic Task Scheduler ===\n");

    time_t now;
    time(&now);
    
    // Schedule some tasks
    add_task("Collect Water", now + 5, 1, 10); // will run every 10 seconds
    add_task("Scout the Area", now + 3, 0, 0); // only once
    add_task("Check Traps", now + 15, 1, 15); // will run every 15 seconds
    add_task("Inventory Supplies", now + 20, 0, 0); // only once

    while (running) {
        check_tasks();
        print_tasks();
        sleep(1); // Check every second
    }

    printf("\nPost-Apocalyptic Scheduler terminated!\n");
    return 0;
}