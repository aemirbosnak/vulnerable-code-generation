//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Struct to store process information
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} Process;

// Function to implement Shortest Job First scheduling algorithm
void SJF(Process processes[], int n) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (true) {
        bool all_completed = true;
        int shortest_burst_time = __INT_MAX__;
        int shortest_burst_time_index = -1;

        // Find the process with shortest burst time which has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completed == false) {
                all_completed = false;
                if (processes[i].burst_time < shortest_burst_time) {
                    shortest_burst_time = processes[i].burst_time;
                    shortest_burst_time_index = i;
                }
            }
        }

        // If all processes are completed, break out of loop
        if (all_completed) {
            break;
        }

        // Update current time and process waiting/turnaround time
        current_time += processes[shortest_burst_time_index].burst_time;
        processes[shortest_burst_time_index].turnaround_time = current_time - processes[shortest_burst_time_index].arrival_time;
        processes[shortest_burst_time_index].waiting_time = processes[shortest_burst_time_index].turnaround_time - processes[shortest_burst_time_index].burst_time;
        total_waiting_time += processes[shortest_burst_time_index].waiting_time;
        total_turnaround_time += processes[shortest_burst_time_index].turnaround_time;
        processes[shortest_burst_time_index].completed = true;
    }

    // Print results
    printf("SJF Scheduling Results:\n");
    printf("Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d           %d             %d           %d             %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    // Take input for number of processes and process information
    printf("Enter number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].completed = false;
    }

    // Call SJF scheduling function
    SJF(processes, n);

    return 0;
}