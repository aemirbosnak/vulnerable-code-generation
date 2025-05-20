//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;          // Process ID
    int burstTime;   // Burst Time
    int arrivalTime; // Arrival Time
    int waitingTime; // Waiting Time
    int turnAroundTime; // Turnaround Time
} Process;

// Function to sort processes by their arrival time
void sortProcessesByArrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(Process processes[], int n) {
    int time = 0;
    
    for (int i = 0; i < n; i++) {
        // If the CPU is idle, move to the next arrival time
        if (time < processes[i].arrivalTime) {
            time = processes[i].arrivalTime;
        }

        // Calculate waiting time
        processes[i].waitingTime = time - processes[i].arrivalTime;

        // Calculate turnaround time
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;

        // Update time
        time += processes[i].burstTime;
    }
}

// Function to calculate average times
void calculateAverageTimes(Process processes[], int n) {
    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
}

// Function to display process details
void displayProcessDetails(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
               processes[i].burstTime,
               processes[i].arrivalTime,
               processes[i].waitingTime,
               processes[i].turnAroundTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum processes limit of %d\n", MAX_PROCESSES);
        return 1;
    }

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign Process ID
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        printf("Enter Arrival Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrivalTime);
    }

    // Sort processes by arrival time
    sortProcessesByArrival(processes, n);

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n);

    // Display the process details
    displayProcessDetails(processes, n);

    // Calculate and display average times
    calculateAverageTimes(processes, n);

    return 0;
}