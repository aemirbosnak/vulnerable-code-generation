//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 20

typedef struct {
    int task_id;
    char task_name[MAX_TASK_NAME];
    int task_frequency;
    time_t last_run_time;
} TASK;

TASK tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char* name, int frequency) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strncpy(tasks[num_tasks].task_name, name, MAX_TASK_NAME);
    tasks[num_tasks].task_frequency = frequency;
    tasks[num_tasks].last_run_time = 0;
    num_tasks++;
}

void run_tasks() {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].last_run_time + tasks[i].task_frequency <= current_time) {
            tasks[i].last_run_time = current_time;
            printf("Running task %s\n", tasks[i].task_name);
        }
    }
}

int main() {
    add_task("Task A", 5);
    add_task("Task B", 10);
    add_task("Task C", 15);

    while (1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}