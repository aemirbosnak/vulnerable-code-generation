//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process p[], int n, int quantum) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = p[i].burst_time;
    }
    int time = 0;
    bool done;
    
    while (true) {
        done = true;
        
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = false; // There is a pending process

                if (remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    time += remaining_burst_time[i];
                    p[i].waiting_time = time - p[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }
        
        if (done)
            break;
    }
}

void calculateTurnaroundTime(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void findavgTime(Process p[], int n, int quantum) {
    calculateWaitingTime(p, n, quantum);
    calculateTurnaroundTime(p, n);
}

void printProcesses(Process p[], int n) {
    printf("Processes  |  Burst Time  |  Waiting Time  |  Turnaround Time\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("   %d      |      %d      |       %d       |        %d\n", 
               p[i].id, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("-------------------------------------------------------------\n");
}

int main() {
    Process processes[MAX_PROCESSES];

    int n;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum allowed processes.\n");
        return 1;
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign Process IDs starting from 1
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0; // Initialize waiting time
        processes[i].turnaround_time = 0; // Initialize turnaround time
    }

    findavgTime(processes, n, quantum);
    printProcesses(processes, n);

    return 0;
}