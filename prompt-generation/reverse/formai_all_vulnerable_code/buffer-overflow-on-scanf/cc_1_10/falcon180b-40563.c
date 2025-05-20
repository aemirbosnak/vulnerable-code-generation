//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int task_id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void print_schedule(Task tasks[], int num_tasks) {
    printf("Task ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", tasks[i].task_id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task ID for task %d: ", i+1);
        scanf("%d", &tasks[i].task_id);

        printf("Enter priority for task %d (1-100): ", i+1);
        scanf("%d", &tasks[i].priority);

        printf("Enter burst time for task %d: ", i+1);
        scanf("%d", &tasks[i].burst_time);
    }

    int quantum = 2; // time slice in milliseconds
    int time_quantum_count = 0;

    int current_time = 0;
    int completed_tasks = 0;
    int current_task = 0;

    while (completed_tasks < num_tasks) {
        if (tasks[current_task].burst_time > quantum) {
            tasks[current_task].burst_time -= quantum;
            current_time += quantum;
            time_quantum_count++;
        } else {
            tasks[current_task].burst_time = 0;
            completed_tasks++;
        }

        if (tasks[current_task].burst_time == 0) {
            current_task++;
            if (current_task == num_tasks) {
                current_task = 0;
            }
        }
    }

    print_schedule(tasks, num_tasks);

    return 0;
}