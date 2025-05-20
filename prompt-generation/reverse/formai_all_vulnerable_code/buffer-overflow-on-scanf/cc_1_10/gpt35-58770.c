//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Structure of a process
struct process {
    int pid; // process ID
    int burst_time; // burst time
    int wait_time; // wait time
    int turnaround_time; // turnaround time
    int arrival_time; // arrival time
};

// Function to find the waiting time for all processes
int find_waiting_time(struct process proc[], int n) {

    int total_time = 0;
    int *remaining_time = (int*) malloc(n * sizeof(int));

    // Copy the burst time into remaining_time[]
    for(int i = 0; i < n; i++)
        remaining_time[i] = proc[i].burst_time;

    while(1) {
        int done = 1;

        // Traverse all processes
        for(int i = 0; i < n; i++) {

            // If burst time of a process is greater than 0 then only need to process further
            if(remaining_time[i] > 0) {
                done = 0;

                // Check if the process has arrived yet
                if(proc[i].arrival_time <= total_time) {
                    total_time++;
                    remaining_time[i]--;

                    // If the process has completed its execution
                    if(remaining_time[i] == 0) {
                        proc[i].wait_time = total_time - proc[i].burst_time - proc[i].arrival_time;
                        if(proc[i].wait_time < 0) proc[i].wait_time = 0;
                    }
                }
            }
        }

        // If all processes are done
        if(done == 1) break;
    }

    free(remaining_time);

    return 0;
}

// Function to find the turnaround time for all processes
int find_turnaround_time(struct process proc[], int n) {
    for(int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].wait_time;
    }
    return 0;
}

// Function to calculate the average waiting time and turnaround time for all processes
int calculate_avg_time(struct process proc[], int n, float *avg_wait_time, float *avg_turnaround_time) {

    int total_wait_time = 0;
    int total_turnaround_time = 0;

    find_waiting_time(proc, n);
    find_turnaround_time(proc, n);

    for(int i = 0; i < n; i++) {
        total_wait_time += proc[i].wait_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    *avg_wait_time = (float) total_wait_time / (float) n;
    *avg_turnaround_time = (float) total_turnaround_time / (float) n;

    return 0;
}

// Function to perform FCFS scheduling
int fcfs(struct process proc[], int n) {

    float avg_wait_time, avg_turnaround_time;

    calculate_avg_time(proc, n, &avg_wait_time, &avg_turnaround_time);

    // Printing the process details
    printf("FCFS Scheduling Algorithm:\n\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].wait_time, proc[i].turnaround_time);
    }

    // Printing the average waiting time and turnaround time for all processes
    printf("\nAverage waiting time: %f\n", avg_wait_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    return 0;
}

int main()
{
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *proc = (struct process*) malloc(n * sizeof(struct process));

    // Getting the process details from the user
    for(int i = 0; i < n; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &proc[i].pid);

        printf("Enter the arrival time: ");
        scanf("%d", &proc[i].arrival_time);

        printf("Enter the burst time: ");
        scanf("%d", &proc[i].burst_time);
    }

    fcfs(proc, n);

    free(proc);

    return 0;
}