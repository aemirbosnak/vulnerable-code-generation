//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process *processes, int n) {
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > 0) {
            processes[i].burst_time--;
            sum_waiting_time += processes[i].burst_time;
        } else {
            completed_processes++;
        }
    }

    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        sum_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average waiting time: %.2f\n", (float) sum_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float) sum_turnaround_time / n);
    printf("Number of completed processes: %d\n", completed_processes);
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, n);

    return 0;
}