//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;             // Process ID
    int burst_time;     // Burst time required by the process
    int arrival_time;   // Arrival time of the process
    int waiting_time;   // Waiting time for the process
    int turnaround_time; // Turnaround time for the process
} Process;

void calculate_times(Process processes[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / num_processes);
}

void sort_processes_arrival(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void schedule_fcfs(Process processes[], int num_processes) {
    // First-Come, First-Served (FCFS) Scheduling
    printf("\nFCFS Scheduling:\n");
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d - Waiting Time: %d, Turnaround Time: %d\n", 
                processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }
    calculate_times(processes, num_processes);
}

void schedule_sjf(Process processes[], int num_processes) {
    // Shortest Job First (SJF) Scheduling
    printf("\nSJF Scheduling:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d - Waiting Time: %d, Turnaround Time: %d\n", 
                processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }
    calculate_times(processes, num_processes);
}

int main() {
    Process processes[MAX_PROCESSES];

    int num_processes;
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);
    
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1; // Process IDs start from 1
        printf("Enter burst time and arrival time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].waiting_time = 0; // Initialize waiting time
        processes[i].turnaround_time = 0; // Initialize turnaround time
    }
    
    sort_processes_arrival(processes, num_processes);
    
    schedule_fcfs(processes, num_processes);
    schedule_sjf(processes, num_processes);

    return 0;
}