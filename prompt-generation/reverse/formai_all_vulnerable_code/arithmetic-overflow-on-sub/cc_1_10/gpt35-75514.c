//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100 // maximum number of processes
#define MAX_TIME 100 // maximum running time for the algorithm

// Define process struct
typedef struct {
    int pid; // process id
    int burst_time; // burst time
    int arrival_time; // arrival time
    int waiting_time; // waiting time
    int turnaround_time; // turn around time
    int remaining_time; // remaining time
} process;

// Function to invoke FCFS CPU scheduling algorithm
void fcfs(process *proc_arr, int n);

// Function to invoke SJF CPU scheduling algorithm
void sjf(process *proc_arr, int n);

// Function to invoke SRTF CPU scheduling algorithm
void srtf(process *proc_arr, int n);

// Function to invoke Round Robin CPU scheduling algorithm
void rr(process *proc_arr, int n, int quantum);

int main() {
    int n_processes; // variable to store number of processes
    int quantum; // variable to store quantum time for round robin algorithm
    
    // Prompt user for inputs
    printf("Enter number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter quantum time for Round Robin Algorithm: ");
    scanf("%d", &quantum);
    
    // Allocate memory for array of processes
    process *proc_arr = (process*) malloc(sizeof(process) * n_processes);
    
    // Prompt user to input process details
    for (int i = 0; i < n_processes; i++) {
        printf("\nProcess %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &proc_arr[i].burst_time);
        printf("Enter arrival time: ");
        scanf("%d", &proc_arr[i].arrival_time);
        // Initialize remaining time to burst time
        proc_arr[i].remaining_time = proc_arr[i].burst_time;
        // Assign process id
        proc_arr[i].pid = i+1;
    }
    
    // Invoke FCFS algorithm
    printf("\nFCFS Algorithm:\n");
    fcfs(proc_arr, n_processes);
    
    // Invoke SJF algorithm
    printf("\nSJF Algorithm:\n");
    sjf(proc_arr, n_processes);
    
    // Invoke SRTF algorithm
    printf("\nSRTF Algorithm:\n");
    srtf(proc_arr, n_processes);
    
    // Invoke Round Robin algorithm
    printf("\nRound Robin Algorithm:\n");
    rr(proc_arr, n_processes, quantum);
    
    // Free allocated memory
    free(proc_arr);
    
    return 0;
}

void fcfs(process *proc_arr, int n) {
    int curr_time = 0; // variable to store current time
    float avg_waiting_time = 0; // variable to store average waiting time
    float avg_turnaround_time = 0; // variable to store average turn around time
    
    // Calculate waiting and turn around time for each process
    for (int i = 0; i < n; i++) {
        if (proc_arr[i].arrival_time > curr_time) {
            // Process has not arrived yet, wait for process to arrive
            curr_time = proc_arr[i].arrival_time;
        }
        proc_arr[i].waiting_time = curr_time - proc_arr[i].arrival_time;
        curr_time += proc_arr[i].burst_time;
        proc_arr[i].turnaround_time = curr_time - proc_arr[i].arrival_time;
        avg_waiting_time += proc_arr[i].waiting_time;
        avg_turnaround_time += proc_arr[i].turnaround_time;
    }
    
    // Calculate average waiting and turn around time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Display process details
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc_arr[i].pid, proc_arr[i].burst_time, proc_arr[i].arrival_time,
        proc_arr[i].waiting_time, proc_arr[i].turnaround_time);
    }
    
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turn around time: %.2f\n", avg_turnaround_time);
}

void sjf(process *proc_arr, int n) {
    int curr_time = 0; // variable to store current time
    float avg_waiting_time = 0; // variable to store average waiting time
    float avg_turnaround_time = 0; // variable to store average turn around time
    
    // Sort processes based on burst time
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc_arr[i].burst_time > proc_arr[j].burst_time) {
                // Swap the processes
                process temp = proc_arr[i];
                proc_arr[i] = proc_arr[j];
                proc_arr[j] = temp;
            }
        }
    }
    
    // Calculate waiting and turn around time for each process
    for (int i = 0; i < n; i++) {
        if (proc_arr[i].arrival_time > curr_time) {
            // Process has not arrived yet, wait for process to arrive
            curr_time = proc_arr[i].arrival_time;
        }
        proc_arr[i].waiting_time = curr_time - proc_arr[i].arrival_time;
        curr_time += proc_arr[i].burst_time;
        proc_arr[i].turnaround_time = curr_time - proc_arr[i].arrival_time;
        avg_waiting_time += proc_arr[i].waiting_time;
        avg_turnaround_time += proc_arr[i].turnaround_time;
    }
    
    // Calculate average waiting and turn around time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Display process details
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc_arr[i].pid, proc_arr[i].burst_time, proc_arr[i].arrival_time,
        proc_arr[i].waiting_time, proc_arr[i].turnaround_time);
    }
    
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turn around time: %.2f\n", avg_turnaround_time);
}

