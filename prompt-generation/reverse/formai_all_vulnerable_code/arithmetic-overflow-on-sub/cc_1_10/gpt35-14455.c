//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
/*
 * Simple Task Scheduler Example
 * Written in the style of Claude Shannon
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_TASKS 10

typedef struct task {
    int id;
    int priority;
    void (*func)(void);
    struct timeval last_executed;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

/*
 * Initializes a new task with the given priority and task function.
 */
void initialize_task(int priority, void (*func)(void)) {
    if (num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Task scheduler overflow!\n");
        return;
    }

    Task new_task;
    new_task.id = num_tasks++;
    new_task.priority = priority;
    new_task.func = func;
    gettimeofday(&new_task.last_executed, NULL);

    tasks[num_tasks-1] = new_task;

    printf("Initialized task %d with priority %d\n", new_task.id, new_task.priority);
}

/*
 * Runs the highest-priority task that is ready to run.
 */
void run_ready_task() {
    int highest_priority = -1;
    int highest_priority_idx = -1;
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (current_time.tv_sec - tasks[i].last_executed.tv_sec >= tasks[i].priority) {
            if (tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                highest_priority_idx = i;
            }
        }
    }

    if (highest_priority_idx >= 0) {
        tasks[highest_priority_idx].func();
        tasks[highest_priority_idx].last_executed = current_time;
        printf("Task %d executed\n", tasks[highest_priority_idx].id);
    } else {
        printf("No tasks ready to run\n");
    }
}

/*
 * Example task function: print out a message.
 */
void example_task_1() {
    printf("Task 1 running\n");
}

/*
 * Example task function: sleep for 2 seconds and print out a message.
 */
void example_task_2() {
    sleep(2);
    printf("Task 2 running\n");
}

int main() {
    // Initialize some example tasks
    initialize_task(1, example_task_1);
    initialize_task(2, example_task_2);
    initialize_task(1, example_task_1);

    // Run the task scheduler every second
    printf("Starting task scheduler...\n");
    while (1) {
        sleep(1);
        printf("---\nRunning task scheduler\n");
        run_ready_task();
    }

    return 0;
}