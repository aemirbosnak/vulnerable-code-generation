//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

typedef struct task {
    char name[50];
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} task_t;

void init_task(task_t *task) {
    strcpy(task->name, "");
    task->priority = 0;
    task->arrival_time = 0;
    task->burst_time = 0;
    task->waiting_time = 0;
    task->turnaround_time = 0;
}

void print_task(task_t *task) {
    printf("Task name: %s\n", task->name);
    printf("Priority: %d\n", task->priority);
    printf("Arrival time: %d\n", task->arrival_time);
    printf("Burst time: %d\n", task->burst_time);
    printf("Waiting time: %d\n", task->waiting_time);
    printf("Turnaround time: %d\n", task->turnaround_time);
}

int compare_tasks(const void *a, const void *b) {
    task_t *task_a = (task_t *)a;
    task_t *task_b = (task_t *)b;

    if (task_a->arrival_time < task_b->arrival_time) {
        return -1;
    } else if (task_a->arrival_time > task_b->arrival_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    task_t tasks[MAX_TASKS];

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Arrival time: ");
        scanf("%d", &tasks[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(task_t), compare_tasks);

    printf("Task list:\n");
    for (int i = 0; i < num_tasks; i++) {
        print_task(&tasks[i]);
    }

    return 0;
}