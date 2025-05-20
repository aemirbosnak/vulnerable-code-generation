//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct task {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_task(struct task *task) {
    printf("Executing task %d\n", task->id);
    task->burst_time--;
}

void add_waiting_time(struct task *task) {
    task->waiting_time += task->burst_time;
}

int main() {
    struct task tasks[MAX];
    int n, i, j, sum = 0;
    int quantum = 2;
    int current_time = 0;
    int previous_time = -1;
    int cpu_burst[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    printf("Enter task details:\n");
    for (i = 0; i < n; i++) {
        printf("For task %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &tasks[i].burst_time);
        printf("Enter arrival time: ");
        scanf("%d", &tasks[i].id);
    }

    printf("Gantt chart:\n");
    for (i = 0; i < n; i++) {
        while (current_time <= tasks[i].id) {
            current_time++;
            if (previous_time!= -1) {
                printf("%d ", previous_time);
            }
        }
        previous_time = current_time;
        printf("%d ", current_time);
        current_time += tasks[i].burst_time;
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        tasks[i].waiting_time = tasks[i].id - tasks[i].burst_time;
        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (tasks[i].turnaround_time > tasks[j].turnaround_time) {
                tasks[i].turnaround_time = tasks[j].turnaround_time;
            }
        }
        sum += tasks[i].turnaround_time;
    }

    printf("Average turnaround time: %.2f\n", (float)sum/n);

    return 0;
}