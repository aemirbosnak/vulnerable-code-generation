//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task *task) {
    printf("Executing task: %s\n", task->name);
    printf("Priority: %d\n", task->priority);
    printf("Burst time: %d\n", task->burst_time);
    printf("Waiting time: %d\n", task->waiting_time);
    printf("Turnaround time: %d\n", task->turnaround_time);
}

int main() {
    int i, j, n, m;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    struct task tasks[MAX_TASKS];

    printf("Welcome to the Task Scheduler!\n");

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter task %d name: ", i+1);
        scanf("%s", tasks[i].name);

        printf("Enter task %d priority (1-10): ", i+1);
        scanf("%d", &tasks[i].priority);

        printf("Enter task %d burst time: ", i+1);
        scanf("%d", &tasks[i].burst_time);
    }

    printf("Enter the number of time slices: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (tasks[j].burst_time > i) {
                tasks[j].burst_time -= i;
                tasks[j].waiting_time += i;
                total_waiting_time += i;
                total_turnaround_time += i;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        tasks[i].turnaround_time = tasks[i].burst_time + tasks[i].waiting_time;
        total_turnaround_time += tasks[i].turnaround_time;
    }

    printf("Average waiting time: %d\n", total_waiting_time / m);
    printf("Average turnaround time: %d\n", total_turnaround_time / n);

    printf("Executing tasks...\n");

    for (i = 0; i < n; i++) {
        execute_task(&tasks[i]);
    }

    return 0;
}