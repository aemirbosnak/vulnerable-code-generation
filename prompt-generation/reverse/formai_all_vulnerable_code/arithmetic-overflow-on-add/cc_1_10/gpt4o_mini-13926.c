//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef enum {
    SCHEDULED,
    RUNNING,
    COMPLETED
} TaskStatus;

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t schedule_time;
    TaskStatus status;
    void (*task_function)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, time_t schedule_time, void (*task_function)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Error: Task list is full!\n");
        return;
    }
    strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH);
    task_list[task_count].schedule_time = schedule_time;
    task_list[task_count].status = SCHEDULED;
    task_list[task_count].task_function = task_function;
    task_count++;
}

void run_task(Task *task) {
    printf("Running task: %s\n", task->name);
    task->status = RUNNING;
    task->task_function();
    task->status = COMPLETED;
    printf("Completed task: %s\n", task->name);
}

void check_and_run_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].status == SCHEDULED && task_list[i].schedule_time <= current_time) {
            run_task(&task_list[i]);
        }
    }
}

void example_task_1() {
    printf("Task 1 is executing...\n");
    sleep(1); 
}

void example_task_2() {
    printf("Task 2 is executing...\n");
    sleep(2); 
}

void example_task_3() {
    printf("Task 3 is executing...\n");
    sleep(1); 
}

int main() {
    printf("Task Scheduler Program\n");

    time_t current_time = time(NULL);

    // Schedule tasks
    add_task("Task 1", current_time + 2, example_task_1);
    add_task("Task 2", current_time + 3, example_task_2);
    add_task("Task 3", current_time + 1, example_task_3);

    // Run the scheduler loop
    while (task_count > 0) {
        check_and_run_tasks();
        sleep(1);

        // Remove completed tasks from the list
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].status == COMPLETED) {
                printf("Removing task: %s\n", task_list[i].name);
                for (int j = i; j < task_count - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                task_count--;
                i--; // Decrement i to stay at the same index after removal
            }
        }
    }

    printf("All tasks completed!\n");
    return 0;
}