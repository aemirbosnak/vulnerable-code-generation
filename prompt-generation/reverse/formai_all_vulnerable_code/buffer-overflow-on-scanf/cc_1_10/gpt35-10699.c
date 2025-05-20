//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>

struct process {
    int pid;
    int burst_time;
    int wait_time;
    int arrival_time;
    int priority;
    int turnaround_time;
    int completed;
};

void fcfs(struct process *processes, int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].wait_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].wait_time + processes[i].burst_time;
        
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
        
        current_time += processes[i].burst_time;
    }
    
    printf("FCFS Algorithm Results:\n");
    printf("Average wait time: %f\n", (double) total_wait_time / n);
    printf("Average turnaround time: %f\n", (double) total_turnaround_time / n);
}

void sjf(struct process *processes, int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    int completed = 0;
    
    while (completed < n) {
        int shortest_index = -1;
        int shortest_burst_time = 1000000000;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completed == 0) {
                if (processes[i].burst_time < shortest_burst_time) {
                    shortest_burst_time = processes[i].burst_time;
                    shortest_index = i;
                }
            }
        }
        
        if (shortest_index != -1) {
            processes[shortest_index].wait_time = current_time - processes[shortest_index].arrival_time;
            processes[shortest_index].turnaround_time = processes[shortest_index].wait_time + processes[shortest_index].burst_time;
            
            total_wait_time += processes[shortest_index].wait_time;
            total_turnaround_time += processes[shortest_index].turnaround_time;
            
            current_time += processes[shortest_index].burst_time;
            processes[shortest_index].completed = 1;
            completed++;
        } else {
            current_time++;
        }
    }
    
    printf("SJF Algorithm Results:\n");
    printf("Average wait time: %f\n", (double) total_wait_time / n);
    printf("Average turnaround time: %f\n", (double) total_turnaround_time / n);
}

int main() {
    struct process processes[10];
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].completed = 0;
    }
    
    fcfs(processes, n);
    sjf(processes, n);
    
    return 0;
}