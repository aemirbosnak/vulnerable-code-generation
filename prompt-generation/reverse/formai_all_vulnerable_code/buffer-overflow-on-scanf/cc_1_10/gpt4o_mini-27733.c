//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;             // Process ID
    int burstTime;     // Burst Time
    int arrivalTime;   // Arrival Time
    int waitingTime;   // Waiting Time
    int turnaroundTime; // Turnaround Time
};

void calculateWaitingTime(struct Process processes[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }
    
    int t = 0; // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0; // Process is not finished
                
                if (remainingTime[i] > quantum) {
                    t += quantum; // Increase time by quantum
                    remainingTime[i] -= quantum; // Reduce remaining time
                } else { // Process can complete in this cycle
                    t = t + remainingTime[i]; // Increase time by remaining time
                    processes[i].waitingTime = t - processes[i].burstTime - processes[i].arrivalTime; //  Calculate waiting time
                    remainingTime[i] = 0; // Process finished
                }
            }
        }
        if (done) break; // All processes finished
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void displayProcessInfo(struct Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burstTime, 
                processes[i].arrivalTime, 
                processes[i].waitingTime, 
                processes[i].turnaroundTime);
    }
}

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process *processes = (struct Process*) malloc(n * sizeof(struct Process));
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assigning Process ID
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burstTime, &processes[i].arrivalTime);
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    displayProcessInfo(processes, n);
    
    free(processes); // Clean up dynamically allocated memory
    return 0;
}