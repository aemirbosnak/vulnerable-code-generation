//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_NAME_LEN 20

typedef struct {
    int task_id;
    int priority;
    char name[MAX_NAME_LEN];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

int compare_priority(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;
    return task_a->priority - task_b->priority;
}

int compare_burst_time(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;
    return task_a->burst_time - task_b->burst_time;
}

void print_tasks(Task *tasks, int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("%d: %s (Priority: %d, Burst Time: %d)\n", tasks[i].task_id, tasks[i].name, tasks[i].priority, tasks[i].burst_time);
    }
}

void schedule_tasks(Task *tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_priority);
    int completed_tasks = 0;
    int current_time = 0;
    Task *current_task = &tasks[0];

    while (completed_tasks < num_tasks) {
        if (current_task->burst_time > current_time) {
            current_time += current_task->burst_time;
            completed_tasks++;
        } else {
            current_time += current_task->burst_time;
        }
        current_task++;
    }

    printf("Total waiting time: %d\n", current_time);
    printf("Average turnaround time: %.2f\n", (float)current_time / num_tasks);
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[MAX_TASKS];
    printf("Enter task details:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task ID: ");
        scanf("%d", &tasks[i].task_id);
        printf("Task Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst Time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}