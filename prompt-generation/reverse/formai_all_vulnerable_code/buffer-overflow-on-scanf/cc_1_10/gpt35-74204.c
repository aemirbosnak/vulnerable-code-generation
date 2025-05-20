//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_BURST_TIME 1000

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
} Process;

void schedule_fcfs(Process *processes, int num_processes);
void schedule_rr(Process *processes, int num_processes, int time_quantum);
void schedule_sjf(Process *processes, int num_processes);
void schedule_priority(Process *processes, int num_processes);

int main() {
    int num_processes, time_quantum;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;

        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;
    }

    // First Come, First Served (FCFS)
    printf("\n---FCFS---\n");
    schedule_fcfs(processes, num_processes);

    // Round Robin (RR)
    printf("\n---RR---\n");
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    schedule_rr(processes, num_processes, time_quantum);

    // Shortest Job First (SJF)
    printf("\n---SJF---\n");
    schedule_sjf(processes, num_processes);

    // Priority
    printf("\n---Priority---\n");
    schedule_priority(processes, num_processes);

    return 0;
}

void schedule_fcfs(Process *processes, int num_processes) {
    int current_time = 0;
    int total_turnaround_time = 0;

    printf("Processes\tArrival Time\tBurst Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        current_time = (current_time > processes[i].arrival_time) ? current_time : processes[i].arrival_time;
        processes[i].turnaround_time = current_time + processes[i].burst_time - processes[i].arrival_time;
        total_turnaround_time += processes[i].turnaround_time;
        current_time += processes[i].burst_time;
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time);
    }

    double avg_turnaround_time = ((double) total_turnaround_time) / num_processes;
    printf("Average turnaround time: %f\n", avg_turnaround_time);
}

void schedule_rr(Process *processes, int num_processes, int time_quantum) {
    int current_time = 0;
    int total_turnaround_time = 0;

    int *remaining_times = malloc(num_processes * sizeof(int));
    int *arrival_times = malloc(num_processes * sizeof(int));
    for (int i = 0; i < num_processes; i++) {
        remaining_times[i] = processes[i].burst_time;
        arrival_times[i] = processes[i].arrival_time;
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < num_processes; i++) {
            if (remaining_times[i] > 0) {
                done = 0;
                if (remaining_times[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_times[i] -= time_quantum;
                } else {
                    current_time += remaining_times[i];
                    processes[i].turnaround_time = current_time - arrival_times[i];
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_times[i] = 0;
                    printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time);
                }           
            }
        }
        if (done == 1) {
            break;
        }
    }

    double avg_turnaround_time = ((double) total_turnaround_time) / num_processes;
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    free(remaining_times);
    free(arrival_times);
}

void schedule_sjf(Process *processes, int num_processes) {
    int current_time = 0;
    int total_turnaround_time = 0;

    int *remaining_times = malloc(num_processes * sizeof(int));
    int *arrival_times = malloc(num_processes * sizeof(int));
    for (int i = 0; i < num_processes; i++) {
        remaining_times[i] = processes[i].burst_time;
        arrival_times[i] = processes[i].arrival_time;
    }
    
    while (1) {
        int done = 1;
        int shortest_job_index = -1;
        int shortest_job_remaining_time = MAX_BURST_TIME;
        for (int i = 0; i < num_processes; i++) {
            if (remaining_times[i] > 0 && remaining_times[i] < shortest_job_remaining_time && arrival_times[i] <= current_time) {
                done = 0;
                shortest_job_index = i;
                shortest_job_remaining_time = remaining_times[i];
            }
        }
        if (done == 1) {
            break;
        }
        current_time += shortest_job_remaining_time;
        processes[shortest_job_index].turnaround_time = current_time - arrival_times[shortest_job_index];
        total_turnaround_time += processes[shortest_job_index].turnaround_time;
        remaining_times[shortest_job_index] = 0;
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[shortest_job_index].id, processes[shortest_job_index].arrival_time, processes[shortest_job_index].burst_time, processes[shortest_job_index].turnaround_time);
    }

    double avg_turnaround_time = ((double) total_turnaround_time) / num_processes;
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    free(remaining_times);
    free(arrival_times);
}

void schedule_priority(Process *processes, int num_processes) {
    int current_time = 0;
    int total_turnaround_time = 0;

    int *remaining_times = malloc(num_processes * sizeof(int));
    int *arrival_times = malloc(num_processes * sizeof(int));
    int *priorities = malloc(num_processes * sizeof(int));
    for (int i = 0; i < num_processes; i++) {
        remaining_times[i] = processes[i].burst_time;
        arrival_times[i] = processes[i].arrival_time;
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &priorities[i]);
        processes[i].remaining_time = remaining_times[i];
    }

    while (1) {
        int done = 1;
        int highest_priority_index = -1;
        int highest_priority_remaining_time = MAX_BURST_TIME;
        for (int i = 0; i < num_processes; i++) {
            if (remaining_times[i] > 0 && priorities[i] < highest_priority_remaining_time && arrival_times[i] <= current_time) {
                done = 0;
                highest_priority_index = i;
                highest_priority_remaining_time = priorities[i];
            }
        }
        if (done == 1) {
            break;
        }
        current_time += highest_priority_remaining_time;
        processes[highest_priority_index].turnaround_time = current_time - arrival_times[highest_priority_index];
        total_turnaround_time += processes[highest_priority_index].turnaround_time;
        remaining_times[highest_priority_index] = 0;
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[highest_priority_index].id, processes[highest_priority_index].arrival_time, processes[highest_priority_index].burst_time, processes[highest_priority_index].turnaround_time);
    }

    double avg_turnaround_time = ((double) total_turnaround_time) / num_processes;
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    free(remaining_times);
    free(arrival_times);
    free(priorities);
}