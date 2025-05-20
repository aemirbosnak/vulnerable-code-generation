//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>

// Defining the Process Struct
struct Process {
    int pid;
    int burstTime;
    int waitTime;
    int turnaroundTime;
};

// Function to calculate the waiting time and turnaround time of processes
void calculateTimes(struct Process *proc, int n) {
    int sum = 0;
    proc[0].waitTime = 0;
    proc[0].turnaroundTime = proc[0].burstTime;

    for(int i=1; i<n; i++) {
        proc[i].waitTime = sum;
        proc[i].turnaroundTime = proc[i].waitTime + proc[i].burstTime;
        sum += proc[i].burstTime;
    }
}

// Function to print the process details
void printProcesses(struct Process *proc, int n) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].waitTime, proc[i].turnaroundTime);
    }
}

// Function to implement First Come First Serve (FCFS) Scheduling Algorithm
void FCFS(struct Process *proc, int n) {
    calculateTimes(proc, n);
    printProcesses(proc, n);
}

// Function to sort the processes based on their Burst Time
void sortProcesses(struct Process *proc, int n) {
    // Using Bubble Sort to sort the processes based on their Burst Time
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(proc[j].burstTime > proc[j+1].burstTime) {
                struct Process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

// Function to implement Shortest Job First (SJF) Scheduling Algorithm
void SJF(struct Process *proc, int n) {
    sortProcesses(proc, n);
    calculateTimes(proc, n);
    printProcesses(proc, n);
}

// Main function to test the CPU Scheduling Algorithms
int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Taking input for each process
    for(int i=0; i<n; i++) {
        printf("Enter the Burst Time for Process %d: ", i+1);
        scanf("%d", &proc[i].burstTime);
        proc[i].pid = i+1;
    }

    printf("\nFCFS Scheduling Algorithm\n");
    FCFS(proc, n);

    printf("\nSJF Scheduling Algorithm\n");
    SJF(proc, n);

    return 0;
}