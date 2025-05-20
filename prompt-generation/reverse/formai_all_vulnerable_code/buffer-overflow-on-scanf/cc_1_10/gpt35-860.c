//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Declaration of process structure
typedef struct {
    int pid; // Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int completion_time; // Completion Time
    int turnaround_time; // Turnaround Time
    int waiting_time; // Waiting Time
    int response_time; // Response Time
    int remaining_time; // Remaining Time
} Process;

// Function to swap two processes
void swap(Process* a, Process* b) {
    Process t = *a;
    *a = *b;
    *b = t;
}

// Function to perform selection sort based on arrival time
void sortByArrivalTime(Process* processes, int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (processes[j].arrival_time < processes[min_idx].arrival_time)
                min_idx = j;
        swap(&processes[min_idx], &processes[i]);
    }
}

// Function to calculate waiting time of each process
void calculateWaitingTime(Process* processes, int n) {
    int i, j;
    processes[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        processes[i].waiting_time = 0;
        for (j = 0; j < i; j++)
            processes[i].waiting_time += processes[j].burst_time;

        processes[i].waiting_time -= processes[i].arrival_time;
    }
}

// Function to calculate turnaround time of each process
void calculateTurnaroundTime(Process* processes, int n) {
    int i;
    for (i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

// Function to calculate completion time of each process
void calculateCompletionTime(Process* processes, int n) {
    int i;
    processes[0].completion_time = processes[0].arrival_time + processes[0].burst_time;
    for (i = 1; i < n; i++)
        processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
}

// Function to calculate response time of each process
void calculateResponseTime(Process* processes, int n) {
    int i;
    for (i = 0; i < n; i++)
        processes[i].response_time = processes[i].waiting_time - processes[i].arrival_time;
}

// Function to perform Round Robin Scheduling
void performScheduling(Process* processes, int n, int quantum) {
    int i, j;
    int time = 0; // Current time
    int remaining_processes = n; // Number of remaining processes

    // Initialize remaining time of each process
    for (i = 0; i < n; i++)
        processes[i].remaining_time = processes[i].burst_time;

    // Loop until all processes are completed
    while (remaining_processes > 0) {
        // Traverse through all processes
        for (i = 0; i < n; i++) {
            // Check if process has arrived and still has remaining time
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                // If remaining time is less than quantum
                if (processes[i].remaining_time <= quantum) {
                    // Increment time by remaining time of process
                    time += processes[i].remaining_time;
                    // Set completion time of process
                    processes[i].completion_time = time;
                    // Decrease remaining processes count
                    remaining_processes--;
                    // Calculate waiting, turnaround and response time of process
                    processes[i].waiting_time = processes[i].completion_time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].response_time = processes[i].waiting_time;

                    // Set remaining time of process to 0
                    processes[i].remaining_time = 0;
                }
                else {
                    // Increment time by quantum
                    time += quantum;
                    // Decrease remaining time of process by quantum
                    processes[i].remaining_time -= quantum;
                }
            }
        }
    }
}

// Function to print details of each process
void printProcesses(Process* processes, int n) {
    int i;
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time, processes[i].response_time);
    }
}

// Driver function
int main() {
    int n, i, quantum = 2; // Quantum of time in round robin scheduling
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for processes
    Process* processes = (Process*)malloc(n * sizeof(Process));

    // Initialize process details randomly
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 8 + 1;
    }

    // Sort processes based on arrival time
    sortByArrivalTime(processes, n);

    // Perform Round Robin Scheduling
    performScheduling(processes, n, quantum);

    // Calculate waiting, turnaround and response time of each process
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    calculateResponseTime(processes, n);

    // Print details of each process
    printProcesses(processes, n);

    // Free memory
    free(processes);

    return 0;
}