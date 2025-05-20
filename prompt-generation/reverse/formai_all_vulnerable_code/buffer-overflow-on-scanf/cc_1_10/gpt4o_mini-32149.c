//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void initialize_processes(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].remaining_time = processes[i].burst_time;
    }
}

void calculate_times(Process processes[], int n, int time_quantum) {
    int current_time = 0;
    int completed_processes = 0;
    int i = 0;

    while (completed_processes < n) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
            if (processes[i].remaining_time > time_quantum) {
                current_time += time_quantum;
                processes[i].remaining_time -= time_quantum;
            } else {
                current_time += processes[i].remaining_time;
                processes[i].turnaround_time = current_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                processes[i].remaining_time = 0;
                completed_processes++;
            }
        }
        i = (i + 1) % n;
    }
}

void print_processes(Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int n;
    int time_quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESS);
    scanf("%d", &n);

    if (n > MAX_PROCESS || n <= 0) {
        printf("Invalid number of processes. Please restart and enter a valid number.\n");
        return 1; // Exit if invalid input
    }

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    initialize_processes(processes, n);
    calculate_times(processes, n, time_quantum);
    print_processes(processes, n);

    return 0;
}