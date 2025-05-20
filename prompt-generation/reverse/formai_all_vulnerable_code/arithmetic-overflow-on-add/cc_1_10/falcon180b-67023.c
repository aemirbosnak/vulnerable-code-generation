//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char *name;
    time_t start_time;
    int duration;
    int priority;
} Task;

void add_task(Task *task_list, int num_tasks, int id, char *name, time_t start_time, int duration, int priority) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }

    task_list[num_tasks].id = id;
    task_list[num_tasks].name = name;
    task_list[num_tasks].start_time = start_time;
    task_list[num_tasks].duration = duration;
    task_list[num_tasks].priority = priority;

    num_tasks++;
}

void print_task_list(Task *task_list, int num_tasks) {
    printf("Task List:\n");
    printf("ID\tName\tStart Time\tDuration\tPriority\n");

    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%ld\t%d\t%d\n", task_list[i].id, task_list[i].name, task_list[i].start_time, task_list[i].duration, task_list[i].priority);
    }
}

int main() {
    Task task_list[MAX_TASKS];
    int num_tasks = 0;

    add_task(task_list, num_tasks, 1, "Task 1", time(NULL) + 10, 20, 1);
    add_task(task_list, num_tasks, 2, "Task 2", time(NULL) + 15, 30, 2);
    add_task(task_list, num_tasks, 3, "Task 3", time(NULL) + 20, 10, 3);

    print_task_list(task_list, num_tasks);

    return 0;
}