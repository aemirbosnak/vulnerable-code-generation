//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_turnaround_time(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void fcfs(Process processes[], int n) {
    int current_time = 0;

    printf("\nFCFS Scheduling:\n");
    
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;

        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", 
                 processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0;
    int min_index, min_burst_time;

    printf("\nSJF Scheduling:\n");

    while (completed < n) {
        min_index = -1;
        min_burst_time = 10000; // Arbitrary large number to compare min

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && 
                processes[i].burst_time < min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
            continue;
        }
        
        processes[min_index].waiting_time = current_time - processes[min_index].arrival_time;
        current_time += processes[min_index].burst_time;
        processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
        processes[min_index].remaining_time = 0;
        completed++;
        
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", 
                 processes[min_index].id, processes[min_index].waiting_time, processes[min_index].turnaround_time);
    }
}

void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0, done = 0;

    printf("\nRound Robin Scheduling:\n");
    
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].arrival_time <= current_time) {
                    if (processes[i].remaining_time > quantum) {
                        current_time += quantum;
                        processes[i].remaining_time -= quantum;
                    } else {
                        current_time += processes[i].remaining_time;
                        processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                        processes[i].turnaround_time = current_time - processes[i].arrival_time;
                        processes[i].remaining_time = 0;
                        done++;
                        
                        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", 
                                 processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
                    }
                }
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // FCFS Scheduling
    fcfs(processes, n);
    
    // Reset waiting and turnaround times for next algorithm
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // SJF Scheduling
    sjf(processes, n);
    
    // Reset waiting and turnaround times for next algorithm
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Round Robin Scheduling
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    round_robin(processes, n, quantum);

    return 0;
}