//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct process {
    int pid; // Process ID
    int burst_time; // Burst time of process
    int priority; // Priority of process
} process;

// Global Variables
int no_of_processes = 0;
process *process_list;

// Function to output the results of the scheduling algorithm
void output_results(int *new_order, int *completion_time, int *turnaround_time, int *waiting_time, float avg_turnaround_time, float avg_waiting_time) {
    printf("Result of Scheduling Algorithm:\n");
    printf("PID\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<no_of_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process_list[new_order[i]].pid, process_list[new_order[i]].burst_time, process_list[new_order[i]].priority, completion_time[new_order[i]], turnaround_time[new_order[i]], waiting_time[new_order[i]]);
    }
    printf("\nAverage Turnaround Time: %.2f\nAverage Waiting Time: %.2f", avg_turnaround_time, avg_waiting_time);
}

// Function for First-Come First-Serve (FCFS) scheduling algorithm
void fcfs() {
    // Initialize variables
    int new_order[no_of_processes];
    int completion_time[no_of_processes];
    int turnaround_time[no_of_processes];
    int waiting_time[no_of_processes];
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;

    // Set the new order of process as it is
    for(int i=0; i<no_of_processes; i++) {
        new_order[i] = i;
    }

    // Calculate Completion Time, Turnaround Time and Waiting Time
    int time = 0;
    for(int i=0; i<no_of_processes; i++) {
        if(time < process_list[new_order[i]].priority) { // Check if any processes arrived earlier than expected
            time = process_list[new_order[i]].priority; // If so, update the time
        }
        completion_time[new_order[i]] = time + process_list[new_order[i]].burst_time;
        turnaround_time[new_order[i]] = completion_time[new_order[i]] - process_list[new_order[i]].priority;
        waiting_time[new_order[i]] = turnaround_time[new_order[i]] - process_list[new_order[i]].burst_time;
        time = completion_time[new_order[i]];
        total_turnaround_time += turnaround_time[new_order[i]];
        total_waiting_time += waiting_time[new_order[i]];
    }

    // Calculate average turnaround time and average waiting time
    float avg_turnaround_time = total_turnaround_time/no_of_processes;
    float avg_waiting_time = total_waiting_time/no_of_processes;

    // Output results
    output_results(new_order, completion_time, turnaround_time, waiting_time, avg_turnaround_time, avg_waiting_time);
}

// Function for Round Robin (RR) scheduling algorithm
void rr(int quantum) {
    // Initialize variables
    int new_order[no_of_processes];
    int completion_time[no_of_processes];
    int turnaround_time[no_of_processes];
    int waiting_time[no_of_processes];
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;
    int remaining_burst_time[no_of_processes];
    int time = 0;
    int flag = 0; // Flag variable to check if any process was executed in a pass

    // Set the new order of process as it is
    for(int i=0; i<no_of_processes; i++) {
        new_order[i] = i;
        remaining_burst_time[i] = process_list[new_order[i]].burst_time;
    }

    // Start the RR scheduling algorithm
    while(1) {
        flag = 0;
        for(int i=0; i<no_of_processes; i++) {
            if(remaining_burst_time[new_order[i]] > 0) { // Check if process still needs to be executed
                if(remaining_burst_time[new_order[i]] > quantum) { // Check if process needs full quantum to be executed
                    time += quantum; // Add quantum time to the clock
                    remaining_burst_time[new_order[i]] -= quantum; // Update remaining burst time
                }
                else {
                    time += remaining_burst_time[new_order[i]]; // Add remaining burst time to the clock
                    completion_time[new_order[i]] = time;
                    turnaround_time[new_order[i]] = completion_time[new_order[i]] - process_list[new_order[i]].priority;
                    waiting_time[new_order[i]] = turnaround_time[new_order[i]] - process_list[new_order[i]].burst_time;
                    remaining_burst_time[new_order[i]] = 0;
                    total_turnaround_time += turnaround_time[new_order[i]];
                    total_waiting_time += waiting_time[new_order[i]];
                    flag = 1;
                }
            }
        }
        if(flag == 0) { // Check if all processes have been executed
            break;
        }
    }

    // Calculate average turnaround time and average waiting time
    float avg_turnaround_time = total_turnaround_time/no_of_processes;
    float avg_waiting_time = total_waiting_time/no_of_processes;

    // Output results
    output_results(new_order, completion_time, turnaround_time, waiting_time, avg_turnaround_time, avg_waiting_time);
}

int main() {
    // Take the input of the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);

    // Allocate memory for process list
    process_list = (process*) malloc(no_of_processes*sizeof(process));

    // Take the input of processes
    printf("Enter the details of each process: (PID, Burst Time, Priority)\n");
    for(int i=0; i<no_of_processes; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &process_list[i].pid, &process_list[i].burst_time, &process_list[i].priority);
    }

    // Take the input of the desired scheduling algorithm
    int choice = -1;
    while(choice != 0) {
        printf("\n=== Scheduling Algorithm ===\n");
        printf("1. First-Come First-Serve (FCFS)\n");
        printf("2. Round Robin (RR)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                fcfs();
                break;
            case 2:
                {
                    int quantum = -1;
                    while(quantum < 1) {
                        printf("Enter time quantum: ");
                        scanf("%d", &quantum);
                    }
                    rr(quantum);
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Free memory
    free(process_list);

    return 0;
}