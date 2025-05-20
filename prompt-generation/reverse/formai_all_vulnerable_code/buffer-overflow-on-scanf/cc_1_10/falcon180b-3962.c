//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void add_task(Task *tasks, int *num_tasks) {
    printf("Enter task ID (0 to %d): ", *num_tasks);
    scanf("%d", &tasks[*num_tasks].id);

    printf("Enter task priority (0 to %d): ", *num_tasks);
    scanf("%d", &tasks[*num_tasks].priority);

    printf("Enter task burst time (in milliseconds): ");
    scanf("%d", &tasks[*num_tasks].burst_time);

    (*num_tasks)++;
}

void print_tasks(Task *tasks, int num_tasks) {
    printf("Task ID\tPriority\tBurst Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t\t%d\t\t%d\n", tasks[i].id, tasks[i].priority, tasks[i].burst_time);
    }
}

void execute_tasks(Task *tasks, int num_tasks) {
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        int min_burst_time = 999999;
        int min_index = -1;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].burst_time <= min_burst_time) {
                min_burst_time = tasks[i].burst_time;
                min_index = i;
            }
        }

        if (min_index!= -1) {
            tasks[min_index].burst_time -= 1;

            if (tasks[min_index].burst_time == 0) {
                printf("Task %d completed.\n", tasks[min_index].id);
                completed_tasks++;
            }
        } else {
            printf("No task found to execute.\n");
        }
    }
}

void main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        add_task(tasks, &num_tasks);
    }

    print_tasks(tasks, num_tasks);

    execute_tasks(tasks, num_tasks);
}