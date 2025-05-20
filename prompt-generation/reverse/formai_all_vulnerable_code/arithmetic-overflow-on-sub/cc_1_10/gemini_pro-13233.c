//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define process structure
typedef struct process {
    int pid;        // Process ID
    int bt;         // Burst time
    int at;         // Arrival time
    int ct;         // Completion time
    int wt;         // Waiting time
    int tt;         // Turnaround time
    int remaining_bt;// Remaining burst time
} process;

// Function to sort processes by arrival time
void sort_by_arrival_time(process *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to find the waiting time for each process
void find_waiting_time(process *p, int n) {
    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].ct - p[i].at;
        if (p[i].wt < 0) {
            p[i].wt = 0;
        }
    }
}

// Function to find the turnaround time for each process
void find_turnaround_time(process *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].tt = p[i].ct - p[i].at;
    }
}

// Function to find the average waiting time and turnaround time
void find_avg_time(process *p, int n) {
    int total_wt = 0, total_tt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tt += p[i].tt;
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tt / n);
}

// Function to print the Gantt chart
void print_gantt_chart(process *p, int n) {
    printf("Gantt Chart:\n");
    printf("------------------------------------------------------------------\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i].pid);
    }
    printf("\n");
    printf("------------------------------------------------------------------\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        printf("    %d", p[i].ct);
    }
    printf("\n");
    printf("------------------------------------------------------------------\n");
}

int main() {
    // Get the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get the burst time and arrival time for each process
    process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        p[i].pid = i + 1;
        p[i].remaining_bt = p[i].bt;
    }

    // Sort the processes by arrival time
    sort_by_arrival_time(p, n);

    // Get the time quantum
    int tq;
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Simulate the round robin scheduling algorithm
    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0) {
                done = 0;
                if (p[i].remaining_bt <= tq) {
                    time += p[i].remaining_bt;
                    p[i].ct = time;
                    p[i].remaining_bt = 0;
                } else {
                    p[i].remaining_bt -= tq;
                    time += tq;
                }
            }
        }
        if (done) {
            break;
        }
    }

    // Find the waiting time and turnaround time for each process
    find_waiting_time(p, n);
    find_turnaround_time(p, n);

    // Find the average waiting time and turnaround time
    find_avg_time(p, n);

    // Print the Gantt chart
    print_gantt_chart(p, n);

    return 0;
}