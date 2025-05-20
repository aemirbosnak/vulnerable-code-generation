//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>

// Defining the struct for Process
struct process {
    int pid; // Process ID
    int burst_time; // Time to complete task
    int arrival_time; // Time of arrival in the system
    int waiting_time; // Total time waited in the queue
    int turnaround_time; // Total time from arrival till completion
};

// Sorting the processes based on their arrival time
void sort_arrival_time(struct process proc[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(proc[i].arrival_time > proc[j].arrival_time) {
                // Swapping the 2 processes if i is greater than j
                struct process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculate_times(struct process proc[], int n) {
    // Waiting time for first process is zero
    proc[0].waiting_time = 0;
    proc[0].turnaround_time = proc[0].burst_time;
    for(int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].turnaround_time + proc[i-1].arrival_time - proc[i].arrival_time;
        // If waiting time obtained is negative then make it zero
        if(proc[i].waiting_time < 0) {
            proc[i].waiting_time = 0;
        }
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

// Main function
int main() {
    struct process proc[10]; // Array of processes
    int n; // Number of processes

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Inputting process data from user
    for(int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].pid = i+1;
    }

    // Sorting the processes by their arrival time
    sort_arrival_time(proc, n);

    // Calculating waiting time and turnaround time
    calculate_times(proc, n);

    // Displaying the results
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    return 0;
}