//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitTurnaroundTime(struct Process processes[], int n, int time_quantum) {
    int total_time = 0;
    int completed_processes = 0;
    
    // Loop until all processes are completed
    while (completed_processes < n) {
        int executed_in_this_round = 0;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                executed_in_this_round = 1;
                // If the remaining time is greater than the time quantum
                if (processes[i].remaining_time > time_quantum) {
                    total_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    total_time += processes[i].remaining_time;
                    processes[i].waiting_time = total_time - processes[i].burst_time;
                    processes[i].turnaround_time = total_time;
                    processes[i].remaining_time = 0;
                    completed_processes++;
                }
            }
        }

        // If no process executed, break the loop
        if (executed_in_this_round == 0)
            break;
    }
}

void printProcessDetails(struct Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    calculateWaitTurnaroundTime(processes, n, time_quantum);
    printProcessDetails(processes, n);

    return 0;
}