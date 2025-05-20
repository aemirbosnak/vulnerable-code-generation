//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int processID; 
    int arrivalTime; 
    int burstTime; 
    int completionTime; 
    int waitingTime; 
    int turnaroundTime; 
} Process;

void sortProcessesByArrival(Process processes[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

float calculateAverageTime(Process processes[], int n) {
    float totalWaitingTime = 0.0;
    float totalTurnaroundTime = 0.0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    return totalWaitingTime / n;
}

void displayProcesses(Process processes[], int n) {
    printf("\nProcessID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].processID, 
               processes[i].arrivalTime, 
               processes[i].burstTime, 
               processes[i].completionTime, 
               processes[i].waitingTime, 
               processes[i].turnaroundTime);
    }
}

void applyFCFS(Process processes[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

int main() {
    int n;

    printf("Oh, cherished love! How many processes shall we dance with? ");
    scanf("%d", &n); // The number of processes.

    Process *processes = malloc(n * sizeof(Process));

    // Entering process details
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("For process %d, when did they arrive in this beautiful journey? ", processes[i].processID);
        scanf("%d", &processes[i].arrivalTime);
        printf("And how long shall they linger in our lives (burst time)? ");
        scanf("%d", &processes[i].burstTime);
    }

    // Sweetly sort by arrival time, like lovers finding each other in the crowd.
    sortProcessesByArrival(processes, n);
    
    // Apply the fairy tale of First-Come, First-Served
    applyFCFS(processes, n);

    // Display the dances of our processes
    displayProcesses(processes, n);

    // Finally, calculate the average waiting and turnaround times.
    calculateAverageTime(processes, n);
    
    free(processes);
    return 0;
}