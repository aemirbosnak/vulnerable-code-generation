//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    void (*run)();
    time_t start_time;
    time_t delay;
    time_t interval;
} Task;

Task* tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(Task* task) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Task limit reached.\n");
        return;
    }
    tasks[num_tasks++] = task;
}

void remove_task(Task* task) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i] == task) {
            tasks[i] = tasks[--num_tasks];
            return;
        }
    }
}

void scheduler() {
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            Task* task = tasks[i];
            time_t now = time(NULL);
            if (now >= task->start_time + task->delay) {
                task->run();
                if (task->interval > 0) {
                    task->start_time = now;
                } else {
                    remove_task(task);
                }
            }
        }
        sleep(1);
    }
}

void task1_fn() {
    printf("Task 1 executed at %ld.\n", time(NULL));
}

void task2_fn() {
    printf("Task 2 executed at %ld.\n", time(NULL));
}

int main() {
    Task task1 = { task1_fn, time(NULL), 0, 5 };
    Task task2 = { task2_fn, time(NULL), 1, 3 };
    
    add_task(&task1);
    add_task(&task2);
    
    scheduler();
    
    return 0;
}