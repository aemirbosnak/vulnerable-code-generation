//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>

// Process structure definition
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

// Function declarations
float calculate_average_turnaround_time(Process *processes, int num_processes);
float calculate_average_waiting_time(Process *processes, int num_processes);

// Shortest Job First (SJF) scheduling algorithm function
void sjf_scheduling(Process *processes, int num_processes) {
    // Sorting processes based on their burst time
    for(int i = 0; i < num_processes - 1; i++) {
        for(int j = i + 1; j < num_processes; j++) {
            if(processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int current_time = 0; // Current time, starting from 0
    for(int i = 0; i < num_processes; i++) {
        // Updating current time to the arrival time of the current process
        if(current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        // Assigning completion time, turnaround time and waiting time for the current process
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        // Updating current time to the completion time of the current process
        current_time = processes[i].completion_time;
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
        processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("\nAverage Turnaround Time: %.2f\n", calculate_average_turnaround_time(processes, num_processes));
    printf("Average Waiting Time: %.2f\n", calculate_average_waiting_time(processes, num_processes));
}

// Function to calculate average turnaround time of all processes
float calculate_average_turnaround_time(Process *processes, int num_processes) {
    int total_turnaround_time = 0;
    for(int i = 0; i < num_processes; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }
    float average_turnaround_time = (float)total_turnaround_time / (float)num_processes;
    return average_turnaround_time;
}

// Function to calculate average waiting time of all processes
float calculate_average_waiting_time(Process *processes, int num_processes) {
    int total_waiting_time = 0;
    for(int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    float average_waiting_time = (float)total_waiting_time / (float)num_processes;
    return average_waiting_time;
}

int main() {
    // Input
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    Process processes[num_processes];
    for(int i = 0; i < num_processes; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    // Shortest Job First (SJF) scheduling algorithm
    sjf_scheduling(processes, num_processes);

    return 0;
}