//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;          // Process ID
    int burst_time;  // Burst time of the process
    int arrival_time; // Arrival time of the process
    int waiting_time; // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
};

void calculateWaitingTime(struct Process proc[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
        proc[i].waiting_time = 0;
    }

    int t = 0; // Current time
    while (1) {
        int done = 1; // Check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There are still processes remaining
                if (remaining_time[i] > quantum) {
                    t += quantum; // Increase time by quantum
                    remaining_time[i] -= quantum; // Decrease remaining time
                } else {
                    t += remaining_time[i]; // Finish this process
                    proc[i].waiting_time = t - proc[i].burst_time - proc[i].arrival_time;
                    remaining_time[i] = 0; // Process finished
                }
            }
        }
        if (done == 1) {
            break; // If all processes are done
        }
    }
}

void calculateTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void findavgTime(struct Process proc[], int n, int quantum) {
    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);

    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].id, 
               proc[i].burst_time, 
               proc[i].arrival_time, 
               proc[i].waiting_time, 
               proc[i].turnaround_time);
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process *proc = malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assigning process IDs
        printf("Enter Burst Time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].arrival_time);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    findavgTime(proc, n, quantum);

    free(proc); // Free allocated memory
    return 0;
}