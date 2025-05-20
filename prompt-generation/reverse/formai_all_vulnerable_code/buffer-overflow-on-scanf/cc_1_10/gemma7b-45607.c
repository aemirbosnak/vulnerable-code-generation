//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];

void simulate_cpu_scheduling(int quantum) {
    int i, j, current_time = 0, completed_processes = 0;
    processes[0].waiting_time = 0;

    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].turnaround_time = processes[i].arrival_time + processes[i].burst_time;
    }

    while (completed_processes < MAX_PROCESSES) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                processes[i].waiting_time++;
                processes[i].burst_time--;
                if (processes[i].burst_time == 0) {
                    completed_processes++;
                }
            }
        }

        current_time++;
    }

    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int quantum;

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    simulate_cpu_scheduling(quantum);

    return 0;
}