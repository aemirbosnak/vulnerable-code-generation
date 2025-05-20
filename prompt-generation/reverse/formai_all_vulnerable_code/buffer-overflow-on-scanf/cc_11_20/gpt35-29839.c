//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    bool is_completed;
} Process;

int main() {
    int num_processes, i, j, time_quantum, current_time = 0, completed_processes = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    Process processes[num_processes];
    
    for (i = 0; i < num_processes; i++) {
        printf("\nEnter details for Process %d:\n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].is_completed = false;
    }
    
    printf("\nEnter time quantum: ");
    scanf("%d", &time_quantum);
    
    while (completed_processes < num_processes) {
        bool is_process_completed = true;
        
        for (i = 0; i < num_processes; i++) {
            if (processes[i].is_completed)
                continue;
            
            int remaining_time = processes[i].burst_time;
            
            if (remaining_time > time_quantum)
                remaining_time = time_quantum;
            
            processes[i].burst_time -= remaining_time;
            current_time += remaining_time;
        
            if (processes[i].burst_time == 0) {
                processes[i].completion_time = current_time;
                processes[i].waiting_time = processes[i].completion_time - processes[i].arrival_time - processes[i].start_time;
                if (processes[i].waiting_time < 0)
                    processes[i].waiting_time = 0;
                processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                processes[i].is_completed = true;
                completed_processes++;
            }
            else {
                is_process_completed = false;
            }
            
            processes[i].start_time = current_time;
        }
        
        if (is_process_completed)
            break;
    }
    
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].pid, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time/num_processes);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time/num_processes);
    
    return 0;
}