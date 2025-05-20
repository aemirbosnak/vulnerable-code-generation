//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to sort processes based on arrival time
void sortProcesses(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to find the waiting time for the processes using FCFS
void findWaitingTime(Process processes[], int n) {
    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

// Function to calculate turnaround time
void findTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// Function to calculate average times
void calculateAverageTimes(Process processes[], int n) {
    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);

    float total_waiting_time = 0.0, total_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage waiting time: %.2f\n", total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", total_turnaround_time / n);
}

// Function to display the resulting scheduling order
void displaySchedule(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                processes[i].arrival_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        processes[i].id = i + 1; // Process IDs start from 1
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    // Sort the processes based on arrival time
    sortProcesses(processes, n);
    
    // Calculate and display average waiting and turnaround times
    calculateAverageTimes(processes, n);
    
    // Display the results
    displaySchedule(processes, n);

    return 0;
}