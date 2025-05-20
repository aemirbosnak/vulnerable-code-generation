//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    int task_id;
    char task_name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} task_t;

void print_tasks(task_t tasks[], int num_tasks) {
    printf("Task ID\tTask Name\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", tasks[i].task_id, tasks[i].task_name, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

void schedule_tasks(task_t tasks[], int num_tasks) {
    int completed_tasks = 0;
    int current_time = 0;
    int highest_priority = -1;
    task_t current_task;

    while (completed_tasks < num_tasks) {
        highest_priority = -1;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].task_id == -1) {
                continue;
            }
            if (tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                current_task = tasks[i];
            }
        }
        if (highest_priority == -1) {
            break;
        }
        current_task.task_id = -1;
        current_time += current_task.burst_time;
        completed_tasks++;
    }
}

int main() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter task name, priority, and burst time:\n");
    while (num_tasks < MAX_TASKS) {
        scanf("%s %d %d", tasks[num_tasks].task_name, &tasks[num_tasks].priority, &tasks[num_tasks].burst_time);
        tasks[num_tasks].task_id = num_tasks + 1;
        num_tasks++;
    }

    schedule_tasks(tasks, num_tasks);

    printf("Task Scheduling Results:\n");
    print_tasks(tasks, num_tasks);

    return 0;
}