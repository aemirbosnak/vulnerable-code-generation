//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int bt; // Burst Time for Process
    int at; // Arrival Time of Process
    int tat; // Turnaround Time for Process
    int wt; // Waiting Time for Process
} Process;

// Compare Function for qsort() to sort based on Arrival Time
int compare(const void* a, const void* b) {
    return ((Process*)a)->at - ((Process*)b)->at;
}

// FCFS Scheduling Algorithm
void fcfs(Process* processes, int n) {
    // Sort Processes based on Arrival Time
    qsort(processes, n, sizeof(Process), compare);

    int t = 0; // Current Time
    for(int i = 0; i < n; i++) {
        t += processes[i].bt;
        processes[i].tat = t - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

// SJF Scheduling Algorithm
void sjf(Process* processes, int n) {
    int t = 0; // Current Time
    int index = 0; // Index of Process with Shortest Burst Time

    // Loop until all Processes are executed
    while(n > 0) {
        // Select Process with Shortest Burst Time
        for(int i = 0; i < n; i++) {
            if(processes[i].at <= t && processes[i].bt < processes[index].bt) {
                index = i;
            }
        }

        // Execute Process and update Time, TT, and WT
        t += processes[index].bt;
        processes[index].tat = t - processes[index].at;
        processes[index].wt = processes[index].tat - processes[index].bt;

        // Remove Process from Array
        for(int i = index; i < n-1; i++) {
            processes[i] = processes[i+1];
        }
        n--;
        index = 0;
    }
}

int main() {
    int n; // Number of Processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate Memory for Array of Processes
    Process* processes = (Process*)malloc(n * sizeof(Process));

    // Read Input Values
    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &processes[i].bt);
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &processes[i].at);
        processes[i].pid = i+1; // Set Process ID
    }

    // Run FCFS Algorithm
    fcfs(processes, n);
    printf("\nFCFS Scheduling Algorithm\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|   Process   |   Burst Time   |   Arrival Time   |   Turnaround Time   |   Waiting Time   |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("|     %3d     |       %3d      |        %3d        |         %3d         |        %3d      |\n",
            processes[i].pid, processes[i].bt, processes[i].at, processes[i].tat, processes[i].wt);
    }
    printf("-----------------------------------------------------------------------------\n");

    // Run SJF Algorithm
    sjf(processes, n);
    printf("\nSJF Scheduling Algorithm\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|   Process   |   Burst Time   |   Arrival Time   |   Turnaround Time   |   Waiting Time   |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("|     %3d     |       %3d      |        %3d        |         %3d         |        %3d      |\n",
            processes[i].pid, processes[i].bt, processes[i].at, processes[i].tat, processes[i].wt);
    }
    printf("-----------------------------------------------------------------------------\n");

    // Free Memory
    free(processes);
    return 0;
}