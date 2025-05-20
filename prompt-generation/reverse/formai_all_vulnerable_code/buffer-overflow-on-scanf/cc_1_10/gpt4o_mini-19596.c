//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;        // Process ID
    int burstTime;  // Burst time
    int remainingTime; // Remaining time
    int waitingTime; // Waiting time
    int turnaroundTime; // Turnaround time
};

void calculateWaitingAndTurnaroundTime(struct Process processes[], int n, int timeQuantum) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int remainingProcesses = n;
    int time = 0;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > timeQuantum) {
                    time += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].waitingTime = time - processes[i].burstTime;
                    processes[i].turnaroundTime = time;
                    totalWaitingTime += processes[i].waitingTime;
                    totalTurnaroundTime += processes[i].turnaroundTime;
                    processes[i].remainingTime = 0;
                    remainingProcesses--;
                }
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

void displaySchedulingSequence(struct Process processes[], int n) {
    printf("\nProcess Scheduling Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (Burst Time: %d) -> ", processes[i].pid, processes[i].burstTime);
    }
    printf("Completed\n");
}

int main() {
    int n, timeQuantum;

    printf("Welcome to the CPU Scheduling Simulator!\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = malloc(n * sizeof(struct Process));
    if (processes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter the burst time for Process %d: ", processes[i].pid);
        scanf("%d", &(processes[i].burstTime));
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    displaySchedulingSequence(processes, n);
    calculateWaitingAndTurnaroundTime(processes, n, timeQuantum);

    free(processes);
    printf("\nThank you for using the CPU Scheduling Simulator!\n");
    return 0;
}