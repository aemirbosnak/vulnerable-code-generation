//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int completed = 0, t = 0;
    while (completed < n) {
        bool do_more = false;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= t) {
                do_more = true;
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = t - processes[i].arrival_time;
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }
        if (!do_more) {
            t++;
        }
    }
}

void calculate_turnaround_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void print_chart(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst_time, processes[i].arrival_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void schedule_processes() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter quantum time: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // assigning process ID starting from 1
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }

    calculate_waiting_time(processes, n, quantum);
    calculate_turnaround_time(processes, n);
    print_chart(processes, n);
}

int main() {
    printf("=== Round Robin CPU Scheduling Algorithm ===\n");
    schedule_processes();
    return 0;
}