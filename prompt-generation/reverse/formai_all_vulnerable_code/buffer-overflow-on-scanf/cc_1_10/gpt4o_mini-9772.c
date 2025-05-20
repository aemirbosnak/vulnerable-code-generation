//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
} Process;

void calculateWaitingTime(Process processes[], int n) {
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void calculateTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void sortProcessesByPriority(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void displayProcessInfo(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].pid, 
            processes[i].burstTime, 
            processes[i].priority, 
            processes[i].waitingTime, 
            processes[i].turnAroundTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Exiting.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Assigning Process ID
        printf("Enter burst time for Process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority for Process %d (lower number means higher priority): ", processes[i].pid);
        scanf("%d", &processes[i].priority);
    }

    // Sort processes based on priority
    sortProcessesByPriority(processes, n);

    // Calculate waiting and turnaround times
    calculateWaitingTime(processes, n);
    calculateTurnAroundTime(processes, n);

    // Display process information
    displayProcessInfo(processes, n);
    
    // Calculate and display average waiting time and turnaround time
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);

    return EXIT_SUCCESS;
}