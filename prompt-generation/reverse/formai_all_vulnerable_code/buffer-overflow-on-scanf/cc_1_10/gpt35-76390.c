//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>

// Struct for storing process information
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int priority;
};

// Function to swap two processes
void SwapProcesses(struct Process* process1, struct Process* process2) {
    struct Process temp = *process1;
    *process1 = *process2;
    *process2 = temp;
}

// Function to perform bubble sort on an array of processes based on their arrival time
void BubbleSort(struct Process processes[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                SwapProcesses(&processes[j], &processes[j+1]);
            }
        }
    }
}

// Function to perform round robin scheduling on an array of processes
void RoundRobin(struct Process processes[], int n, int quantum_time) {
    int current_time = 0;
    int remaining_burst_time[n];

    // Initializing remaining burst time for each process
    for(int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // Running the loop until all processes are completed
    while(1) {
        int completed_processes = 1;

        for(int i = 0; i < n; i++) {
            if(remaining_burst_time[i] > 0) {
                completed_processes = 0;

                // If remaining burst time is greater than quantum time
                if(remaining_burst_time[i] > quantum_time) {
                    current_time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                }
                // If remaining burst time is less than or equal to quantum time
                else {
                    current_time += remaining_burst_time[i];
                    processes[i].completion_time = current_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }

        // If all processes are completed, break the loop
        if(completed_processes == 1) {
            break;
        }
    }
}

// Function to calculate turnaround time and waiting time for each process
void CalculateTime(struct Process processes[], int n) {
    for(int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// Function to display the process information
void DisplayProcesses(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time,
            processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n;
    int quantum_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for(int i = 0; i < n; i++) {
        processes[i].process_id = i+1;

        printf("Enter the arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the priority for process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }

    printf("Enter the quantum time for the round robin scheduling: ");
    scanf("%d", &quantum_time);

    BubbleSort(processes, n);

    RoundRobin(processes, n, quantum_time);

    CalculateTime(processes, n);

    DisplayProcesses(processes, n);
}