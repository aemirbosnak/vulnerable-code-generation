//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;           // Process ID
    int burst_time;    // Burst time
    int waiting_time;  // Waiting time
    int turn_around_time; // Turn around time
} Process;

// Function to calculate waiting time and turnaround time
void calculateTimes(Process proc[], int n, int quantum) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = proc[i].burst_time;
        proc[i].waiting_time = 0;
        proc[i].turn_around_time = 0;
    }

    int time = 0; // Keep track of current time
    int done = 0; // Count of completed processes

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                // If the burst time is greater than quantum
                if (remaining_burst_time[i] > quantum) {
                    time += quantum; // Increment time by quantum
                    remaining_burst_time[i] -= quantum; // Reduce remaining burst time
                    printf("Process %d gets a turn! (%d remaining)\n", proc[i].pid, remaining_burst_time[i]);
                } else {
                    // If the burst time is less than quantum
                    time += remaining_burst_time[i]; // Increment time by remaining burst time
                    proc[i].waiting_time = time - proc[i].burst_time; // Calculate waiting time
                    remaining_burst_time[i] = 0; // Finish the process
                    printf("Process %d finishes happily! \n", proc[i].pid);
                    done++;
                }
            }
        }
    }
}

// Function to calculate average waiting time and average turnaround time
void calculateAverageTimes(Process proc[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turn_around_time;
    }

    printf("\nAverage waiting time: %.2f\n", total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", total_turnaround_time / n);
}

// Main function to execute the program
int main() {
    printf("Welcome to the Happy CPU Scheduling Simulator!\n");

    int n, quantum;
    Process proc[MAX_PROCESSES];

    printf("How many processes do we have? (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Too many processes! Let's stick to the max of %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1; // Assigning Process IDs
        printf("Enter the burst time for Process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst_time);
    }

    printf("What should be our quantum time? (in milliseconds): ");
    scanf("%d", &quantum);

    calculateTimes(proc, n, quantum); // Calculate waiting and turnaround times
    calculateAverageTimes(proc, n); // Calculate and display averages

    printf("Thank you for using the Happy CPU Scheduling Simulator! Have a great day!\n");

    return 0;
}