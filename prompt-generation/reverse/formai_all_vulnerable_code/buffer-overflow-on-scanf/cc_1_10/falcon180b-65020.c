//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    int id;
    char name[20];
    int priority;
    int period;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void init_task(Task *t) {
    t->id = 0;
    t->priority = 0;
    t->period = 0;
    t->burst_time = 0;
    t->waiting_time = 0;
    t->turnaround_time = 0;
}

int compare_priority(const void *a, const void *b) {
    const Task *task_a = a;
    const Task *task_b = b;
    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

void print_task(const Task *t) {
    printf("ID: %d, Name: %s, Priority: %d, Period: %d, Burst time: %d\n", t->id, t->name, t->priority, t->period, t->burst_time);
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[MAX_TASKS];
    init_task(tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    printf("\nTask list:\n");
    for (int i = 0; i < num_tasks; i++) {
        print_task(&tasks[i]);
    }

    return 0;
}