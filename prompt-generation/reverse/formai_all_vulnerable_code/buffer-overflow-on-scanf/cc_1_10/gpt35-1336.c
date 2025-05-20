//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    printf("\n[FCFS Algorithm]\n");

    for (int i = 0; i < n; i++) {
        printf("[Process %d] | Arrival Time: %d | Burst Time: %d\n",
            processes[i].pid, processes[i].arrival_time, processes[i].burst_time);

        current_time += processes[i].burst_time;

        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        total_turnaround_time += processes[i].turnaround_time;

        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

void sjf(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    printf("\n[SJF Algorithm]\n");

    for (int i = 0; i < n; i++) {
        int shortest_index = i;

        for (int j = i + 1; j < n; j++) {
            if (processes[j].burst_time < processes[shortest_index].burst_time) {
                shortest_index = j;
            }
        }

        struct Process temp = processes[i];
        processes[i] = processes[shortest_index];
        processes[shortest_index] = temp;

        printf("[Process %d] | Arrival Time: %d | Burst Time: %d\n",
            processes[i].pid, processes[i].arrival_time, processes[i].burst_time);

        current_time += processes[i].burst_time;

        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        total_turnaround_time += processes[i].turnaround_time;

        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n\n", (float)total_turnaround_time / n);
}

int main() {
    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (< %d): ", MAX_PROCESSES);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;

        printf("\nEnter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}