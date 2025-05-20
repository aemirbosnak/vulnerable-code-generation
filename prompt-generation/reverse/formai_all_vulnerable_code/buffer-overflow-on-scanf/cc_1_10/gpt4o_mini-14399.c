//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define QUANTUM 3

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

// Function to find the waiting time for each process
void findWaitingTime(struct Process processes[], int n, int bt[], int wt[], int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = bt[i];

    int t = 0; // Current time
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false; // There's a process left to schedule
                if (remaining_time[i] > quantum) {
                    t += quantum; // Increase time by the quantum
                    remaining_time[i] -= quantum; // Decrease remaining time
                } else {
                    t = t + remaining_time[i]; // Add remaining time to current time
                    wt[i] = t - bt[i]; // Calculate waiting time
                    remaining_time[i] = 0; // Process completed
                }
            }
        }
        if (done == true) break; // If all processes are done, exit the loop
    }
}

// Function to calculate turnaround time for each process
void findTurnAroundTime(struct Process processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(struct Process processes[], int n) {
    int bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES];

    // Fill the burst times from the process structure
    for (int i = 0; i < n; i++)
        bt[i] = processes[i].burst_time;

    findWaitingTime(processes, n, bt, wt, QUANTUM); // Find waiting time
    findTurnAroundTime(processes, n, bt, wt, tat); // Find turnaround time

    // Print results joyfully!
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, bt[i], wt[i], tat[i]);

    // Calculate and print average waiting time and turnaround time
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    // Initialize happiness with a big smile!
    printf("✨ Welcome to the Happy Round Robin CPU Scheduler! ✨\n");

    int n;

    // Input the number of processes
    printf("\nPlease enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if(n > MAX_PROCESSES || n <= 0) {
        printf("😢 Please enter a valid number of processes (1 - %d).\n", MAX_PROCESSES);
        return 1;
    }

    struct Process processes[MAX_PROCESSES];

    // Gather burst times from the user
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    // Hooray! Time to compute averages and celebrate!
    findavgTime(processes, n);

    printf("\n🎉 Thank you for using the Happy Round Robin CPU Scheduler! 🎉\n");
    
    return 0;
}