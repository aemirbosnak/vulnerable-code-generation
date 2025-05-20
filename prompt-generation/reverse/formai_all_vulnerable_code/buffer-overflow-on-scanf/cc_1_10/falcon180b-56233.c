//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
struct task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to compare tasks based on priority
int compare(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->priority > task_b->priority)
        return 1;
    else if (task_a->priority == task_b->priority)
        return 0;
    else
        return -1;
}

// Function to execute a task
void execute_task(struct task *task) {
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    task->burst_time -= 1;
}

// Function to calculate waiting time for a task
void calculate_waiting_time(struct task *task, int quantum) {
    int i;
    for (i = 0; i < task->waiting_time; i++) {
        printf("Task %s is waiting...\n", task->name);
        sleep(1);
    }
    task->turnaround_time += task->waiting_time;
}

// Function to schedule tasks using round robin algorithm
void round_robin_scheduling(struct task *tasks, int n, int quantum) {
    int i, j, completed_tasks = 0;
    qsort(tasks, n, sizeof(struct task), compare);

    while (completed_tasks < n) {
        for (i = 0; i < n; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].waiting_time == 0) {
                execute_task(&tasks[i]);
                tasks[i].burst_time--;
                completed_tasks++;
            }
        }

        for (i = 0; i < n; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].waiting_time > 0) {
                calculate_waiting_time(&tasks[i], quantum);
            }
        }
    }
}

int main() {
    int n, i, quantum;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    struct task tasks[n];

    printf("Enter task details:\n");
    for (i = 0; i < n; i++) {
        printf("Task %d:\n", i+1);
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    round_robin_scheduling(tasks, n, quantum);

    return 0;
}