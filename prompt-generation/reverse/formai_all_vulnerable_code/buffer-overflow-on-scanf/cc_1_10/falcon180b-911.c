//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char name[20];
    int priority;
    int period;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void init_task(Task *task, int id, char *name, int priority, int period, int burst_time) {
    task->id = id;
    strcpy(task->name, name);
    task->priority = priority;
    task->period = period;
    task->burst_time = burst_time;
    task->waiting_time = task->turnaround_time = 0;
}

void print_task(Task task) {
    printf("Task ID: %d, Name: %s, Priority: %d, Period: %d, Burst time: %d\n", task.id, task.name, task.priority, task.period, task.burst_time);
}

int compare_priority(const void *a, const void *b) {
    Task ta = *(Task *)a;
    Task tb = *(Task *)b;
    return ta.priority - tb.priority;
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks, i;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (i = 0; i < num_tasks; i++) {
        char name[20];
        int id, priority, period, burst_time;

        printf("Enter task %d details:\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf("%s", name);
        printf("Priority: ");
        scanf("%d", &priority);
        printf("Period: ");
        scanf("%d", &period);
        printf("Burst time: ");
        scanf("%d", &burst_time);

        init_task(&tasks[i], id, name, priority, period, burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    printf("\nTask List:\n");
    for (i = 0; i < num_tasks; i++) {
        print_task(tasks[i]);
    }

    return 0;
}