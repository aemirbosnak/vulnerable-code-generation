//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

// Struct for Process
struct process {
    int id;   // Process ID
    int burst_time;  // Burst time of process
    int arrival_time; // Arrival time of process
    int waiting_time; // Waiting time of process
    int turnaround_time; // Turnaround time of process
    int remaining_time; // Remaining time of process
};

// Function to sort process based on their arrival time
void sort_arrival_time(struct process proc[], int n) {
    int i, j;
    struct process temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(proc[j].arrival_time > proc[j+1].arrival_time) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

// Function to sort process based on their burst time
void sort_burst_time(struct process proc[], int n) {
    int i, j;
    struct process temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(proc[j].burst_time > proc[j+1].burst_time) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

// Function to find waiting time for each process
void find_waiting_time(struct process proc[], int n) {
    int i;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    // Set remaining time for all processes
    for(i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
    }

    // Sort process based on their arrival time
    sort_arrival_time(proc, n);

    printf("\nPID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    // Process until all processes are completed
    while(1) {
        int completed = 1;
        int shortest_job_index = -1;
        int shortest_job_time = 99999;

        // Find the shortest job available in the current time
        for(i = 0; i < n; i++) {
            if(proc[i].remaining_time > 0 && proc[i].arrival_time <= current_time) {
                if(proc[i].remaining_time < shortest_job_time) {
                    shortest_job_index = i;
                    shortest_job_time = proc[i].remaining_time;
                }
                completed = 0;
            }
        }

        // Exit if all processes are completed
        if(completed == 1) {
            break;
        }

        // Decrease the remaining time of the shortest job by 1
        proc[shortest_job_index].remaining_time--;

        // Update current time
        current_time++;

        // If a process is completed, calculate its waiting time and turnaround time
        if(proc[shortest_job_index].remaining_time == 0) {
            proc[shortest_job_index].waiting_time = current_time - proc[shortest_job_index].burst_time - proc[shortest_job_index].arrival_time;
            if(proc[shortest_job_index].waiting_time < 0) {
                proc[shortest_job_index].waiting_time = 0;
            }
            proc[shortest_job_index].turnaround_time = proc[shortest_job_index].burst_time + proc[shortest_job_index].waiting_time;

            // Print the process details
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[shortest_job_index].id, proc[shortest_job_index].burst_time, proc[shortest_job_index].arrival_time, proc[shortest_job_index].waiting_time, proc[shortest_job_index].turnaround_time);

            // Update waiting time and turnaround time for all processes
            total_waiting_time += proc[shortest_job_index].waiting_time;
            total_turnaround_time += proc[shortest_job_index].turnaround_time;
        }
    }

    printf("\nAverage Waiting Time : %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time : %.2f\n", (float)total_turnaround_time/n);
}

// Driver program to test the above functions
int main() {
    int i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process proc[n];

    // Take user input for arrival time and burst time of processes
    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].id = i+1;
    }

    // Sort process based on their burst time
    sort_burst_time(proc, n);

    // Calculate waiting time and turnaround time for each process
    find_waiting_time(proc, n);

    return 0;
}