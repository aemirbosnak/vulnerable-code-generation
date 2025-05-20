//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // Define the maximum number of processes
#define TIME_QUANTUM 4 // Define the time quantum for Round Robin Scheduling

typedef struct {
    int arrival_time; // Arrival time of process
    int burst_time; // Burst time of process
    int remaining_time; // Remaining time of process
    int turnaround_time; // Turnaround time of process
    int completion_time; // Completion time of process
    int waiting_time; // Waiting time of process
    int priority; // Priority of process
    int pid; // Process ID
} Process;

void swap(Process *p1, Process *p2) {
    Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(Process processes[], int n) { // Sort processes based on arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void fcfs(Process processes[], int n) { // First-Come-First-Serve Scheduling
    int current_time = 0;

    for(int i = 0; i < n; i++) {
        if(current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        current_time = processes[i].completion_time;
    }
}

void sjf(Process processes[], int n) { // Shortest-Job-First Scheduling
    int current_time = 0;

    for(int i = 0, remaining_processes = n; remaining_processes > 0; i++) {
        int next_process = -1, shortest_burst_time = 1000000; // Initialize variables

        for(int j = 0; j < n; j++) { // Find the next shortest job
            if(processes[j].arrival_time <= current_time && processes[j].remaining_time < shortest_burst_time && processes[j].remaining_time > 0) {
                next_process = j;
                shortest_burst_time = processes[j].remaining_time;
            }
        }

        if(next_process == -1) { // No process found that can be executed now
            current_time++;
            continue;
        }

        processes[next_process].remaining_time--;
        if(processes[next_process].remaining_time == 0) { // Current process is done executing
            processes[next_process].completion_time = current_time + 1;
            processes[next_process].turnaround_time = processes[next_process].completion_time - processes[next_process].arrival_time;
            processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;

            remaining_processes--;
        }

        current_time++;
    }
}

void priority_scheduling(Process processes[], int n) { // Priority Scheduling
    int current_time = 0;

    for(int i = 0, remaining_processes = n; remaining_processes > 0; i++) {
        int next_process = -1, highest_priority = -1; // Initialize variables

        for(int j = 0; j < n; j++) { // Find the next highest priority process
            if(processes[j].arrival_time <= current_time && processes[j].priority > highest_priority && processes[j].remaining_time > 0) {
                next_process = j;
                highest_priority = processes[j].priority;
            }
        }

        if(next_process == -1) { // No process found that can be executed now
            current_time++;
            continue;
        }

        processes[next_process].remaining_time--;
        if(processes[next_process].remaining_time == 0) { // Current process is done executing
            processes[next_process].completion_time = current_time + 1;
            processes[next_process].turnaround_time = processes[next_process].completion_time - processes[next_process].arrival_time;
            processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;

            remaining_processes--;
        }

        current_time++;
    }
}

void round_robin(Process processes[], int n) { // Round Robin Scheduling
    int current_time = 0;

    while(1) {
        int done = 1;

        for(int i = 0; i < n; i++) {
            if(processes[i].remaining_time > 0) {
                done = 0; // There are still processes pending
                if(processes[i].remaining_time > TIME_QUANTUM) {
                    current_time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                }
                else {
                    current_time += processes[i].remaining_time; // Finish the process
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
            }
        }

        if(done == 1) { // All processes done executing
            break;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) { // Input process details
        printf("\nEnter details of process %d:\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i+1;
    }

    sort(processes, n); // Sort processes based on arrival time

    fcfs(processes, n); // First-Come-First-Serve Scheduling

    printf("\nResults of First-Come-First-Serve Scheduling:\n");
    printf("PID\tAT\tBT\tPT\tCT\tTAT\tWT\n"); // Display results
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    for(int i = 0; i < n; i++) { // Reset process details for next scheduling algorithm
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    sjf(processes, n); // Shortest-Job-First Scheduling

    printf("\nResults of Shortest-Job-First Scheduling:\n");
    printf("PID\tAT\tBT\tPT\tCT\tTAT\tWT\n"); // Display results
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    for(int i = 0; i < n; i++) { // Reset process details for next scheduling algorithm
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    priority_scheduling(processes, n); // Priority Scheduling

    printf("\nResults of Priority Scheduling:\n");
    printf("PID\tAT\tBT\tPT\tCT\tTAT\tWT\n"); // Display results
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    for(int i = 0; i < n; i++) { // Reset process details for next scheduling algorithm
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    round_robin(processes, n); // Round Robin Scheduling

    printf("\nResults of Round Robin Scheduling:\n");
    printf("PID\tAT\tBT\tPT\tCT\tTAT\tWT\n"); // Display results
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}