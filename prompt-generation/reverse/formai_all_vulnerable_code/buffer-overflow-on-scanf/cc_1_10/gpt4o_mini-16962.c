//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;           // Process ID
    int burstTime;   // Burst Time
    int remainingTime; // Remaining Time
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum, int waitingTime[]) {
    int remainingTime[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remainingTime[i] = processes[i].burstTime;

    int time = 0;
    while (1) {
        int done = 1; // Check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0; // There is a pending process
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - processes[i].burstTime;
                    remainingTime[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void calculateTurnaroundTime(Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++)
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
}

void displayResults(Process processes[], int n, int waitingTime[]) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("=========================================================\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, waitingTime[i], waitingTime[i] + processes[i].burstTime);
    printf("=========================================================\n");
}

int main() {
    int n, quantum;

    printf("Enter the number of processes (1 to %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n < 1 || n > MAX_PROCESSES) {
        fprintf(stderr, "Invalid number of processes.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign process ID
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    int waitingTime[MAX_PROCESSES], turnaroundTime[MAX_PROCESSES];
    
    calculateWaitingTime(processes, n, quantum, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);
    displayResults(processes, n, waitingTime);

    return 0;
}