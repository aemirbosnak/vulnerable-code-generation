//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
// A sample C program to demonstrate CPU Scheduling Algorithms
// in a Dennis Ritchie style.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process Structure
typedef struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    bool is_completed;
} Process;

// Function prototypes
void print_processes(Process[], int);
void first_come_first_serve(Process[], int);
void shortest_job_first(Process[], int);
void round_robin(Process[], int, int);

// Main function
int main() {
    int total_processes, quantum;

    // Reading input values from the user
    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    // Creating an array of processes and reading information
    // for each process from the user
    Process processes[total_processes];

    for (int i = 0; i < total_processes; i++) {
        processes[i].pid = i + 1;

        printf("Enter the arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].is_completed = false;
    }

    // Sorting processes according to arrival time
    for (int i = 0; i < total_processes - 1; i++) {
        for (int j = i + 1; j < total_processes; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Applying different CPU Scheduling algorithms
    printf("\n-- First Come First Serve --\n");
    first_come_first_serve(processes, total_processes);

    printf("\n-- Shortest Job First --\n");
    shortest_job_first(processes, total_processes);

    printf("\n-- Round Robin --\n");
    round_robin(processes, total_processes, quantum);

    return 0;
}

// Function to print details of all the processes
void print_processes(Process processes[], int total_processes) {
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");

    for (int i = 0; i < total_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time, processes[i].turn_around_time,
               processes[i].waiting_time);
    }
}

// Function to implement First Come First Serve (FCFS) Scheduling Algorithm
void first_come_first_serve(Process processes[], int total_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turn_around_time = 0;

    for (int i = 0; i < total_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turn_around_time += processes[i].turn_around_time;

        current_time = processes[i].completion_time;
    }

    printf("\nAverage Waiting Time: %.2f", (float) total_waiting_time / total_processes);
    printf("\nAverage Turn Around Time: %.2f", (float) total_turn_around_time / total_processes);

    print_processes(processes, total_processes);
}

// Function to implement Shortest Job First (SJF) Scheduling Algorithm
void shortest_job_first(Process processes[], int total_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turn_around_time = 0;
    int remaining_processes = total_processes;

    while (remaining_processes > 0) {
        int shortest_job_index = -1;
        int shortest_job_burst_time = 9999999;

        for (int i = 0; i < total_processes; i++) {
            if (!processes[i].is_completed && processes[i].arrival_time <= current_time &&
                processes[i].burst_time < shortest_job_burst_time) {
                shortest_job_index = i;
                shortest_job_burst_time = processes[i].burst_time;
            }
        }

        if (shortest_job_index == -1) {
            current_time++;
            continue;
        }

        processes[shortest_job_index].completion_time = current_time + processes[shortest_job_index].burst_time;
        processes[shortest_job_index].turn_around_time =
                processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].waiting_time =
                processes[shortest_job_index].turn_around_time - processes[shortest_job_index].burst_time;

        total_waiting_time += processes[shortest_job_index].waiting_time;
        total_turn_around_time += processes[shortest_job_index].turn_around_time;

        remaining_processes--;
        processes[shortest_job_index].is_completed = true;

        current_time = processes[shortest_job_index].completion_time;
    }

    printf("\nAverage Waiting Time: %.2f", (float) total_waiting_time / total_processes);
    printf("\nAverage Turn Around Time: %.2f", (float) total_turn_around_time / total_processes);

    print_processes(processes, total_processes);
}

// Function to implement Round Robin Scheduling Algorithm
void round_robin(Process processes[], int total_processes, int quantum) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turn_around_time = 0;
    int remaining_processes = total_processes;

    while (remaining_processes > 0) {
        for (int i = 0; i < total_processes; i++) {
            if (processes[i].is_completed) {
                continue;
            }

            if (processes[i].burst_time <= quantum) {
                current_time += processes[i].burst_time;
                processes[i].burst_time = 0;
            } else {
                current_time += quantum;
                processes[i].burst_time -= quantum;
            }

            if (processes[i].burst_time == 0) {
                processes[i].completion_time = current_time;
                processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;

                total_waiting_time += processes[i].waiting_time;
                total_turn_around_time += processes[i].turn_around_time;

                remaining_processes--;
                processes[i].is_completed = true;
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float) total_waiting_time / total_processes);
    printf("\nAverage Turn Around Time: %.2f", (float) total_turn_around_time / total_processes);

    print_processes(processes, total_processes);
}