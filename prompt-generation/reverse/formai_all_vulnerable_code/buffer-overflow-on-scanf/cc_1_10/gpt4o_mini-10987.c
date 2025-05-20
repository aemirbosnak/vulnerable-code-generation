//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;        // Process ID
    int burst_time; // Burst Time
    int arrival_time; // Arrival Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
} Process;

void calculateAverageTimes(Process procs[], int n, float *avg_waiting_time, float *avg_turnaround_time) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += procs[i].waiting_time;
        total_turnaround_time += procs[i].turnaround_time;
    }

    *avg_waiting_time = (float)total_waiting_time / n;
    *avg_turnaround_time = (float)total_turnaround_time / n;
}

void sjfScheduling(Process procs[], int n) {
    int completed = 0, time = 0, min_index, min_burst;
    int completed_processes[MAX_PROCESSES] = {0};

    while (completed < n) {
        min_burst = 1000; // Set to a large number to find the minimum
        min_index = -1;

        // Find the process with the minimum burst time which has arrived
        for (int i = 0; i < n; i++) {
            if (procs[i].arrival_time <= time && 
                !completed_processes[i] && 
                procs[i].burst_time < min_burst) {
                min_burst = procs[i].burst_time;
                min_index = i;
            }
        }

        // If no process is found, increment time
        if (min_index == -1) {
            time++;
            continue;
        }

        // Simulate the process
        completed_processes[min_index] = 1;
        time += procs[min_index].burst_time;

        // Calculate waiting time and turnaround time
        procs[min_index].turnaround_time = time - procs[min_index].arrival_time;
        procs[min_index].waiting_time = procs[min_index].turnaround_time - procs[min_index].burst_time;

        completed++;
    }
}

void printStatistics(Process procs[], int n) {
    float avg_waiting_time, avg_turnaround_time;
    calculateAverageTimes(procs, n, &avg_waiting_time, &avg_turnaround_time);

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                procs[i].pid, 
                procs[i].burst_time, 
                procs[i].arrival_time, 
                procs[i].waiting_time, 
                procs[i].turnaround_time);
    }

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main() {
    Process procs[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        procs[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", procs[i].pid);
        scanf("%d", &procs[i].burst_time);
        printf("Enter arrival time for Process %d: ", procs[i].pid);
        scanf("%d", &procs[i].arrival_time);
        procs[i].waiting_time = 0;
        procs[i].turnaround_time = 0;
    }

    sjfScheduling(procs, n);
    printStatistics(procs, n);

    return 0;
}