//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burstTime;
    int arrivalTime;
    int remainingTime;
} Process;

void printProcesses(Process processes[], int count) {
    printf("ID\tArrival\tBurst\tRemaining\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].remainingTime);
    }
}

void FCFS(Process processes[], int count) {
    printf("\n--- FCFS Scheduling ---\n");
    int waitTime = 0, totalWaitTime = 0;
    
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            waitTime += processes[i-1].burstTime;
        }
        totalWaitTime += waitTime;
        
        printf("Process %d finished after %d time units.\n", processes[i].id, waitTime + processes[i].burstTime);
    }
    
    printf("Average Waiting Time: %.2f\n", (float) totalWaitTime / count);
}

void SJF(Process processes[], int count) {
    printf("\n--- SJF Scheduling ---\n");
    int waitTime = 0, totalWaitTime = 0;
    
    // Sort processes by burst time (Shortest Job First)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (processes[i].burstTime > processes[j].burstTime) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            waitTime += processes[i-1].burstTime;
        }
        totalWaitTime += waitTime;
        
        printf("Process %d finished after %d time units.\n", processes[i].id, waitTime + processes[i].burstTime);
    }
    
    printf("Average Waiting Time: %.2f\n", (float) totalWaitTime / count);
}

void RoundRobin(Process processes[], int count, int quantum) {
    printf("\n--- Round Robin Scheduling ---\n");
    int time = 0, i = 0;
    float totalWaitTime = 0;
    
    while (1) {
        int done = 1;
        for (i = 0; i < count; i++) {
            if (processes[i].remainingTime > 0) {
                done = 0; // Process is remaining
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    totalWaitTime += time - processes[i].burstTime - processes[i].arrivalTime;
                    printf("Process %d finished after %d time units.\n", processes[i].id, time);
                    processes[i].remainingTime = 0;
                }
            }
        }
        if (done) break; // All processes finished
    }

    printf("Average Waiting Time: %.2f\n", totalWaitTime / count);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if(n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // ID from 1 to n
        printf("Enter arrival time and burst time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining
    }

    printf("Choose a scheduling algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. Round Robin\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS(processes, n);
            break;
        case 2:
            SJF(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            RoundRobin(processes, n, quantum);
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
    }

    return 0;
}