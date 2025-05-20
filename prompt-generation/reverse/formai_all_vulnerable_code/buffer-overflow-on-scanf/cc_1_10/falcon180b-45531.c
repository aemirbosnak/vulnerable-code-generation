//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void executeTask(Task *task, int quantum) {
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    int time_slice = (task->burst_time > quantum)? quantum : task->burst_time;
    task->burst_time -= time_slice;
    task->waiting_time += time_slice;
}

int main() {
    int num_tasks, i;
    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[MAX_TASKS];
    for (i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    int quantum = 2; // time quantum in seconds
    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        int shortest_remaining_time = MAX_PRIORITY;
        int shortest_task_index = -1;

        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].waiting_time == 0) {
                if (tasks[i].burst_time < shortest_remaining_time) {
                    shortest_remaining_time = tasks[i].burst_time;
                    shortest_task_index = i;
                }
            }
        }

        if (shortest_task_index!= -1) {
            executeTask(&tasks[shortest_task_index], quantum);
            tasks[shortest_task_index].burst_time = 0;
            completed_tasks++;
        } else {
            current_time += quantum;
        }
    }

    printf("All tasks completed!\n");
    return 0;
}