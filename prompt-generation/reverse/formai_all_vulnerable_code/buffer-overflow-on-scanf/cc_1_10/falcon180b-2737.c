//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char name[20];
    int priority;
    int period;
    int deadline;
    int burst;
    int waiting_time;
    int turnaround_time;
} task_t;

void print_task(task_t task) {
    printf("Name: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Period: %d\n", task.period);
    printf("Deadline: %d\n", task.deadline);
    printf("Burst: %d\n", task.burst);
    printf("Waiting time: %d\n", task.waiting_time);
    printf("Turnaround time: %d\n", task.turnaround_time);
}

int compare_deadline(const void *a, const void *b) {
    task_t *task1 = (task_t *)a;
    task_t *task2 = (task_t *)b;

    if (task1->deadline < task2->deadline) {
        return -1;
    } else if (task1->deadline > task2->deadline) {
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
        printf("Enter task %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Burst: ");
        scanf("%d", &tasks[i].burst);
    }

    qsort(tasks, num_tasks, sizeof(task_t), compare_deadline);

    printf("Task\tPriority\tPeriod\tDeadline\tBurst\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < num_tasks; i++) {
        print_task(tasks[i]);
    }

    return 0;
}