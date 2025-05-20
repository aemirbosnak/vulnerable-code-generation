//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

int compare_priority(const void* a, const void* b) {
    const Task* task_a = (const Task*)a;
    const Task* task_b = (const Task*)b;

    if(task_a->priority > task_b->priority)
        return 1;
    else if(task_a->priority < task_b->priority)
        return -1;
    else
        return 0;
}

void print_tasks(Task tasks[], int num_tasks) {
    printf("Task\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[num_tasks];

    for(int i=0; i<num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);

        printf("Enter task priority (1-10): ");
        scanf("%d", &tasks[i].priority);

        printf("Enter task burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    int quantum = 2;
    int current_time = 0;
    int completed_tasks = 0;

    while(completed_tasks < num_tasks) {
        int i;
        for(i=0; i<num_tasks; i++) {
            if(tasks[i].burst_time > quantum && tasks[i].burst_time - quantum > current_time) {
                tasks[i].burst_time -= quantum;
                current_time += quantum;
            }
            else {
                tasks[i].burst_time = 0;
                current_time += tasks[i].burst_time;
            }
        }

        completed_tasks++;
    }

    print_tasks(tasks, num_tasks);

    return 0;
}