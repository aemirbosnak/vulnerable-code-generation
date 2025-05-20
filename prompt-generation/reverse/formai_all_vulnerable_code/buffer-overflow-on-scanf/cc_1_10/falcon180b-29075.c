//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void display_tasks(struct task tasks[], int size) {
    printf("Task\tID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, tasks[i].id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time, tasks[i].completion_time);
    }
}

void execute_tasks(struct task tasks[], int size) {
    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < size) {
        int smallest_burst_time = tasks[0].burst_time;
        int smallest_index = 0;

        for (int i = 1; i < size; i++) {
            if (tasks[i].burst_time < smallest_burst_time) {
                smallest_burst_time = tasks[i].burst_time;
                smallest_index = i;
            }
        }

        if (current_time >= tasks[smallest_index].completion_time) {
            completed_tasks++;
        } else {
            current_time += tasks[smallest_index].burst_time;
            tasks[smallest_index].completion_time = current_time;
        }
    }
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    struct task tasks[num_tasks];

    printf("Enter the details of the tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst Time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    execute_tasks(tasks, num_tasks);

    display_tasks(tasks, num_tasks);

    return 0;
}