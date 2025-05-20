//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    time_t start_time;
    time_t end_time;
    int duration;
} Task;

void add_task(Task *tasks, int num_tasks, char *name, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }
    strncpy(tasks[num_tasks].name, name, MAX_TASK_NAME_LEN);
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    tasks[num_tasks].duration = end_time - start_time;
    num_tasks++;
}

void print_tasks(Task *tasks, int num_tasks) {
    printf("Task\tStart Time\tEnd Time\tDuration\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%s\t\t%s\t\t%d\n", tasks[i].name, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time), tasks[i].duration);
    }
}

void schedule_tasks(Task *tasks, int num_tasks) {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time == current_time) {
            printf("Starting task: %s\n", tasks[i].name);
        } else if (tasks[i].end_time == current_time) {
            printf("Completing task: %s\n", tasks[i].name);
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    add_task(tasks, num_tasks, "Task 1", time(NULL) + 10, time(NULL) + 60);
    add_task(tasks, num_tasks, "Task 2", time(NULL) + 20, time(NULL) + 80);
    add_task(tasks, num_tasks, "Task 3", time(NULL) + 30, time(NULL) + 100);
    print_tasks(tasks, num_tasks);
    schedule_tasks(tasks, num_tasks);
    return 0;
}