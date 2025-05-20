//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define TIME_QUANTUM 4

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void first_come_first_served(Process processes[], int n) {
    printf("\nExecuting FCFS Scheduling:\n");
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        printf("Process %d executed for %d time units.\n", processes[i].id, processes[i].burst_time);
        total_waiting_time += (i > 0) ? (total_turnaround_time + processes[i-1].burst_time) : 0;
        total_turnaround_time += processes[i].burst_time;
    }

    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
}

void shortest_job_next(Process processes[], int n) {
    printf("\nExecuting SJF Scheduling:\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Process %d executed for %d time units.\n", processes[i].id, processes[i].burst_time);
        total_waiting_time += (i > 0) ? (total_turnaround_time + processes[i-1].burst_time) : 0;
        total_turnaround_time += processes[i].burst_time;
    }

    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
}

void round_robin(Process processes[], int n, int time_quantum) {
    printf("\nExecuting Round Robin Scheduling:\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    int completed = 0, time = 0;
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                // Calculate time for this round
                int time_slice = (processes[i].remaining_time > time_quantum) ? time_quantum : processes[i].remaining_time;
                printf("Process %d executed for %d time units.\n", processes[i].id, time_slice);
                
                time += time_slice;
                processes[i].remaining_time -= time_slice;
                
                if (processes[i].remaining_time == 0) {
                    completed++;
                    total_turnaround_time += time;
                    total_waiting_time += (time - processes[i].burst_time);
                }
            }
        }
    }

    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
}

int main() {
    int n, choice;
    Process processes[MAX_PROCESSES];
    
    printf("Welcome to the CPU Scheduling Simulator!\n");
    printf("How many processes do you want to simulate? (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First-Come-First-Served\n");
    printf("2. Shortest Job Next\n");
    printf("3. Round Robin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            first_come_first_served(processes, n);
            break;
        case 2:
            shortest_job_next(processes, n);
            break;
        case 3:
            round_robin(processes, n, TIME_QUANTUM);
            break;
        default:
            printf("Invalid choice. Please try again!\n");
            break;
    }
    
    printf("Thank you for using the CPU Scheduling Simulator!\n");
    return 0;
}