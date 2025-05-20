//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void swap(struct process *xp, struct process *yp) {
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(struct process proc[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (proc[j].priority < proc[min_idx].priority) {
                min_idx = j;
            }
        }
        swap(&proc[min_idx], &proc[i]);
    }
}

void calculate_waiting_time(struct process proc[], int n) {
    int i, total_waiting_time = 0;
    proc[0].waiting_time = 0; // first process has zero waiting time
    for (i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        total_waiting_time += proc[i].waiting_time;
    }
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
}

void calculate_turnaround_time(struct process proc[], int n) {
    int i, total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
}

int main() {
    int i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process proc[n];
    for (i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &proc[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Priority: ");
        scanf("%d", &proc[i].priority);
    }
    sort_by_priority(proc, n);
    calculate_waiting_time(proc, n);
    calculate_turnaround_time(proc, n);
    return 0;
}