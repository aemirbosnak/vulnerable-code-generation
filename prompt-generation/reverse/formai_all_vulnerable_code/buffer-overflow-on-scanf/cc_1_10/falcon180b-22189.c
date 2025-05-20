//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task* task) {
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    int time_quantum = 2; // Time quantum of 2 units
    int completed_time_quantums = 0;
    while (completed_time_quantums < task->burst_time) {
        printf("Task %s completed %d time quantums\n", task->name, completed_time_quantums + 1);
        completed_time_quantums++;
        sleep(time_quantum);
    }
    task->turnaround_time = completed_time_quantums * time_quantum;
    task->waiting_time = task->turnaround_time - task->burst_time;
}

int compare_tasks(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;
    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the details of task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    printf("\nTask\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t", tasks[i].name, tasks[i].priority, tasks[i].burst_time);
        execute_task(&tasks[i]);
        printf("%d\t%d\n", tasks[i].waiting_time, tasks[i].turnaround_time);
    }

    return 0;
}