void srtf(process *proc_arr, int n) {
    int curr_time = 0; // variable to store current time
    int min_burst_time = 999; // variable to store minimum burst time
    int min_burst_index = -1; // variable to store index of process with minimum burst time
    int completed_processes = 0; // variable to store number of completed processes
    float avg_waiting_time = 0; // variable to store average waiting time
    float avg_turnaround_time = 0; // variable to store average turn around time
    
    // Calculate waiting and turn around time for each process
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (proc_arr[i].arrival_time <= curr_time && proc_arr[i].remaining_time > 0 && proc_arr[i].remaining_time < min_burst_time) {
                // Process with minimum burst time found
                min_burst_time = proc_arr[i].remaining_time;
                min_burst_index = i;
            }
        }
        
        if (min_burst_index == -1) {
            // No process with minimum burst time found, wait for next process
            curr_time++;
            continue;
        }
        
        // Calculate waiting and turn around time for the process
        if (proc_arr[min_burst_index].arrival_time > curr_time) {
            // Process has not arrived yet, wait for process to arrive
            curr_time = proc_arr[min_burst_index].arrival_time;
        }
        proc_arr[min_burst_index].waiting_time = curr_time - proc_arr[min_burst_index].arrival_time;
        curr_time++;
        proc_arr[min_burst_index].remaining_time--;
        if (proc_arr[min_burst_index].remaining_time == 0) {
            // Process has completed execution
            completed_processes++;
            proc_arr[min_burst_index].turnaround_time = curr_time - proc_arr[min_burst_index].arrival_time;
            avg_waiting_time += proc_arr[min_burst_index].waiting_time;
            avg_turnaround_time += proc_arr[min_burst_index].turnaround_time;
            // Reset minimum burst time variables
            min_burst_time = 999;
            min_burst_index = -1;
        }
    }
    
    // Calculate average waiting and turn around time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Display process details
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc_arr[i].pid, proc_arr[i].burst_time, proc_arr[i].arrival_time,
        proc_arr[i].waiting_time, proc_arr[i].turnaround_time);
    }
    
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turn around time: %.2f\n", avg_turnaround_time);
}

void rr(process *proc_arr, int n, int quantum) {
    int curr_time = 0; // variable to store current time
    int completed_processes = 0; // variable to store number of completed processes
    float avg_waiting_time = 0; // variable to store average waiting time
    float avg_turnaround_time = 0; // variable to store average turn around time
    int *remaining_time_arr = (int*) malloc(sizeof(int) * n); // array to keep track of remaining time for each process
    int *executed_time_arr = (int*) malloc(sizeof(int) * n); // array to keep track of executed time for each process
    
    // Initialize remaining time and executed time for each process
    for (int i = 0; i < n; i++) {
        remaining_time_arr[i] = proc_arr[i].burst_time;
        executed_time_arr[i] = 0;
    }
    
    // Run Round Robin algorithm
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time_arr[i] > 0) {
                if (remaining_time_arr[i] > quantum) {
                    // Process has remaining time more than quantum time
                    curr_time += quantum;
                    remaining_time_arr[i] -= quantum;
                    executed_time_arr[i] += quantum;
                }
                else {
                    // Process has remaining time less than or equal to quantum time
                    curr_time += remaining_time_arr[i];
                    executed_time_arr[i] += remaining_time_arr[i];
                    remaining_time_arr[i] = 0;
                    completed_processes++;
                    // Calculate waiting and turn around time for the process
                    proc_arr[i].waiting_time = curr_time - proc_arr[i].burst_time - proc_arr[i].arrival_time;
                    proc_arr[i].turnaround_time = curr_time - proc_arr[i].arrival_time;
                    avg_waiting_time += proc_arr[i].waiting_time;
                    avg_turnaround_time += proc_arr[i].turnaround_time;
                }
            }
        }
    }
    
    // Calculate average waiting and turn around time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Display process details
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc_arr[i].pid, proc_arr[i].burst_time, proc_arr[i].arrival_time,
        proc_arr[i].waiting_time, proc_arr[i].turnaround_time);
    }
    
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turn around time: %.2f\n", avg_turnaround_time);
    
    // Free allocated memory
    free(remaining_time_arr);
    free(executed_time_arr);
}