//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_fcfs(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    processes[0].waiting_time = 0; // First process has no waiting time
    
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("FCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void calculate_sjf(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int completed = 0, t = 0, min_index;

    while (completed < n) {
        min_index = -1;
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival_time <= t && (min_index == -1 ||
               processes[j].burst_time < processes[min_index].burst_time) && processes[j].burst_time > 0) {
                min_index = j;
            }
        }

        if (min_index != -1) {
            processes[min_index].waiting_time = t - processes[min_index].arrival_time;
            t += processes[min_index].burst_time;
            processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
            total_waiting_time += processes[min_index].waiting_time;
            total_turnaround_time += processes[min_index].turnaround_time;
            processes[min_index].burst_time = 0; // Mark as completed
            completed++;
        } else {
            t++; // No process is ready, increment time
        }
    }

    printf("\nSJF Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void calculate_rr(Process processes[], int n, int quantum) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int t = 0, completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= t) {
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    total_waiting_time += processes[i].waiting_time;
                    processes[i].turnaround_time = t - processes[i].arrival_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_time[i] = 0; // Mark as completed
                    completed++;
                }
            }
        }
    }

    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process* processes = malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    calculate_fcfs(processes, n);
    calculate_sjf(processes, n);
    int quantum;
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    calculate_rr(processes, n, quantum);

    free(processes);
    return 0;
}