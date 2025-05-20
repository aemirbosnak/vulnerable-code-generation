//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    remaining_processes--;
                }
            }
        }
    }
}

void calculateAverageTimes(Process processes[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESS);
    scanf("%d", &n);

    if (n > MAX_PROCESS || n <= 0) {
        printf("Invalid number of processes. Please enter a number between 1 and %d.\n", MAX_PROCESS);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter time quantum for the Round Robin scheduling: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum);
    calculateAverageTimes(processes, n);
    printProcesses(processes, n);

    return 0;
}