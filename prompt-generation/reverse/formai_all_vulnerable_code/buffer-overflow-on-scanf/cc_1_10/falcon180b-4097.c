//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_WAIT_TIME 1000

struct task {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void print_tasks(struct task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: Priority %d, Burst Time %d, Waiting Time %d, Turnaround Time %d, Completion Time %d\n", tasks[i].id, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time, tasks[i].completion_time);
    }
}

void execute_tasks(struct task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("Executing task %d\n", tasks[i].id);
        sleep(tasks[i].burst_time / 100);
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: ", i + 1);
        scanf("%d%d", &tasks[i].id, &tasks[i].burst_time);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
    }

    printf("Enter time quantum: ");
    int time_quantum = scanf("%d", &time_quantum);

    int current_time = 0;
    int completed_tasks = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed_tasks < num_tasks) {
        int shortest_remaining_time = MAX_WAIT_TIME;
        int shortest_task_index = -1;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].burst_time > 0 && tasks[i].waiting_time > 0) {
                if (tasks[i].burst_time - tasks[i].waiting_time <= shortest_remaining_time) {
                    shortest_remaining_time = tasks[i].burst_time - tasks[i].waiting_time;
                    shortest_task_index = i;
                }
            }
        }

        if (shortest_task_index!= -1) {
            tasks[shortest_task_index].waiting_time += time_quantum;
            if (tasks[shortest_task_index].burst_time <= time_quantum) {
                tasks[shortest_task_index].burst_time = 0;
                tasks[shortest_task_index].completion_time = current_time + time_quantum;
                completed_tasks++;
            } else {
                tasks[shortest_task_index].burst_time -= time_quantum;
            }
        } else {
            current_time += time_quantum;
            total_waiting_time += time_quantum;
        }
    }

    printf("Completed tasks:\n");
    print_tasks(tasks, num_tasks);

    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turnaround time: %d\n", total_turnaround_time);

    return 0;
}