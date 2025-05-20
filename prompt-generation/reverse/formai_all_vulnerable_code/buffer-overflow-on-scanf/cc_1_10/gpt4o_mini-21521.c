//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].completion_time - processes[i].burst_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }
    }
}

void calculate_turnaround_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void round_robin(Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int time = 0;
    int i = 0;

    while (remaining_processes > 0) {
        if (processes[i].remaining_time > 0) {
            if (processes[i].remaining_time > time_quantum) {
                time += time_quantum;
                processes[i].remaining_time -= time_quantum;
            } else {
                time += processes[i].remaining_time;
                processes[i].completion_time = time;
                processes[i].remaining_time = 0;
                remaining_processes--;
            }
        }
        i = (i + 1) % n;
    }

    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
}

void sjf(Process processes[], int n) {
    int completed = 0;
    int time = 0;

    while (completed < n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (idx == -1 || processes[i].remaining_time < processes[idx].remaining_time) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += processes[idx].burst_time;
            processes[idx].completion_time = time;
            processes[idx].remaining_time = 0;
            completed++;
        } else {
            time++;
        }
    }

    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
}

void display_processes(Process processes[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
               processes[i].burst_time, processes[i].arrival_time,
               processes[i].completion_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;

        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Choose the scheduling algorithm:\n1. Round Robin\n2. Shortest Job First\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &time_quantum);
            round_robin(processes, n, time_quantum);
            break;

        case 2:
            sjf(processes, n);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    display_processes(processes, n);
    return 0;
}