//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate waiting time
void calculate_waiting_time(struct Process processes[], int n, int waiting_time[], int quantum) {
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
        waiting_time[i] = 0;
    }

    int time = 0;
    int completed = 0;

    while (completed < n) {
        int done = 0;

        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0 && processes[i].arrival_time <= time) {
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    waiting_time[i] += (time - processes[i].burst_time - processes[i].arrival_time);
                    remaining_burst[i] = 0;
                    completed++;
                }
                done = 1;
            }
        }
        if (!done) {
            time++;
        }
    }
}

// Function to calculate turnaround time
void calculate_turnaround_time(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

// Function to calculate average times
void calculate_average_time(struct Process processes[], int n, int quantum) {
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    calculate_waiting_time(processes, n, waiting_time, quantum);
    calculate_turnaround_time(processes, n, waiting_time, turnaround_time);

    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    calculate_average_time(processes, n, quantum);

    return 0;
}