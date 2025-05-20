//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n, int quantum) {
    int i, j, current_time = 0;
    int completed_processes = 0;
    int current_process = 0;
    int cpu_bursts[MAX] = {0};

    for(i=0; i<n; i++) {
        cpu_bursts[i] = processes[i].burst_time;
    }

    for(i=0; i<n; i++) {
        for(j=0; j<cpu_bursts[i]; j++) {
            if(current_time >= processes[i].waiting_time) {
                current_time += quantum;
                processes[i].turnaround_time += quantum;
                completed_processes++;
            } else {
                current_time += quantum;
                processes[i].waiting_time -= quantum;
            }
        }
        current_time += processes[i].burst_time;
        processes[i].turnaround_time += processes[i].burst_time;
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i, j, sum = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("\nEnter the details of process %d:\n", i+1);
        printf("Enter process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n, TIME_QUANTUM);

    return 0;
}