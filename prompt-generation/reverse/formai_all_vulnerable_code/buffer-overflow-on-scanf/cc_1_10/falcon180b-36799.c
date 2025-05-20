//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 10
#define MAX_PROCESS_BURST_TIME 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void execute_processes(Process *processes, int num_processes) {
    int i, j, total_burst_time = 0;

    // Calculate the total burst time of all processes
    for (i = 0; i < num_processes; i++) {
        total_burst_time += processes[i].burst_time;
    }

    // Execute each process one by one
    for (i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int completed_processes = 0;
    int time_quantum = 1;

    while (completed_processes < num_processes) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= time_quantum) {
                    processes[i].burst_time = 0;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= time_quantum;
                    processes[i].waiting_time += time_quantum;
                    processes[i].turnaround_time += time_quantum;
                }
            }
        }
        time_quantum++;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\t%d\n", processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name of process %d (up to %d characters): ", i+1, MAX_PROCESS_NAME_LENGTH);
        scanf("%s", processes[i].name);

        printf("Enter the burst time for process %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);

        if (processes[i].burst_time > MAX_PROCESS_BURST_TIME) {
            printf("Error: Burst time cannot exceed %d\n", MAX_PROCESS_BURST_TIME);
            exit(1);
        }
    }

    execute_processes(processes, num_processes);

    return 0;
}