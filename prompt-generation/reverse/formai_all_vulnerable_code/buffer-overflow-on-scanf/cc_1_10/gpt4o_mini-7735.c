//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for(int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int time = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is a pending process
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time = time + remaining_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for(int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void printSummary(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].id, 
            processes[i].burst_time, 
            processes[i].arrival_time, 
            processes[i].waiting_time, 
            processes[i].turnaround_time);
    }
}

int compareArrivalTime(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return (p1->arrival_time - p2->arrival_time);
}

void scheduleProcesses(Process processes[], int n, int quantum) {
    qsort(processes, n, sizeof(Process), compareArrivalTime);

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printSummary(processes, n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Please run the program again.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    printf("Enter the Arrival Time and Burst Time for each process:\n");
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    scheduleProcesses(processes, n, quantum);

    return 0;
}