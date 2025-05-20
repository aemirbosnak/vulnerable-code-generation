//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0; // first process always has 0 waiting time

    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
    }
}

void calculateTurnaroundTime(Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void calculateAverageTime(Process processes[], int n) {
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    calculateWaitingTime(processes, n, waiting_time);
    calculateTurnaroundTime(processes, n, waiting_time, turnaround_time);

    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                processes[i].arrival_time, 
                waiting_time[i], 
                turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void sortProcessesByArrival(Process processes[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void scheduleProcesses() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    sortProcessesByArrival(processes, n);
    calculateAverageTime(processes, n);
}

int main() {
    scheduleProcesses();
    return 0;
}