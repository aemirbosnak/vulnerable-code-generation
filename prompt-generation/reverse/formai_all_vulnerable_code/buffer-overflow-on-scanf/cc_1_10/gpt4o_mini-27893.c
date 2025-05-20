//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;        // Process ID
    int burst;     // Burst time
    int arrival;   // Arrival time
    int waiting;   // Waiting time
    int turnaround; // Turnaround time
} Process;

// Function to calculate average waiting time and turnaround time
void calculateTimes(Process processes[], int n) {
    float avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;

    for(int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].burst + processes[i].waiting;
        avgWaitingTime += processes[i].waiting;
        avgTurnaroundTime += processes[i].turnaround;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

void sortProcessesByArrival(Process processes[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(processes[i].arrival > processes[j].arrival) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void firstComeFirstServe(Process processes[], int n) {
    int totalWaitingTime = 0;

    processes[0].waiting = 0; // First process has waiting time 0
    for(int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
        totalWaitingTime += processes[i].waiting;
    }

    calculateTimes(processes, n);
}

void shortestJobFirst(Process processes[], int n) {
    int totalWaitingTime = 0;

    // Sort the processes based on burst time and arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((processes[i].burst > processes[j].burst && processes[i].arrival <= processes[j].arrival) ||
                (processes[i].arrival > processes[j].arrival)) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    processes[0].waiting = 0; // First job has 0 waiting time

    for(int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
    }

    calculateTimes(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Process ID starts from 1
        printf("Enter Burst Time and Arrival Time for Process %d (format: burst arrival): ", i + 1);
        scanf("%d %d", &processes[i].burst, &processes[i].arrival);
        processes[i].waiting = 0; // Initialize waiting time to 0
    }

    sortProcessesByArrival(processes, n);

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n--- First Come First Serve Scheduling ---\n");
            firstComeFirstServe(processes, n);
            break;
        case 2:
            printf("\n--- Shortest Job First Scheduling ---\n");
            shortestJobFirst(processes, n);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            exit(1);
    }

    return 0;
}