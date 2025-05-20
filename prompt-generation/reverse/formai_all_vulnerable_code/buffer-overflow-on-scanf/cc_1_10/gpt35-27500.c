//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int priority;
    int remaining_time;
};

void fcfs(struct process queue[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int time = queue[0].arrival_time;

    for (int i = 0; i < n; i++) {
        queue[i].remaining_time = queue[i].burst_time;
    }

    printf("\nFCFS Scheduling Algorithm\n");
    printf("--------------------------------------------------\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        queue[i].waiting_time = time - queue[i].arrival_time;

        if (queue[i].waiting_time < 0) {
            queue[i].waiting_time = 0;
        }

        queue[i].turnaround_time = queue[i].waiting_time + queue[i].burst_time;
        time += queue[i].burst_time;

        total_waiting_time += queue[i].waiting_time;
        total_turnaround_time += queue[i].turnaround_time;

        printf("%-10d | %-12d | %-10d | %-13d | %d\n", queue[i].pid, queue[i].arrival_time, queue[i].burst_time, queue[i].waiting_time, queue[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float) total_turnaround_time / n);
}

void sjf(struct process queue[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int time = 0;
    int min_index;

    for (int i = 0; i < n; i++) {
        queue[i].remaining_time = queue[i].burst_time;
    }

    printf("\nSJF Scheduling Algorithm\n");
    printf("--------------------------------------------------\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");

    while (1) {
        min_index = -1;

        for (int i = 0; i < n; i++) {
            if (queue[i].remaining_time > 0 && (min_index == -1 || queue[i].remaining_time < queue[min_index].remaining_time)) {
                min_index = i;
            }
        }

        if (min_index == -1) {
            break;
        }

        queue[min_index].waiting_time = time - queue[min_index].arrival_time;

        if (queue[min_index].waiting_time < 0) {
            queue[min_index].waiting_time = 0;
        }

        queue[min_index].turnaround_time = queue[min_index].waiting_time + queue[min_index].burst_time;

        time += queue[min_index].burst_time;
        queue[min_index].remaining_time = 0;

        total_waiting_time += queue[min_index].waiting_time;
        total_turnaround_time += queue[min_index].turnaround_time;

        printf("%-10d | %-12d | %-10d | %-13d | %d\n", queue[min_index].pid, queue[min_index].arrival_time, queue[min_index].burst_time, queue[min_index].waiting_time, queue[min_index].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float) total_turnaround_time / n);
}

int main() {
    int n;
    struct process queue[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        queue[i].pid = i+1;
        printf("Enter Arrival Time: ");
        scanf("%d", &queue[i].arrival_time);
        printf("Enter Burst Time: ");
        scanf("%d", &queue[i].burst_time);
        printf("Enter Priority: ");
        scanf("%d", &queue[i].priority);
    }

    fcfs(queue, n);
    sjf(queue, n);

    return 0;
}