//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int t = 0;
    while (1) {
        int done = 1; // Check if all processes are completed
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // Process is not completed yet

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
        if (done == 1) break; // All processes are completed
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void printAverageTimes(Process processes[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printAverageTimes(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobinScheduling(processes, n, quantum);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].process_id, 
            processes[i].burst_time, 
            processes[i].waiting_time, 
            processes[i].turnaround_time);
    }

    return 0;
}