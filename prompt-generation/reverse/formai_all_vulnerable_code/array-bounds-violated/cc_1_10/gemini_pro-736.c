//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int process_id;
} Process;

// Function to compare processes based on their arrival times
int compare_arrival_times(const void *a, const void *b) {
    const Process *process1 = (const Process *)a;
    const Process *process2 = (const Process *)b;
    return process1->arrival_time - process2->arrival_time;
}

// Function to compare processes based on their priorities
int compare_priorities(const void *a, const void *b) {
    const Process *process1 = (const Process *)a;
    const Process *process2 = (const Process *)b;
    return process1->priority - process2->priority;
}

// Function to simulate the Shortest Job First (SJF) scheduling algorithm
void sjf(Process *processes, int num_processes) {
    // Sort the processes by their arrival times
    qsort(processes, num_processes, sizeof(Process), compare_arrival_times);

    // Initialize the current time to the arrival time of the first process
    int current_time = processes[0].arrival_time;

    // Initialize the total waiting time and turnaround time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Iterate over the processes
    for (int i = 0; i < num_processes; i++) {
        // Calculate the waiting time for the current process
        int waiting_time = current_time - processes[i].arrival_time;

        // Update the total waiting time
        total_waiting_time += waiting_time;

        // Calculate the turnaround time for the current process
        int turnaround_time = waiting_time + processes[i].burst_time;

        // Update the total turnaround time
        total_turnaround_time += turnaround_time;

        // Update the current time
        current_time += processes[i].burst_time;

        // Print the details of the current process
        printf("Process %d: ", processes[i].process_id);
        printf("Waiting time: %d\n", waiting_time);
        printf("Turnaround time: %d\n\n", turnaround_time);
    }

    // Calculate the average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;

    // Print the average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Function to simulate the Priority Scheduling (PS) scheduling algorithm
void ps(Process *processes, int num_processes) {
    // Sort the processes by their priorities
    qsort(processes, num_processes, sizeof(Process), compare_priorities);

    // Initialize the current time to the arrival time of the first process
    int current_time = processes[0].arrival_time;

    // Initialize the total waiting time and turnaround time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Iterate over the processes
    for (int i = 0; i < num_processes; i++) {
        // Calculate the waiting time for the current process
        int waiting_time = current_time - processes[i].arrival_time;

        // Update the total waiting time
        total_waiting_time += waiting_time;

        // Calculate the turnaround time for the current process
        int turnaround_time = waiting_time + processes[i].burst_time;

        // Update the total turnaround time
        total_turnaround_time += turnaround_time;

        // Update the current time
        current_time += processes[i].burst_time;

        // Print the details of the current process
        printf("Process %d: ", processes[i].process_id);
        printf("Waiting time: %d\n", waiting_time);
        printf("Turnaround time: %d\n\n", turnaround_time);
    }

    // Calculate the average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;

    // Print the average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Function to simulate the Round Robin (RR) scheduling algorithm
void rr(Process *processes, int num_processes, int quantum) {
    // Initialize the current time to the arrival time of the first process
    int current_time = processes[0].arrival_time;

    // Initialize the total waiting time and turnaround time
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Initialize the queue of processes
    int queue[num_processes];
    int front = 0;
    int rear = 0;

    // Iterate over the processes
    for (int i = 0; i < num_processes; i++) {
        // Enqueue the process into the queue
        queue[rear++] = i;

        // Update the remaining time for the process
        processes[i].remaining_time = processes[i].burst_time;
    }

    // While the queue is not empty
    while (front != rear) {
        // Get the current process from the queue
        int process_index = queue[front++];

        // If the process has finished executing
        if (processes[process_index].remaining_time == 0) {
            // Calculate the waiting time for the process
            int waiting_time = current_time - processes[process_index].arrival_time;

            // Update the total waiting time
            total_waiting_time += waiting_time;

            // Calculate the turnaround time for the process
            int turnaround_time = waiting_time + processes[process_index].burst_time;

            // Update the total turnaround time
            total_turnaround_time += turnaround_time;

            // Print the details of the current process
            printf("Process %d: ", processes[process_index].process_id);
            printf("Waiting time: %d\n", waiting_time);
            printf("Turnaround time: %d\n\n", turnaround_time);
        } else {
            // Execute the process for the quantum time
            if (processes[process_index].remaining_time > quantum) {
                processes[process_index].remaining_time -= quantum;
                current_time += quantum;
            } else {
                current_time += processes[process_index].remaining_time;
                processes[process_index].remaining_time = 0;
            }

            // Enqueue the process back into the queue
            queue[rear++] = process_index;
        }
    }

    // Calculate the average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;

    // Print the average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main() {
    // Initialize the processes
    Process processes[] = {
        {0, 5, 5, 1, 1},
        {1, 2, 2, 3, 2},
        {2, 3, 3, 2, 3},
        {3, 1, 1, 1, 4},
        {4, 6, 6, 4, 5}
    };

    // Get the number of processes
    int num_processes = sizeof(processes) / sizeof(Process);

    // Run the SJF scheduling algorithm
    printf("SJF Scheduling Algorithm:\n");
    sjf(processes, num_processes);
    printf("\n");

    // Run the PS scheduling algorithm
    printf("PS Scheduling Algorithm:\n");
    ps(processes, num_processes);
    printf("\n");

    // Run the RR scheduling algorithm
    printf("RR Scheduling Algorithm:\n");
    rr(processes, num_processes, 2);
    printf("\n");

    return 0;
}