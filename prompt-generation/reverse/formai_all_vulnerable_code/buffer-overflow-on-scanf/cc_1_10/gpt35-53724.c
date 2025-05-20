//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int wait_time;
    int turnaround_time;
} Process;

void fcfs(Process processes[], int n) {
    int time = processes[0].arrival_time;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        processes[i].completion_time = time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
        time = processes[i].completion_time;
    }
}

void sjf(Process processes[], int n) {
    int time = processes[0].arrival_time;
    int min_idx, temp;
    for (int i = 0; i < n; i++) {
        min_idx = i;
        for (int j = i; j < n; j++) {
            if (processes[j].burst_time < processes[min_idx].burst_time) {
                min_idx = j;
            }
        }
        temp = processes[i].burst_time;
        processes[i].burst_time = processes[min_idx].burst_time;
        processes[min_idx].burst_time = temp;
        processes[i].completion_time = time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
        time = processes[i].completion_time;
    }
}

void print_table(Process processes[], int n) {
    printf("%-10s%-20s%-20s%-20s\n", "PID", "Completion Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-20d%-20d%-20d\n", processes[i].pid, processes[i].completion_time, processes[i].turnaround_time, processes[i].wait_time);
    }
}

int main() {
    int n, choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
    }
    printf("Choose a scheduling algorithm\n");
    printf("1. First Come First Serve\n");
    printf("2. Shortest Job First\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            fcfs(processes, n);
            print_table(processes, n);
            break;
        case 2:
            sjf(processes, n);
            print_table(processes, n);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}