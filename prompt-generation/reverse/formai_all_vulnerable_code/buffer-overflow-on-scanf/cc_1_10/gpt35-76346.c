//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Process structure for keeping track of running processes */
typedef struct {
    int pid;            // process ID
    int arrival_time;   // arrival time of the process
    int burst_time;     // burst time of the process
    int waiting_time;   // waiting time of the process
    int turnaround_time;// turnaround time of the process
    int remaining_time; // remaining time of the process
} process_t;

/* Function to calculate the average waiting and turnaround time */
void calc_avg_times(process_t *processes, int num_processes, float *avg_waiting_time, float *avg_turnaround_time) {
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // calculate the averages
    *avg_waiting_time = total_waiting_time / num_processes;
    *avg_turnaround_time = total_turnaround_time / num_processes;
}

/* First-Come, First-Serve (FCFS) scheduling algorithm */
void fcfs(process_t *processes, int num_processes) {
    int i, current_time = 0;

    for (i = 0; i < num_processes; i++) {
        // calculate waiting and turnaround time for the current process
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // update the current time and remaining time of the process
        current_time += processes[i].burst_time;
        processes[i].remaining_time = 0;
    }
}

/* Shortest Job First (SJF) scheduling algorithm */
void sjf(process_t *processes, int num_processes) {
    int i, j, shortest_job_index, current_time = 0;

    for (i = 0; i < num_processes; i++) {
        // find the process with the shortest remaining time
        shortest_job_index = -1;
        for (j = 0; j < num_processes; j++) {
            if (processes[j].remaining_time > 0 && (shortest_job_index == -1 || processes[j].remaining_time < processes[shortest_job_index].remaining_time)) {
                shortest_job_index = j;
            }
        }

        // calculate waiting and turnaround time for the current process
        processes[shortest_job_index].waiting_time = current_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].turnaround_time = processes[shortest_job_index].waiting_time + processes[shortest_job_index].burst_time;

        // update the current time and remaining time of the process
        current_time += processes[shortest_job_index].burst_time;
        processes[shortest_job_index].remaining_time = 0;
    }
}

int main() {
    int i, num_processes, algorithm_choice;
    float avg_waiting_time, avg_turnaround_time;
    process_t *processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // allocate memory for the processes
    processes = (process_t *) malloc(num_processes * sizeof(process_t));

    // get the details of each process from the user
    for (i = 0; i < num_processes; i++) {
        printf("Enter details for process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    // ask the user which scheduling algorithm to use
    printf("Choose a scheduling algorithm:\n1. First-Come, First-Serve (FCFS)\n2. Shortest Job First (SJF)\n");
    scanf("%d", &algorithm_choice);

    switch (algorithm_choice) {
        case 1:
            fcfs(processes, num_processes);
            printf("\nFCFS Scheduling:\n");
            break;
        case 2:
            sjf(processes, num_processes);
            printf("\nSJF Scheduling:\n");
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    // print the details of each process
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // calculate and print the averages
    calc_avg_times(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    free(processes);   // free the memory allocated for the processes

    return 0;
}