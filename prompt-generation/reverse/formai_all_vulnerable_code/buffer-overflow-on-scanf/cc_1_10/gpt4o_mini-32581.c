//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void find_turnaround_times(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void find_waiting_times(struct Process proc[], int n, int time_quantum) {
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    proc[i].remaining_time -= time_quantum;
                } else {
                    time += proc[i].remaining_time;
                    proc[i].waiting_time = time - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                    remaining_processes--;
                }
            }
        }
    }
}

void calculate_scheduling(struct Process proc[], int n, int time_quantum) {
    find_waiting_times(proc, n, time_quantum);
    find_turnaround_times(proc, n);
}

void print_process_details(struct Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].id, 
               proc[i].burst_time, 
               proc[i].waiting_time, 
               proc[i].turnaround_time);
    }
}

int main() {
    struct Process proc[MAX_PROCESSES];
    int n, time_quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Maximum number of processes is %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assigning process IDs starting from 1
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time; // Initialize remaining time
        proc[i].waiting_time = 0; // Initialize waiting time to 0
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    calculate_scheduling(proc, n, time_quantum);
    print_process_details(proc, n);

    return 0;
}