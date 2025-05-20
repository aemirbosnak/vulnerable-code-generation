//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
}Process;

void FCFS(Process *processes, int n) {
    printf("\n----- First Come First Serve (FCFS) -----");

    int currentTime = 0;
    float waitingTime = 0, turnaroundTime = 0;
    for(int i=0; i<n; i++) {
        if(currentTime < processes[i].arrivalTime) 
            currentTime = processes[i].arrivalTime;

        waitingTime += currentTime - processes[i].arrivalTime;
        turnaroundTime += currentTime + processes[i].burstTime - processes[i].arrivalTime;

        currentTime += processes[i].burstTime;
    }

    printf("\nAverage Waiting Time: %f", waitingTime/n);
    printf("\nAverage Turnaround Time: %f", turnaroundTime/n);
}

void SJF(Process *processes, int n) {
    printf("\n----- Shortest Job First (SJF) -----");

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(processes[i].burstTime > processes[j].burstTime) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int currentTime = 0;
    float waitingTime = 0, turnaroundTime = 0;
    for(int i=0; i<n; i++) {
        if(currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        waitingTime += currentTime - processes[i].arrivalTime;
        turnaroundTime += currentTime + processes[i].burstTime - processes[i].arrivalTime;

        currentTime += processes[i].burstTime;
    }

    printf("\nAverage Waiting Time: %f", waitingTime/n);
    printf("\nAverage Turnaround Time: %f", turnaroundTime/n);
}

void Priority(Process *processes, int n) {
    printf("\n----- Priority Scheduling -----");

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(processes[i].priority < processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int currentTime = 0;
    float waitingTime = 0, turnaroundTime = 0;
    for(int i=0; i<n; i++) {
        if(currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        waitingTime += currentTime - processes[i].arrivalTime;
        turnaroundTime += currentTime + processes[i].burstTime - processes[i].arrivalTime;

        currentTime += processes[i].burstTime;
    }

    printf("\nAverage Waiting Time: %f", waitingTime/n);
    printf("\nAverage Turnaround Time: %f", turnaroundTime/n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process*)malloc(sizeof(Process)*n);
    for(int i=0; i<n; i++) {
        printf("\nEnter the arrival time for Process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter the burst time for Process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter the priority for Process %d: ", i+1);
        scanf("%d", &processes[i].priority);

        processes[i].pid = i+1;
    }

    FCFS(processes, n);
    SJF(processes, n);
    Priority(processes, n);

    free(processes);

    return 0;
}