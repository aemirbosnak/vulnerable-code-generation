//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    void (*function)(void);
    time_t execution_time;
    bool executed;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(void (*function)(void), time_t execution_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    Task new_task = {num_tasks + 1, function, execution_time, false};
    task_list[num_tasks] = new_task;
    num_tasks++;
    printf("Task #%d added.\n", new_task.id);
}

void remove_task(int task_id) {
    bool found = false;
    for (int i = 0; i < num_tasks; i++) {
        if (task_list[i].id == task_id) {
            for (int j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            num_tasks--;
            found = true;
            break;
        }
    }

    if (found) {
        printf("Task #%d removed.\n", task_id);
    } else {
        printf("Error: Task #%d not found.\n", task_id);
    }
}

void execute_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < num_tasks; i++) {
        if (!task_list[i].executed && difftime(now, task_list[i].execution_time) >= 0) {
            printf("Executing task #%d...\n", task_list[i].id);
            task_list[i].function();
            task_list[i].executed = true;
        }
    }
}

void print_tasks() {
    printf("Current tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task #%d: Execution time = %s", task_list[i].id, asctime(localtime(&task_list[i].execution_time)));
    }
}

void task1() {
    printf("Hello from task 1!\n");
}

void task2() {
    printf("Hello from task 2!\n");
}

int main() {
    time_t now = time(NULL);

    add_task(task1, now + 5);
    add_task(task2, now + 10);

    while (num_tasks > 0) {
        print_tasks();
        execute_tasks();
        sleep(1);
    }

    printf("All tasks completed.\n");

    return 0;
}