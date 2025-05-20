//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char *name;
    time_t start_time;
    time_t end_time;
    int duration;
} task_t;

void add_task(task_t *tasks, int num_tasks, int id, char *name, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    tasks[num_tasks].id = id;
    tasks[num_tasks].name = name;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    tasks[num_tasks].duration = end_time - start_time;

    num_tasks++;
}

void display_tasks(task_t *tasks, int num_tasks) {
    printf("Task ID | Task Name | Start Time | End Time | Duration\n");

    for (int i = 0; i < num_tasks; i++) {
        printf("%d | %s | %s | %s | %d seconds\n", tasks[i].id, tasks[i].name, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time), tasks[i].duration);
    }
}

void schedule_tasks(task_t *tasks, int num_tasks) {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time == current_time) {
            printf("Starting task %s at %s\n", tasks[i].name, ctime(&tasks[i].start_time));
        } else if (tasks[i].end_time == current_time) {
            printf("Completing task %s at %s\n", tasks[i].name, ctime(&tasks[i].end_time));
        }
    }
}

int main() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, 1, "Task 1", time(NULL) + 10, time(NULL) + 20);
    add_task(tasks, num_tasks, 2, "Task 2", time(NULL) + 30, time(NULL) + 40);

    display_tasks(tasks, num_tasks);

    while (1) {
        schedule_tasks(tasks, num_tasks);
        sleep(1);
    }

    return 0;
}