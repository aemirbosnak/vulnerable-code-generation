//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the maximum time to run the scheduler in seconds
#define MAX_TIME 60

// Define a struct to hold the information about each task
typedef struct {
    int id;
    int interval;
    int last_run;
    void (*task_function)(void);
} task_t;

// Define an array to hold the information about each task
task_t tasks[MAX_TASKS];

// Define the number of tasks currently scheduled
int num_tasks = 0;

// Define a function to add a new task to the scheduler
void add_task(void (*task_function)(void), int interval) {
    if (num_tasks < MAX_TASKS) {
        // Set the information about the new task
        tasks[num_tasks].id = num_tasks;
        tasks[num_tasks].interval = interval;
        tasks[num_tasks].last_run = time(NULL);
        tasks[num_tasks].task_function = task_function;

        // Increment the number of tasks
        num_tasks++;

        printf("Added new task with interval %d seconds.\n", interval);
    } else {
        printf("Unable to add new task: maximum number of tasks reached.\n");
    }
}

// Define a function to run the scheduler
int run_scheduler(int run_time) {
    int i, num_runs = 0;
    time_t start_time, current_time;

    start_time = time(NULL);

    while ((current_time = time(NULL)) - start_time < run_time) {
        // Check each task to see if it is due to run
        for (i = 0; i < num_tasks; i++) {
            if (current_time - tasks[i].last_run >= tasks[i].interval) {
                // Run the task function
                tasks[i].task_function();

                // Update the last run time
                tasks[i].last_run = current_time;

                // Increment the number of runs
                num_runs++;
            }
        }

        // Sleep for one second before checking the tasks again
        sleep(1);
    }

    return num_runs;
}

// Define some sample task functions
void task1(void) {
    printf("Task 1 done!\n");
}

void task2(void) {
    printf("Task 2 done!\n");
}

// Define the main function
int main(void) {
    int num_runs;

    // Add some tasks
    add_task(task1, 5);
    add_task(task2, 10);

    // Run the scheduler for one minute
    num_runs = run_scheduler(MAX_TIME);

    printf("Scheduler finished after %d runs.\n", num_runs);

    return 0;
}