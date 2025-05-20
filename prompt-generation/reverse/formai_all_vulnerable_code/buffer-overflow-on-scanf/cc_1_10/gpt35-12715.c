//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

// Structure to hold process information
typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to sort an array of processes based on burst time (SJF)
void sjf_sort(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                // Swap processes
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate completion time, waiting time, and turnaround time for each process
void calculate_times(Process p[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Calculate completion time
        p[i].completion_time = current_time + p[i].burst_time;
        current_time = p[i].completion_time;
        // Calculate waiting time and turnaround time
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process p[n];
    // Get process information from user
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
    }
    // Sort processes based on burst time (SJF)
    sjf_sort(p, n);
    // Calculate completion time, waiting time, and turnaround time for each process
    calculate_times(p, n);
    // Print results
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }
    return 0;
}