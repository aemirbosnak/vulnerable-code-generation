//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 50

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int interval;
    int next_run_time;
} Task;

void add_task(Task* tasks, int num_tasks, char* name, int interval) {
    int i;

    for (i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("Task '%s' already exists.\n", name);
            return;
        }
    }

    if (num_tasks >= MAX_TASKS) {
        printf("Cannot add more tasks.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].next_run_time = time(NULL) + interval;

    num_tasks++;
}

void run_task(Task* tasks, int num_tasks) {
    int i;
    time_t current_time;

    current_time = time(NULL);

    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].next_run_time <= current_time) {
            printf("Running task '%s'...\n", tasks[i].name);
            tasks[i].next_run_time = current_time + tasks[i].interval;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task 1", 5);
    add_task(tasks, num_tasks, "Task 2", 10);
    add_task(tasks, num_tasks, "Task 3", 15);

    while (1) {
        run_task(tasks, num_tasks);
        sleep(1);
    }

    return 0;
}