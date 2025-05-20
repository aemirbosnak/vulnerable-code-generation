//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // maximum number of processes
#define TIME_QUANTUM 2 // fixed time quantum for round-robin scheduling

typedef struct Process {
    int process_id; // process identifier
    int arrival_time; // arrival time of process in the ready queue
    int burst_time; // time required to execute the process
    int remaining_time; // time remaining for the process to complete
    int turnaround_time; // total time taken for a process to complete
    int waiting_time; // time spent by a process waiting in the ready queue
} Process;

void fcfs_schedule(Process *processes, int num_processes);
void sjf_schedule(Process *processes, int num_processes);
void round_robin_schedule(Process *processes, int num_processes);

int main() {
    int choice, num_processes;
    Process processes[MAX_PROCESSES];
    
    printf("Enter number of processes (1-10): ");
    scanf("%d", &num_processes);
    
    // input process details
    printf("Enter process details: \n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: \n", i+1);
        processes[i].process_id = i+1;
        printf("   Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("   Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    // selecting scheduling algorithm
    printf("Select Scheduling Algorithm: \n");
    printf("1. First Come First Serve (FCFS) Scheduling\n");
    printf("2. Shortest Job First (SJF) Scheduling\n");
    printf("3. Round Robin (RR) Scheduling (fixed time quantum = 2)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            fcfs_schedule(processes, num_processes);
            break;
        case 2:
            sjf_schedule(processes, num_processes);
            break;
        case 3:
            round_robin_schedule(processes, num_processes);
            break;
        default:
            printf("Invalid Choice. Please enter a valid option.\n");
            break;
    }
    
    return 0;
}

// FCFS Scheduling Algorithm
void fcfs_schedule(Process *processes, int num_processes) {
    int curr_time = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    
    // scheduling processes in the order of their arrival time
    for (int i = 0; i < num_processes; i++) {
        if (curr_time < processes[i].arrival_time) {
            curr_time = processes[i].arrival_time;
        }
        curr_time += processes[i].burst_time;
        processes[i].turnaround_time = curr_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;
    
    // printing process details
    printf("\n\n");
    printf("FCFS Scheduling:\n");
    printf("Process\t Arrival Time\t Burst Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
}

// SJF Scheduling Algorithm
void sjf_schedule(Process *processes, int num_processes) {
    int curr_time = 0, min_bt, min_index;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    
    // scheduling processes in the order of their shortest burst time
    for (int i = 0; i < num_processes; i++) {
        min_bt = 9999, min_index = 0;
        for (int j = i; j < num_processes; j++) {
            if (processes[j].arrival_time <= curr_time && processes[j].burst_time < min_bt) {
                min_bt = processes[j].burst_time;
                min_index = j;
            }
        }
        curr_time += processes[min_index].burst_time;
        processes[min_index].turnaround_time = curr_time - processes[min_index].arrival_time;
        processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
        avg_turnaround_time += processes[min_index].turnaround_time;
        avg_waiting_time += processes[min_index].waiting_time;
        // swapping processes to move the scheduled process to the front for next iteration
        Process temp = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp;
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;
    
    // printing process details
    printf("\n\n");
    printf("SJF Scheduling:\n");
    printf("Process\t Arrival Time\t Burst Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
}

// Round-Robin Scheduling Algorithm
void round_robin_schedule(Process *processes, int num_processes) {
    int curr_time = 0, rem_processes = num_processes;
    int time_quantum = TIME_QUANTUM;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    
    // scheduling processes in the Round-Robin fashion with a fixed time quantum of 2
    while(rem_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].arrival_time <= curr_time) {
                    if (processes[i].remaining_time > time_quantum) {
                        curr_time += time_quantum;
                        processes[i].remaining_time -= time_quantum;
                    }
                    else {
                        curr_time += processes[i].remaining_time;
                        processes[i].turnaround_time = curr_time - processes[i].arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                        avg_turnaround_time += processes[i].turnaround_time;
                        avg_waiting_time += processes[i].waiting_time;
                        processes[i].remaining_time = 0;
                        rem_processes--;
                    }
                }
            }
        }
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;
    
    // printing process details
    printf("\n\n");
    printf("Round-Robin Scheduling (time quantum = %d):\n", time_quantum);
    printf("Process\t Arrival Time\t Burst Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
}