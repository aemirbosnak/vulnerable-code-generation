//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;             // Process ID
    int burstTime;     // Burst Time
    int remainingTime; // Remaining Time
} Process;

void roundRobinScheduling(Process processes[], int n, int quantum) {
    int time = 0;
    int complete = 0;
    int waitTime[MAX_PROCESSES] = {0};
    int turnAroundTime[MAX_PROCESSES] = {0};
    
    printf("Time\tProcess ID\n");
    printf("---------------------\n");
    
    while (complete < n) {
        int done = 0;
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    waitTime[i] = time - processes[i].burstTime; // Calculate waiting time
                    turnAroundTime[i] = waitTime[i] + processes[i].burstTime; // Calculate turnaround time
                    printf("%d\t%d\n", time, processes[i].id);
                    processes[i].remainingTime = 0; // Process is complete
                    complete++;
                }
                done = 1;
            }
        }
        
        // Check if all processes are done
        if (done == 0) break; 
    }
    
    printf("\nProcess ID\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, waitTime[i], turnAroundTime[i]);
    }
}

int main() {
    int n, quantum;
    Process processes[MAX_PROCESSES];
    
    // Get the number of processes and their details
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
    }

    // Get the time quantum for Round Robin
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    // Perform Round Robin scheduling
    roundRobinScheduling(processes, n, quantum);
    
    return 0;
}