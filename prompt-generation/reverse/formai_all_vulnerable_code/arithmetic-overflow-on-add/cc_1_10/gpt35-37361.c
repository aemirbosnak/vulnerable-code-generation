//FormAI DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    void (*function)(void);
    time_t deadline;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(void (*function)(void), int deadline) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: task list is full\n");
        return;
    }
    task_list[num_tasks].function = function;
    task_list[num_tasks].deadline = time(NULL) + deadline;
    num_tasks++;
}

void execute_task(Task task) {
    printf("Executing task\n");
    task.function();
}

void schedule_tasks() {
    while (num_tasks > 0) {
        time_t current_time = time(NULL);
        for (int i = 0; i < num_tasks; i++) {
            if (current_time >= task_list[i].deadline) {
                execute_task(task_list[i]);
                // remove task from list
                for (int j = i; j < num_tasks - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                num_tasks--;
                i--;
            }
        }
    }
}

void task1() {
    printf("Task 1\n");
}

void task2() {
    printf("Task 2\n");
}

void task3() {
    printf("Task 3\n");
}

int main() {
    add_task(task1, 2);
    add_task(task2, 5);
    add_task(task3, 8);

    schedule_tasks();

    return 0;
}