//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
} Process;

void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].arrival_time > p[j].arrival_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

void calculateWaitingAndTurnaroundTimes(Process p[], int n) {
    p[0].waiting_time = 0; // first process waits 0
    p[0].turnaround_time = p[0].burst_time; // turnaround time is equal to burst time

    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void printGanttChart(Process p[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i].id);
    }
    printf("|\n");

    printf("0 ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i].turnaround_time);
    }
    printf("\n");
}

void printAverageTimes(Process p[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    
    printf("\nAverage waiting time: %.2f", total_waiting_time / n);
    printf("\nAverage turnaround time: %.2f\n", total_turnaround_time / n);
}

void scheduleProcesses(Process p[], int n) {
    sortByArrival(p, n);
    calculateWaitingAndTurnaroundTimes(p, n);
    printGanttChart(p, n);
    printAverageTimes(p, n);
}

int main() {
    int n, i;
    Process processes[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for process P%d: ", processes[i].id);
        scanf("%d%d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].finish_time = 0;
    }

    scheduleProcesses(processes, n);

    return 0;
}