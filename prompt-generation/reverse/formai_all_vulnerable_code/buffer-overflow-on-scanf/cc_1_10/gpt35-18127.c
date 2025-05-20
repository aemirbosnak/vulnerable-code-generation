//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Creating a process struct to hold the process information
typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} Process;

// Function to calculate the waiting time, turnaround time and completion status of each process
void calculate(Process *process_list, int n, int current_time, int *total_waiting_time, int *total_turnaround_time, int *completed_processes) {
    int shortest_job = -1; // Index of process with shortest remaining burst time
    int shortest_burst_time = INT_MAX; // Minimum burst time among all incomplete processes

    for(int i = 0; i < n; i++) {
        if(!process_list[i].completed && process_list[i].arrival_time <= current_time) {
            if(process_list[i].burst_time < shortest_burst_time) {
                shortest_burst_time = process_list[i].burst_time;
                shortest_job = i;
            }
        }
    }

    // If there's no process with arrival time less than or equal to current_time
    if(shortest_job == -1) {
        printf("CPU idle for 1 unit\n");
        (*total_turnaround_time)++;
        return;
    }

    // If shortest job is found, execute it for 1 time unit
    process_list[shortest_job].burst_time -= 1;
    (*total_turnaround_time)++;
    current_time++;

    // If the process has completed executing, calculate its waiting time and completion status
    if(process_list[shortest_job].burst_time == 0) {
        process_list[shortest_job].waiting_time = current_time - process_list[shortest_job].arrival_time - process_list[shortest_job].turnaround_time;
        process_list[shortest_job].turnaround_time = current_time - process_list[shortest_job].arrival_time;

        (*total_waiting_time) += process_list[shortest_job].waiting_time;
        (*total_turnaround_time) += process_list[shortest_job].turnaround_time;
        (*completed_processes)++;
        process_list[shortest_job].completed = true;

        printf("Process %d completed at time %d. Waiting time = %d. Turnaround time = %d\n", process_list[shortest_job].process_id, current_time, process_list[shortest_job].waiting_time, process_list[shortest_job].turnaround_time);
    }
}

// Function to perform Shortest Job First (SJF) Scheduling
void sjf(Process *process_list, int n) {
    int current_time = 0; // Current time
    int total_waiting_time = 0; // Total waiting time of all processes
    int total_turnaround_time = 0; // Total turnaround time of all processes
    int completed_processes = 0; // Number of completed processes

    // Execution loop
    while(completed_processes < n) {
        calculate(process_list, n, current_time, &total_waiting_time, &total_turnaround_time, &completed_processes);
    }

    // Print average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", (float) total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float) total_turnaround_time / n);
}

int main() {
    int n;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process information
    Process *process_list = malloc(n * sizeof(Process));
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of Process %d: ", i + 1);
        scanf("%d %d", &process_list[i].arrival_time, &process_list[i].burst_time);
        process_list[i].process_id = i + 1;
        process_list[i].waiting_time = 0;
        process_list[i].turnaround_time = 0;
        process_list[i].completed = false;
    }

    // Perform SJF scheduling
    sjf(process_list, n);

    return 0;
}