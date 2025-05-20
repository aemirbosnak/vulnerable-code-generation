//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void calculateWaitingTime(struct Process processes[], int n, int quantum, int waiting_time[]) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int t = 0;  // Time counter
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false;  // There is a pending process
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {  
                    t += remaining_time[i];
                    waiting_time[i] = t - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) break;  // Exit when no tasks remain
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void findavgTime(struct Process processes[], int n, int quantum) {
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    calculateWaitingTime(processes, n, quantum, waiting_time);
    calculateTurnaroundTime(processes, n, waiting_time, turnaround_time);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, 
            waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Welcome to the CPU Scheduling Simulator!\n");
    printf("How many processes do you want to simulate? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;  // Initialize remaining time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("\n=== ROUND ROBIN SCHEDULING ===\n");
    findavgTime(processes, n, quantum);

    return 0;
}