//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Struct for each process
typedef struct process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    bool completed;
} Process;

// Function to print gantt chart
void print_gantt_chart(Process processes[], int num_processes) {
    printf("\n\nGantt Chart\n-----------\n");
    int total_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_time += processes[i].burst_time;
    }
    int time = 0;
    printf("0");
    while (time < total_time) {
        int current_process = -1;
        int highest_priority = -1;
        for (int i = 0; i < num_processes; i++) {
            if (!processes[i].completed && processes[i].priority > highest_priority && processes[i].arrival_time <= time) {
                highest_priority = processes[i].priority;
                current_process = i;
            }
        }
        if (current_process == -1) {
            printf("--");
            time++;
            continue;
        }
        int end_time = time + 1;
        processes[current_process].burst_time--;
        if (processes[current_process].burst_time == 0) {
            processes[current_process].completed = true;
            end_time++;
        }
        printf("P%d%d", processes[current_process].id, end_time);
        time = end_time;
    }
    printf("\n\n");
}

// Function to calculate waiting and turnaround time for each process
void calculate_times(Process processes[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n\n", (float) total_turnaround_time / num_processes);
}

int main() {
    // Get number of processes from user
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    // Create array of processes
    Process processes[num_processes];

    // Get arrival time, burst time, and priority for each process from the user
    for (int i = 0; i < num_processes; i++) {
        printf("\nProcess %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].completed = false;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Apply non-preemptive priority scheduling algorithm
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        int current_process = -1;
        int highest_priority = -1;
        for (int j = 0; j < num_processes; j++) {
            if (!processes[j].completed && processes[j].priority > highest_priority && processes[j].arrival_time <= current_time) {
                highest_priority = processes[j].priority;
                current_process = j;
            }
        }
        if (current_process == -1) {
            continue;
        }
        processes[current_process].waiting_time = current_time - processes[current_process].arrival_time;
        current_time += processes[current_process].burst_time;
        processes[current_process].completed = true;
    }

    // Print gantt chart and calculate waiting and turnaround time for each process
    print_gantt_chart(processes, num_processes);
    calculate_times(processes, num_processes);

    return 0;
}