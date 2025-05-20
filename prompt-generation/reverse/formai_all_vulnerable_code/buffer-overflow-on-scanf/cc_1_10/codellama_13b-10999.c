//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
    int start_time;
    int end_time;
};

void print_processes(struct process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: pid=%d, burst_time=%d, priority=%d, arrival_time=%d\n", i + 1, processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].arrival_time);
    }
}

void print_results(struct process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: turnaround_time=%d, waiting_time=%d\n", i + 1, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

void FCFS(struct process processes[], int num_processes) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time <= current_time) {
            processes[i].start_time = current_time;
            processes[i].end_time = current_time + processes[i].burst_time;
            current_time = processes[i].end_time;
        }
    }
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void SJF(struct process processes[], int num_processes) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time <= current_time) {
            processes[i].start_time = current_time;
            processes[i].end_time = current_time + processes[i].burst_time;
            current_time = processes[i].end_time;
        }
    }
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void RR(struct process processes[], int num_processes, int time_slice) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time <= current_time) {
            processes[i].start_time = current_time;
            processes[i].end_time = current_time + processes[i].burst_time;
            current_time = processes[i].end_time;
        }
    }
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter process %d information:\n", i + 1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
    }

    print_processes(processes, num_processes);

    FCFS(processes, num_processes);
    print_results(processes, num_processes);

    SJF(processes, num_processes);
    print_results(processes, num_processes);

    RR(processes, num_processes, 2);
    print_results(processes, num_processes);
}