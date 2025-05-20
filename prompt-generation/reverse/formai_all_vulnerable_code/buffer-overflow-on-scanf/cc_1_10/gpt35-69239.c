//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Process structure
struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int completed;
};

// Function to execute the Round Robin algorithm
void round_robin(struct Process* processes, int n, int quantum) {
    int time = 0; // current time
    int completed = 0; // number of completed processes
    int* remaining_times = (int*) malloc(sizeof(int) * n); // array to store remaining times of each process
    int i;
    for (i = 0; i < n; i++) {
        remaining_times[i] = processes[i].burst_time;
    }
    // Execute processes until all are completed
    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (processes[i].completed) {
                continue;
            }
            // Execute process for quantum or remaining_time, whichever is smaller
            int execution_time = remaining_times[i] < quantum ? remaining_times[i] : quantum;
            remaining_times[i] -= execution_time;
            time += execution_time; // update current time
            if (remaining_times[i] == 0) {
                // Process is completed
                processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                processes[i].turnaround_time = time - processes[i].arrival_time;
                processes[i].completed = 1;
                completed++;
            }
        }
    }
    // Print results
    printf("Round Robin:\n");
    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
    free(remaining_times);
}

// Main function
int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process* processes = (struct Process*) malloc(sizeof(struct Process) * n);
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time and Arrival Time for Process %d: ", i+1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }
    printf("Enter Time Quantum for Round Robin: ");
    scanf("%d", &quantum);
    round_robin(processes, n, quantum);
    free(processes);
    return 0;
}