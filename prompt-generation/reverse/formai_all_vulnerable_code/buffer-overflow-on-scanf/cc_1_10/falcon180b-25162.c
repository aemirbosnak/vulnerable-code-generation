//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

// Define the structure of a task
typedef struct {
    int task_id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

// Function to compare tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    const Task *task_a = (const Task *)a;
    const Task *task_b = (const Task *)b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

// Function to execute the task scheduling algorithm
void schedule_tasks(Task tasks[], int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    int completed_tasks = 0;
    int current_time = 0;

    while (completed_tasks < num_tasks) {
        int i;
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].waiting_time == 0) {
                if (current_time >= tasks[i].task_id) {
                    tasks[i].burst_time--;
                    tasks[i].waiting_time = current_time - tasks[i].task_id - tasks[i].burst_time;
                    completed_tasks++;
                }
            }
        }
        current_time++;
    }
}

int main() {
    int num_tasks;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[MAX_TASKS];

    printf("Enter the details of the tasks:\n");
    printf("Task ID Priority Burst Time\n");

    int i;
    for (i = 0; i < num_tasks; i++) {
        scanf("%d %d %d", &tasks[i].task_id, &tasks[i].priority, &tasks[i].burst_time);
    }

    schedule_tasks(tasks, num_tasks);

    printf("\nTask ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < num_tasks; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", tasks[i].task_id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].burst_time + tasks[i].waiting_time);
    }

    return 0;
}