//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void sort_by_arrival_time(struct Process *processes, int num_processes);
void round_robin_scheduler(struct Process *processes, int num_processes, int quantum_time);
void print_process_details(struct Process *processes, int num_processes);

int main() {
    int num_processes, quantum_time;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter time quantum for Round Robin Scheduler: ");
    scanf("%d", &quantum_time);

    struct Process *processes = (struct Process*)malloc(num_processes * sizeof(struct Process));

    // Get input details for each process
    for(int i=0; i<num_processes; i++) {
        printf("Enter details for process %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i+1;
    }

    printf("\n");

    sort_by_arrival_time(processes, num_processes);
    round_robin_scheduler(processes, num_processes, quantum_time);
    print_process_details(processes, num_processes);

    return 0;
}

void sort_by_arrival_time(struct Process *processes, int num_processes) {
    int i, j;
    struct Process temp_process;
    for(i=0; i<num_processes-1; i++) {
        for(j=0; j<num_processes-i-1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                temp_process = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp_process;
            }
        }
    }
}

void round_robin_scheduler(struct Process *processes, int num_processes, int quantum_time) {
    int time_elapsed = 0;
    int completed_processes = 0;
    int i;
    while(completed_processes < num_processes) {
        for(i=0; i<num_processes; i++) {
            if(processes[i].remaining_time > 0) {
                if(processes[i].remaining_time <= quantum_time) {
                    time_elapsed += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = time_elapsed - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed_processes++;
                }
                else {
                    time_elapsed += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                }
            }
        }
    }
}
void print_process_details(struct Process *processes, int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("\nProcess Details\n");
    printf("Process ID   Arrival Time   Burst Time   Priority   Waiting Time   Turnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        printf("%9d %14d %12d %11d %15d %16d\n",
            processes[i].pid,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].priority,
            processes[i].waiting_time,
            processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;
    printf("Average Wait Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}