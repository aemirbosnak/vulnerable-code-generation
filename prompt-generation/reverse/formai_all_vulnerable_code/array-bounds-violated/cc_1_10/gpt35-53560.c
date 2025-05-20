//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_BURST_TIME 20

int count;  // number of processes
int burst_time[MAX_PROCESSES];  // burst time for each process

// Structure to hold process data
struct process {
    int id;
    int burst_time;
};

// Function to execute the FCFS algorithm
void fcfs_algorithm() {
    int waiting_time[count], turnaround_time[count];
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    int total_waiting_time = 0, total_turnaround_time = turnaround_time[0];

    for (int i = 1; i < count; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nFCFS Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", total_waiting_time/(float)count);
    printf("Average turnaround time: %.2f\n", total_turnaround_time/(float)count);
}

// Function to execute the SJF algorithm
void sjf_algorithm() {
    int waiting_time[count], turnaround_time[count];
    bool completion[count];  // check if process is complete
    for (int i = 0; i < count; i++) {
        completion[i] = false;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    int time = 0, completed = 0, shortest = MAX_BURST_TIME + 1, shortest_index = 0;
    while (completed != count) {
        for (int i = 0; i < count; i++) {
            if (burst_time[i] <= shortest && burst_time[i] > 0 && time >= waiting_time[i] && !completion[i]) {
                shortest = burst_time[i];
                shortest_index = i;
            }
        }
        burst_time[shortest_index]--;
        shortest = burst_time[shortest_index];
        if (shortest == 0) {
            shortest = MAX_BURST_TIME + 1;
            completion[shortest_index] = true;
            completed++;
            int end = time + 1;
            turnaround_time[shortest_index] = end;
            waiting_time[shortest_index] = end - burst_time[shortest_index];
        }
        time++;
    }

    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nSJF Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average waiting time: %.2f\n", total_waiting_time/(float)count);
    printf("Average turnaround time: %.2f\n", total_turnaround_time/(float)count);
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &count);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &burst_time[i]);
    }

    fcfs_algorithm();
    sjf_algorithm();

    return 0;
}