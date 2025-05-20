//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_SLICE 2

struct process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void FCFS(struct process *processes, int n);
void SJF(struct process *processes, int n);
void RR(struct process *processes, int n);

int main() {
    int i, n;
    struct process processes[MAX_PROCESSES];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    FCFS(processes, n);
    SJF(processes, n);
    RR(processes, n);
    
    return 0;
}

void FCFS(struct process *processes, int n) {
    int i, current_time = 0;
    float average_waiting_time = 0, average_turnaround_time = 0;
    
    for (i = 0; i < n; i++) {
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        average_waiting_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("\nFirst-Come, First-Served Algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

void SJF(struct process *processes, int n) {
    int i, current_time = 0, completed_processes = 0, shortest_job_index;
    float average_waiting_time = 0, average_turnaround_time = 0;
    
    while (completed_processes < n) {
        shortest_job_index = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_job_index == -1 || processes[i].remaining_time < processes[shortest_job_index].remaining_time) {
                    shortest_job_index = i;
                }
            }
        }
        if (shortest_job_index == -1) {
            current_time++;
        }
        else {
            processes[shortest_job_index].remaining_time--;
            current_time++;
            if (processes[shortest_job_index].remaining_time == 0) {
                processes[shortest_job_index].completion_time = current_time;
                processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;
                processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
                average_waiting_time += processes[shortest_job_index].waiting_time;
                average_turnaround_time += processes[shortest_job_index].turnaround_time;
                completed_processes++;
            }
        }
    }
    
    printf("\nShortest Job First Algorithm\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

void RR(struct process *processes, int n) {
    int i, current_time = 0, completed_processes = 0, remaining_processes = n;
    float average_waiting_time = 0, average_turnaround_time = 0;
    
    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= TIME_SLICE) {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    average_waiting_time += processes[i].waiting_time;
                    average_turnaround_time += processes[i].turnaround_time;
                    completed_processes++;
                    remaining_processes--;
                }
                else {
                    current_time += TIME_SLICE;
                    processes[i].remaining_time -= TIME_SLICE;
                }
            }
        }
    }
    
    printf("\nRound Robin Algorithm with Time Quantum = %d\n", TIME_SLICE);
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}