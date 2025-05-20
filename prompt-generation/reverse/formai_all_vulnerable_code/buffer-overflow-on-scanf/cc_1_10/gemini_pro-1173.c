//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int priority;        // Priority
    int remaining_time; // Remaining time
    int waiting_time;    // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Comparison function for sorting processes by arrival time
int compare_arrival_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Comparison function for sorting processes by priority
int compare_priority(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->priority - p2->priority;
}

// Scheduling algorithm
void scheduling_algorithm(Process *processes, int n) {
    // Sort processes by arrival time
    qsort(processes, n, sizeof(Process), compare_arrival_time);

    // Initialize variables
    int current_time = 0;
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Scheduling loop
    while (completed_processes < n) {
        // Find the next process that can be executed
        int next_process_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (next_process_index == -1 || processes[i].priority > processes[next_process_index].priority) {
                    next_process_index = i;
                }
            }
        }

        // If no process can be executed, increment the current time
        if (next_process_index == -1) {
            current_time++;
            continue;
        }

        // Execute the next process
        Process *process = &processes[next_process_index];
        process->remaining_time--;
        current_time++;

        // Update waiting time and turnaround time
        process->waiting_time = current_time - process->arrival_time - process->burst_time;
        process->turnaround_time = current_time - process->arrival_time;

        // If the process has finished executing, increment the completed processes count and update the total waiting and turnaround times
        if (process->remaining_time == 0) {
            completed_processes++;
            total_waiting_time += process->waiting_time;
            total_turnaround_time += process->turnaround_time;
        }
    }

    // Print the results
    printf("Scheduling Algorithm Results:\n");
    printf("-----------------------------------------\n");
    printf("Process | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-7d | %-12d | %-10d | %-8d | %-13d | %-16d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("-----------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    // Get the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    Process processes[n];

    // Get the details of each process
    for (int i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Sort processes by arrival time
    qsort(processes, n, sizeof(Process), compare_arrival_time);

    // Call the scheduling algorithm
    scheduling_algorithm(processes, n);

    return 0;
}