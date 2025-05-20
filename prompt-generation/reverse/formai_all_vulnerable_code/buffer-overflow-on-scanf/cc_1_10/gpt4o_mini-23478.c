//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int wait_time;
    int turnaround_time;
} Process;

void calculateWaitAndTurnaroundTimes(Process process[], int n) {
    for (int i = 0; i < n; i++) {
        process[i].turnaround_time = process[i].burst_time + process[i].wait_time;
    }
}

void printProcessDetails(Process process[], int n) {
    printf("\nProcess ID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].burst_time,
               process[i].wait_time, process[i].turnaround_time);
    }
}

void roundRobinScheduling(Process process[], int n) {
    int time = 0;
    int completed_processes = 0;
    
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (process[i].remaining_time > 0) {
                if (process[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    process[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += process[i].remaining_time;
                    process[i].wait_time = time - process[i].burst_time;
                    process[i].remaining_time = 0;
                    completed_processes++;
                }
            }
        }
    }
    
    calculateWaitAndTurnaroundTimes(process, n);
}

int main() {
    Process process[MAX_PROCESSES];
    int n;

    printf("Welcome to the Round Robin CPU Scheduling Simulator!\n");
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES) {
        printf("Error: Maximum number of processes exceeded!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        process[i].id = i + 1;  // Process ID starts from 1
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &process[i].burst_time);
        process[i].remaining_time = process[i].burst_time;  // Initialize remaining time
        process[i].wait_time = 0;  // Initial wait time
    }

    roundRobinScheduling(process, n);
    printProcessDetails(process, n);

    // Calculate and print average wait time and turnaround time
    float total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_wait_time += process[i].wait_time;
        total_turnaround_time += process[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_wait_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
    
    return 0;
}