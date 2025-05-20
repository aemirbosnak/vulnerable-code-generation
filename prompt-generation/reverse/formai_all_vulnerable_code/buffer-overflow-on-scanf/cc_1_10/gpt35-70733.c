//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Structure for Process Control Block
typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} PCB;

// Function Declarations
void FCFS(PCB *processes, int n);
void SJF(PCB *processes, int n);
void RR(PCB *processes, int n, int time_quantum);

int main() {
    int n; // number of processes
    int choice; // scheduling algorithm choice
    int time_quantum; // time quantum for Round Robin
    PCB processes[MAX_PROCESSES];
    
    // Ask user for input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Get process details from user
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        processes[i].completed = false;
    }
    
    // Ask user for scheduling algorithm choice
    printf("Choose a scheduling algorithm:\n");
    printf("1. First Come First Serve(FCFS)\n");
    printf("2. Shortest Job First(SJF)\n");
    printf("3. Round Robin(RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // Use selected algorithm to schedule processes
    switch(choice) {
        case 1:
            FCFS(processes, n);
            break;
        case 2:
            SJF(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &time_quantum);
            RR(processes, n, time_quantum);
            break;
        default:
            printf("Invalid choice, try again.\n");
            break;
    }
    
    return 0;
}

void FCFS(PCB *processes, int n) {
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        // Wait for process to arrive
        current_time = (current_time < processes[i].arrival_time) ? processes[i].arrival_time : current_time;
        // Calculate waiting time
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        // Calculate turnaround time
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        // Update current time
        current_time += processes[i].burst_time;
        // Mark process as completed
        processes[i].completed = true;
    }
    
    // Print results
    printf("FCFS Scheduling Results:\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void SJF(PCB *processes, int n) {
    int current_time = 0;
    int total_time = 0;
    int min_index;
    bool found;
    
    while (total_time < n) {
        min_index = -1;
        found = false;
        // Find shortest remaining time process
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time && (!found || processes[i].burst_time < processes[min_index].burst_time)) {
                min_index = i;
                found = true;
            }
        }
        
        if (min_index == -1) {
            current_time++;
        } else {
            // Update waiting time and turnaround time
            processes[min_index].waiting_time = current_time - processes[min_index].arrival_time;
            processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
            // Update current time and total time
            current_time += processes[min_index].burst_time;
            total_time++;
            // Mark process as completed
            processes[min_index].completed = true;
        }
    }
    
    // Print results
    printf("SJF Scheduling Results:\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void RR(PCB *processes, int n, int time_quantum) {
    int current_time = 0;
    int total_time = 0;
    int remaining_times[MAX_PROCESSES];
    int start_times[MAX_PROCESSES];
    bool done;
    
    // Initialize remaining times array
    for (int i = 0; i < n; i++) {
        remaining_times[i] = processes[i].burst_time;
    }
    
    while (total_time < n) {
        done = true; // Assume all processes are completed
        
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time) {
                done = false;
                start_times[i] = current_time; // Record start time of process
                if (remaining_times[i] > time_quantum) {
                    // Process execution will exceed time quantum, execute for time quantum
                    remaining_times[i] -= time_quantum;
                    current_time += time_quantum;
                } else {
                    // Process execution will not exceed time quantum, execute for remaining time
                    current_time += remaining_times[i];
                    remaining_times[i] = 0;
                    // Update waiting time and turnaround time
                    processes[i].waiting_time = start_times[i] - processes[i].arrival_time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    // Mark process as completed
                    processes[i].completed = true;
                    total_time++;
                }
            }
        }
        
        if (done) {
            current_time++;
        }
    }
    
    // Print results
    printf("Round Robin Scheduling Results (time quantum: %d):\n", time_quantum);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}