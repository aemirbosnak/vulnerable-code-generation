//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

/* process struct */
typedef struct process {
    int pid;
    int priority;
    int burst_time;
    int turnaround_time;
    int waiting_time;
} Process;

/* function to swap two processes */
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

/* implement Priority Scheduling */
void priorityScheduling(Process processes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

/* calculate turnaround and waiting time */
void calculateTime(Process processes[], int n) {
    int i;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

/* display processes and their details */
void displayProcesses(Process processes[], int n) {
    int i;
    printf("PID\tPriority\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, processes[i].burst_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, i;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Error: maximum number of processes is %d\n", MAX_PROCESSES);
        return 0;
    }
    printf("Enter details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d:\n", processes[i].pid);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }
    priorityScheduling(processes, n);
    calculateTime(processes, n);
    displayProcesses(processes, n);
    return 0;
}