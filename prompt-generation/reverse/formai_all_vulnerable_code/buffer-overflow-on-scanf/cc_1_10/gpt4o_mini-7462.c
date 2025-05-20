//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining time
    int completed;  // Completion time
} Process;

void findWaitingTime(Process proc[], int n, int quantum, int waiting[]) {
    int remaining[n];
    for (int i = 0; i < n; i++)
        remaining[i] = proc[i].burst;

    int t = 0; // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && proc[i].arrival <= t) {
                done = 0; // There's still a process to execute
                if (remaining[i] > quantum) {
                    // Process the full quantum time
                    t += quantum;
                    remaining[i] -= quantum;
                } else {
                    // Process the remaining time
                    t += remaining[i];
                    waiting[i] = t - proc[i].burst - proc[i].arrival;
                    remaining[i] = 0; // Process completed
                    proc[i].completed = t; // Set completion time
                }
            }
        }
        if (done) // If no process left to execute
            break;
    }
}

void findTurnAroundTime(Process proc[], int n, int waiting[], int turnaround[]) {
    for (int i = 0; i < n; i++)
        turnaround[i] = proc[i].burst + waiting[i];
}

void calculateAverageTimes(Process proc[], int n, int quantum) {
    int waiting[n], turnaround[n];

    findWaitingTime(proc, n, quantum, waiting);
    findTurnAroundTime(proc, n, waiting, turnaround);

    float total_waiting = 0, total_turnaround = 0;
    printf("\nProcess ID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\n", 
            proc[i].id, proc[i].arrival, proc[i].burst, 
            waiting[i], turnaround[i]);
        
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);
}

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter arrival time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst);
        proc[i].remaining = proc[i].burst; // Initialize remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateAverageTimes(proc, n, quantum);

    return 0;
}