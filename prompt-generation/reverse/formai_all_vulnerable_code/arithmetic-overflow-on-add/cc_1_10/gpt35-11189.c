//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_TIME 60

typedef void (*task_function_t)(void);

typedef struct {
    int id;
    time_t start_time;
    time_t run_time;
    task_function_t function;
} task_t;

task_t task_list[MAX_TASKS];
int num_tasks = 0;

void task1() {
    printf("Task 1 is running\n");
    sleep(5);
    printf("Task 1 has finished\n");
}

void task2() {
    printf("Task 2 is running\n");
    sleep(10);
    printf("Task 2 has finished\n");
}

void task3() {
    printf("Task 3 is running\n");
    sleep(15);
    printf("Task 3 has finished\n");
}

void add_task(task_function_t function, int run_time) {
    if (num_tasks < MAX_TASKS) {
        task_list[num_tasks].id = num_tasks + 1;
        task_list[num_tasks].start_time = time(NULL);
        task_list[num_tasks].run_time = run_time;
        task_list[num_tasks].function = function;
        num_tasks++;
        printf("Task added successfully\n");
    } else {
        printf("Cannot add task - maximum number of tasks reached\n");
    }
}

void remove_task(int task_id) {
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].id == task_id) {
            for (j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Task removed successfully\n");
            return;
        }
    }
    printf("Cannot remove task - task with given ID not found\n");
}

void scheduler() {
    int i;
    time_t current_time;
    while (1) {
        current_time = time(NULL);
        for (i = 0; i < num_tasks; i++) {
            if (current_time >= task_list[i].start_time + task_list[i].run_time) {
                task_list[i].function();
                task_list[i].start_time = current_time;
            }
        }
        sleep(1);
    }
}

int main(void) {
    add_task(task1, 10);
    add_task(task2, 20);
    add_task(task3, 30);
    scheduler();
    return 0;
}