//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;        // Process ID
    int burst;      // Burst time
    int arrival;    // Arrival time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
} Process;

void calculateWaitingTime(Process proc[], int n, int quantum) {
    int rem_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        rem_burst[i] = proc[i].burst;

    int t = 0; // Current time
    bool done;
    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_burst[i] > 0) {
                done = false; // There is a pending process
                if (rem_burst[i] > quantum) {
                    t += quantum;
                    rem_burst[i] -= quantum;
                } else {
                    t = t + rem_burst[i];
                    proc[i].waiting = t - proc[i].burst - proc[i].arrival;
                    rem_burst[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].turnaround = proc[i].waiting + proc[i].burst;
}

void findavgTime(Process proc[], int n, int quantum) {
    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);

    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].burst, proc[i].arrival,
               proc[i].waiting, proc[i].turnaround);
}

int main() {
    int n;
    int quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process proc[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &proc[i].arrival);
        proc[i].pid = i + 1; // Assigning process ID
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findavgTime(proc, n, quantum);

    return 0;
}