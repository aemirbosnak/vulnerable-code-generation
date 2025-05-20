//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Structure to represent a process
typedef struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

// Function to compare two processes based on arrival_time
int compare(const void *a, const void *b) {
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrival_time - processB->arrival_time;
}

// Function to simulate Round Robin CPU Scheduling
void round_robin(Process processes[], int n, int quantum) {
    int time = 0;
    bool done;
    
    // Queue implementation
    int front = 0, rear = 0;
    int queue[100];

    // Initialize remaining_time for each process
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Main scheduling loop
    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = false; // There is a pending process

                if (processes[i].arrival_time <= time) {
                    if (processes[i].remaining_time > quantum) {
                        time += quantum;
                        processes[i].remaining_time -= quantum;
                    } else {
                        time += processes[i].remaining_time;
                        processes[i].turnaround_time = time - processes[i].arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                        processes[i].remaining_time = 0;

                        printf("Process %d completed at time %d\n", processes[i].id, time);
                    }
                }
            }
        }

        // Break if all processes are done
        if (done) break;

        // Yield to next process
        sleep(1); // Simulating time lapse
    }
}

// Function to print results
void print_results(Process processes[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
               processes[i].burst_time, processes[i].arrival_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Welcome to the Futuristic CPU Scheduler!\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter time quantum for the Round Robin algorithm: ");
    scanf("%d", &quantum);

    // Sort processes based on arrival time
    qsort(processes, n, sizeof(Process), compare);

    // Call Round Robin Scheduling
    round_robin(processes, n, quantum);
    
    // Calculate waiting times and turnaround times for completion
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Print results
    print_results(processes, n);
    
    return 0;
}