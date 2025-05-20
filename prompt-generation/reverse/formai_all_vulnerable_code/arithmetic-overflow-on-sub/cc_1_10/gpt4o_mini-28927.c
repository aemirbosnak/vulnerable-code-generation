//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
} Process;

// Function prototypes
void inputProcesses(Process processes[], int *n);
void fcfs(Process processes[], int n);
void sjn(Process processes[], int n);
void roundRobin(Process processes[], int n, int time_quantum);
void printGanttChart(int gantt[], int size);

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, time_quantum;

    inputProcesses(processes, &n);

    printf("CPU Scheduling Algorithms:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job Next (SJN)\n");
    printf("3. Round Robin (RR)\n");
    printf("Choose a scheduling algorithm: ");
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
            scanf("%d", &time_quantum);
            roundRobin(processes, n, time_quantum);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}

void inputProcesses(Process processes[], int *n) {
    printf("Enter the number of processes: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }
}

void fcfs(Process processes[], int n) {
    int total_time = 0, waiting_time = 0, turnaround_time = 0;
    int gantt[MAX_PROCESSES] = {0};
    printf("FCFS Scheduling:\n");

    for (int i = 0; i < n; i++) {
        if (total_time < processes[i].arrival_time) {
            total_time = processes[i].arrival_time;
        }
        gantt[i] = total_time;
        waiting_time += total_time - processes[i].arrival_time;
        total_time += processes[i].burst_time;
        turnaround_time += total_time - processes[i].arrival_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaround_time / n);
    printGanttChart(gantt, n);
}

void sjn(Process processes[], int n) {
    int waiting_time = 0, turnaround_time = 0;
    int gantt[MAX_PROCESSES] = {0};
    Process temp;

    // Sort processes by burst_time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int total_time = 0;
    printf("SJN Scheduling:\n");

    for (int i = 0; i < n; i++) {
        if (total_time < processes[i].arrival_time) {
            total_time = processes[i].arrival_time;
        }
        gantt[i] = total_time;
        waiting_time += total_time - processes[i].arrival_time;
        total_time += processes[i].burst_time;
        turnaround_time += total_time - processes[i].arrival_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaround_time / n);
    printGanttChart(gantt, n);
}

void roundRobin(Process processes[], int n, int time_quantum) {
    int waiting_time = 0, turnaround_time = 0;
    int gantt[MAX_PROCESSES] = {0};
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int total_time = 0, idx = 0, i = 0;
    printf("Round Robin Scheduling:\n");

    while (1) {
        int all_done = 1;
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_done = 0;
                if (remaining_time[i] > time_quantum) {
                    gantt[idx++] = total_time;
                    total_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    gantt[idx++] = total_time;
                    total_time += remaining_time[i];
                    waiting_time += total_time - processes[i].burst_time - processes[i].arrival_time;
                    turnaround_time += total_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (all_done) {
            break;
        }
    }
    printf("Average Waiting Time: %.2f\n", (float)waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaround_time / n);
    printGanttChart(gantt, idx);
}

void printGanttChart(int gantt[], int size) {
    printf("Gantt Chart:\n");
    for (int i = 0; i < size; i++) {
        printf("| P%d ", i + 1);
    }
    printf("|\n");
    for (int i = 0; i < size; i++) {
        printf("%d   ", gantt[i]);
    }
    printf("%d\n", gantt[size - 1]);
}