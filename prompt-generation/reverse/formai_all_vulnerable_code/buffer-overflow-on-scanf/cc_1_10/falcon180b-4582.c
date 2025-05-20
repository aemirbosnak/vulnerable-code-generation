//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int priority;
    int waiting_time;
    int burst_time;
    int remaining_time;
} Task;

void init_task(Task* task, int id, int priority, int burst_time) {
    task->id = id;
    task->priority = priority;
    task->burst_time = burst_time;
    task->remaining_time = burst_time;
}

int compare_priority(const void* a, const void* b) {
    const Task* task_a = (const Task*)a;
    const Task* task_b = (const Task*)b;
    return task_a->priority - task_b->priority;
}

void process_task(Task* task) {
    printf("Processing task %d\n", task->id);
    task->remaining_time--;
    if (task->remaining_time == 0) {
        printf("Task %d completed\n", task->id);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    printf("Enter task details:\n");
    for (int i = 0; i < num_tasks; i++) {
        int id, priority, burst_time;
        printf("Task %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Priority: ");
        scanf("%d", &priority);
        printf("Burst time: ");
        scanf("%d", &burst_time);

        init_task(&tasks[i], id, priority, burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].remaining_time > 0) {
                if (current_time >= tasks[i].waiting_time) {
                    process_task(&tasks[i]);
                } else {
                    current_time++;
                }
            }
        }
    }

    printf("All tasks completed in %d units of time\n", current_time);

    return 0;
}