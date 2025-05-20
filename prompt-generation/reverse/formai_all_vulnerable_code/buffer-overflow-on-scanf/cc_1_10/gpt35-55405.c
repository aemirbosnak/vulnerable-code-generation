//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define QUANTUM 2

typedef struct {
    int process_id;
    int burst_time;
    int remaining_time;
} Process;

void sjf(Process *processes, int num_processes);
void rr(Process *processes, int num_processes);

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        processes[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // SJF algorithm
    printf("\n-----SJF Scheduling Algorithm-----\n");
    sjf(processes, num_processes);

    // Round Robin algorithm
    printf("\n-----Round Robin Scheduling Algorithm-----\n");
    rr(processes, num_processes);

    return 0;
}

void sjf(Process *processes, int num_processes) {
    // Sort the processes by their burst time in ascending order
    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].burst_time < processes[i].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Execute the processes
    int current_time = 0;
    float avg_waiting_time = 0;
    printf("Process execution order: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%d ", processes[i].process_id);
        while (processes[i].remaining_time > 0) {
            current_time++;
            processes[i].remaining_time--;
            if (processes[i].remaining_time == 0) {
                avg_waiting_time += current_time - processes[i].burst_time;
            }
        }
    }
    avg_waiting_time /= num_processes;
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
}

void rr(Process *processes, int num_processes) {
    // Execute the processes using round robin algorithm
    int current_time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    int completed_processes[MAX_PROCESSES] = {0};
    int num_completed_processes = 0;
    printf("Process execution order: ");
    while (num_completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (completed_processes[i] == 0) {
                printf("%d ", processes[i].process_id);
                if (processes[i].remaining_time <= QUANTUM) { // Process completes within the quantum
                    current_time += processes[i].remaining_time;
                    total_turnaround_time += current_time;
                    total_waiting_time += current_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    num_completed_processes++;
                    completed_processes[i] = 1;
                } else { // Process needs more time after the quantum
                    current_time += QUANTUM;
                    processes[i].remaining_time -= QUANTUM;
                }
            }
        }
    }
    float avg_waiting_time = (float) total_waiting_time / num_processes;
    float avg_turnaround_time = (float) total_turnaround_time / num_processes;
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
}