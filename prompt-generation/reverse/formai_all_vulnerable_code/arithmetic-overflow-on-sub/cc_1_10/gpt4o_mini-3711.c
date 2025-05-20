//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct Process {
    int id;              // Process ID
    int burst_time;     // Burst time
    int arrival_time;   // Arrival time
    int wait_time;      // Waiting time
    int turnaround_time; // Turnaround time
};

void calculate_wait_turnaround_time(struct Process proc[], int n) {
    int total_wait_time = 0, total_turnaround_time = 0;
    
    proc[0].wait_time = 0; // First process waits for 0 time
    for (int i = 1; i < n; i++) {
        proc[i].wait_time = proc[i - 1].wait_time + proc[i - 1].burst_time;
        total_wait_time += proc[i].wait_time;
    }
    
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].wait_time;
        total_turnaround_time += proc[i].turnaround_time;
    }
    
    printf("Average Waiting Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void print_result(struct Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, 
               proc[i].arrival_time, proc[i].wait_time, proc[i].turnaround_time);
    }
}

void sjf_scheduling(struct Process proc[], int n) {
    // Sort processes by arrival time and then by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrival_time > proc[j + 1].arrival_time ||
               (proc[j].arrival_time == proc[j + 1].arrival_time && proc[j].burst_time > proc[j + 1].burst_time)) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    calculate_wait_turnaround_time(proc, n);
    print_result(proc, n);
}

int main() {
    int n;
    struct Process proc[MAX_PROCESSES];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter Process ID, Burst Time and Arrival Time:\n");
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assigning process IDs as 1, 2, 3...
        printf("Process %d: ", i + 1);
        scanf("%d %d", &proc[i].burst_time, &proc[i].arrival_time);
    }
    
    sjf_scheduling(proc, n);

    return 0;
}