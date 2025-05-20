//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
    }
}

void calculate_turnaround_time(Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void find_average_time(Process processes[], int n) {
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    float total_waiting_time = 0, total_turnaround_time = 0;

    calculate_waiting_time(processes, n, waiting_time);
    calculate_turnaround_time(processes, n, waiting_time, turnaround_time);

    printf("\nProcess ID | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = waiting_time[i];
        processes[i].turnaround_time = turnaround_time[i];
        printf("    %d      |     %d     |      %d      |      %d      |       %d\n",
               processes[i].id, processes[i].burst_time, processes[i].arrival_time,
               waiting_time[i], turnaround_time[i]);

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("--------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void sort_processes_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void shortest_job_first(Process processes[], int n) {
    sort_processes_by_arrival_time(processes, n);
    printf("\nScheduling using Shortest Job First (SJF) Algorithm:\n");
    find_average_time(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    shortest_job_first(processes, n);

    return 0;
}