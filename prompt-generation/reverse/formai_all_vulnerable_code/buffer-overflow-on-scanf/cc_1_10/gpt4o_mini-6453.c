//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void print_gantt_chart(Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
    }
    printf("|\n");
}

void find_fcfs(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    processes[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nFCFS Scheduling:\n");
    print_gantt_chart(processes, n);
    printf("Avg Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void find_sjn(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    processes[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nSJN Scheduling:\n");
    print_gantt_chart(processes, n);
    printf("Avg Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void find_rr(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int total_waiting_time = 0, total_turnaround_time = 0, t = 0;

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is a pending process
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    print_gantt_chart(processes, n);
    printf("Avg Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Avg Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and burst time for Process P%d: ", processes[i].id);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    find_fcfs(processes, n);
    find_sjn(processes, n);

    printf("Enter quantum time for Round Robin: ");
    scanf("%d", &quantum);
    find_rr(processes, n, quantum);

    return 0;
}