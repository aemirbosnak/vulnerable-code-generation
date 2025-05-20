//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pId; // Process ID
    int arrivalTime; // Arrival Time of Process
    int burstTime;  // CPU Burst Time for Process
    int priority; // Priority of Process
    int turnaroundTime; // Turnaround Time of process
    int waitingTime; // Waiting Time of Process
};

void swap(struct Process *p1, struct Process *p2) {
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(struct Process processes[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(processes[j].priority > processes[j+1].priority) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for(int i=0; i<n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    int t=0; // Current Time
    for(int i=0; i<n; i++) {
        processes[i].waitingTime = t - processes[i].arrivalTime;
        t = t + processes[i].burstTime;
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pId, processes[i].arrivalTime, processes[i].burstTime, processes[i].priority, processes[i].turnaroundTime, processes[i].waitingTime);
    }
}

void priorityScheduling(struct Process processes[], int n) {
    bubbleSort(processes, n);
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    displayProcesses(processes, n);
}

int main() {
    int n; // Number of Processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for(int i=0; i<n; i++) {
        printf("Enter the Arrival Time, Burst Time and Priority of Process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].pId = i+1;
    }

    priorityScheduling(processes, n);

    return 0;
}