//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define PRIORITY_MIN 1
#define PRIORITY_MAX 10

struct task {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task *task) {
    printf("Task %d executed at time %d\n", task->id, time(NULL));
    task->waiting_time = 0;
    task->turnaround_time = task->waiting_time + task->burst_time;
}

void print_tasks(struct task *tasks, int n) {
    for (int i = 0; i < n; i++) {
        printf("Task %d: Priority %d, Burst Time %d, Waiting Time %d, Turnaround Time %d\n", tasks[i].id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

void schedule_tasks(struct task *tasks, int n) {
    for (int i = 0; i < n; i++) {
        printf("Task %d waiting for CPU at time %d\n", tasks[i].id, tasks[i].waiting_time);
        sleep(tasks[i].waiting_time);
        execute_task(&tasks[i]);
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int n = 0;

    printf("Enter task ID, priority, burst time (in milliseconds):\n");

    while (n < MAX_TASKS) {
        int id, priority, burst_time;
        scanf("%d %d %d", &id, &priority, &burst_time);
        tasks[n].id = id;
        tasks[n].priority = priority;
        tasks[n].burst_time = burst_time;
        n++;
    }

    printf("Tasks:\n");
    print_tasks(tasks, n);

    schedule_tasks(tasks, n);

    return 0;
}