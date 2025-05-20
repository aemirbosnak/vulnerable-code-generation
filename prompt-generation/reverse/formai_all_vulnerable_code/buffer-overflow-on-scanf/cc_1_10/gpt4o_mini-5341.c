//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 10
#define PROCESS_NAME_LENGTH 20

typedef struct {
    char name[PROCESS_NAME_LENGTH];
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void printProcesses(Process processes[], int n) {
    printf("\nCPU Scheduling Results:\n");
    printf("Process Name\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void simulateFCFS(Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        // Wait for the process to arrive
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
}

void simulateSJF(Process processes[], int n) { 
    int completed = 0, current_time = 0;
    int min_index;
    int min_burst_time;

    while (completed < n) {
        min_burst_time = 999999; // Assume a large value for the minimum burst time

        for (int j = 0; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time < min_burst_time) {
                min_index = j;
                min_burst_time = processes[j].burst_time;
            }
        }

        if (min_burst_time == 999999) {
            current_time++; // If no process is available, increment time
            continue;
        }

        processes[min_index].waiting_time = current_time - processes[min_index].arrival_time;
        processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
        current_time += processes[min_index].burst_time;
        completed++;
    }
}

void displayMenu() {
    printf("\n=== Cyberpunk CPU Scheduler ===\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice;

    srand(time(NULL));

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    // Initialize process data
    for (int i = 0; i < n; i++) {
        snprintf(processes[i].name, PROCESS_NAME_LENGTH, "Process_%02d", i+1);
        processes[i].burst_time = rand() % 10 + 1; // Random burst time from 1 to 10
        processes[i].arrival_time = rand() % 5; // Random arrival time from 0 to 4
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nRunning First-Come, First-Served (FCFS) Scheduling...\n");
                simulateFCFS(processes, n);
                printProcesses(processes, n);
                calculateTimes(processes, n);
                break;
            case 2:
                printf("\nRunning Shortest Job First (SJF) Scheduling...\n");
                simulateSJF(processes, n);
                printProcesses(processes, n);
                calculateTimes(processes, n);
                break;
            case 3:
                printf("Exiting the Cyberpunk CPU Scheduler...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        
    } while (choice != 3);

    return 0;
}