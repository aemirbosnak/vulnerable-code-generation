//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
} Process;

void fcfs(Process processes[], int n);
void sjn(Process processes[], int n);
void roundRobin(Process processes[], int n, int quantum);
void displayProcesses(Process processes[], int n);

int main() {
    int n, i, choice, quantum;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Serve (FCFS)\n");
    printf("2. Shortest Job Next (SJN)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjn(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            roundRobin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void displayProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time);
    }
}

void fcfs(Process processes[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
    }

    printf("\nFCFS Scheduling:\n");
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    displayProcesses(processes, n);
    printf("\nWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", waiting_time[i], turnaround_time[i]);
    }
}

void sjn(Process processes[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    fcfs(processes, n); // SJN can be calculated through FCFS after sorting.
}

void roundRobin(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES], waiting_time = 0;
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    printf("\nRound Robin Scheduling:\n");
    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time += time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    printf("Average Waiting Time: %.2f\n", (double)waiting_time / n);
}