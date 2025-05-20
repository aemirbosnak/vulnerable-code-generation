//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

// Functions to sort processes based on arrival time
void sortProcesses(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrival_time > proc[j + 1].arrival_time) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void findWaitingAndTurnaroundTime(struct Process proc[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            proc[i].waiting_time = 0;
        } else {
            proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        }

        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

// Function to print the process details
void printProcesses(struct Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            proc[i].id, 
            proc[i].burst_time, 
            proc[i].arrival_time, 
            proc[i].waiting_time, 
            proc[i].turnaround_time);
    }
}

// Main scheduling function
void scheduleProcesses(struct Process processes[], int n) {
    sortProcesses(processes, n);
    findWaitingAndTurnaroundTime(processes, n);
    printProcesses(processes, n);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        processes[i].id = i + 1;  // Assigning Process ID
    }

    scheduleProcesses(processes, n);
    
    return 0;
}