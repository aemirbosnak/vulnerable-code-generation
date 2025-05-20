//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define BUFFER_SIZE 100

typedef struct {
    char name[TASK_NAME_LEN];
    time_t execution_time; // The time at which the task should be executed
    int period;            // Period in seconds for recurring tasks
    int repeat;            // Number of times to repeat (-1 for infinite)
    int is_active;         // Status of the task
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nThe world has fallen, but the tasks must finish! Exiting...\n");
        exit(0);
    }
}

void display_tasks() {
    printf("\n--- Current Tasks ---\n");
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].is_active) {
            printf("Task %d: %s, Execution Time: %s, Period: %d sec, Remaining: %d\n",
                   i + 1,
                   task_list[i].name,
                   ctime(&task_list[i].execution_time),
                   task_list[i].period,
                   task_list[i].repeat);
        }
    }
    printf("---------------------\n");
}

void execute_task(int index) {
    Task *task = &task_list[index];
    printf("Executing task: %s\n", task->name);
    
    // Here we can simulate task operation; it can be a placeholder for an actual function call.
    sleep(1); // Simulate execution time
    printf("Task %s completed!\n", task->name);

    // Update task based on repeat count
    if (task->repeat != 0) {
        task->execution_time += task->period;
        if (task->repeat > 0) {
            task->repeat--;
        }
    } 
    if (task->repeat == 0) {
        task->is_active = 0; // Deactivate task if no more repeats
    }
}

void add_task(char *name, int period, int repeat) {
    if (task_count >= MAX_TASKS) {
        printf("Maximum task limit reached!\n");
        return;
    }
    strcpy(task_list[task_count].name, name);
    task_list[task_count].execution_time = time(NULL) + 5; // Start execution in 5 seconds
    task_list[task_count].period = period;
    task_list[task_count].repeat = repeat;
    task_list[task_count].is_active = 1;
    task_count++;
}

void run_scheduler() {
    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].is_active && now >= task_list[i].execution_time) {
                execute_task(i);
            }
        }
        display_tasks();
        sleep(1); // Scheduler checks every second
    }
}

int main() {
    signal(SIGINT, handle_signal); // Handle Ctrl+C gracefully

    // Sample tasks to add
    add_task("Scavenge Supplies", 10, 5); // Repeat every 10 seconds, 5 times
    add_task("Activate Radio", 15, -1);    // Task that runs every 15 seconds
    add_task("Fortify Shelter", 20, 2);    // Repeat every 20 seconds, 2 times

    printf("Welcome to the Task Scheduler in a Post-Apocalyptic World!\n");
    run_scheduler();

    return 0;
}