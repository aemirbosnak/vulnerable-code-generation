//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate wait and turnaround times
void calculate_times(struct Process processes[], int n, int quantum) {
    int remaining_bt[n];
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int time = 0;
    int completed = 0;

    // Process the scheduling
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                if (remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = time;
                    remaining_bt[i] = 0;
                    completed++;
                }
            }
        }
    }
}

// Function to display the results
void display_results(struct Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, 
            processes[i].burst_time, processes[i].waiting_time, 
            processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process *processes = malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    calculate_times(processes, n, quantum);
    display_results(processes, n);

    free(processes);
    return 0;
}