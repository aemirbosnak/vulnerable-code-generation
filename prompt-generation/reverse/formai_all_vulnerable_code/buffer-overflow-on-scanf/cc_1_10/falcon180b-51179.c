//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
/* This is an example program that implements the Round Robin CPU scheduling algorithm. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TICKS 50
#define MAX_TIME_QUANTA 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void round_robin(struct process *processes, int num_processes) {
    int current_process = 0;
    int time_quanta = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        while (time_quanta < processes[current_process].burst_time && time_quanta < MAX_TIME_QUANTA) {
            printf("Process %d is executing...\n", current_process + 1);
            time_quanta++;
            sleep(1);
        }

        processes[current_process].waiting_time += time_quanta - processes[current_process].burst_time;
        processes[current_process].turnaround_time += time_quanta;

        current_process = (current_process + 1) % num_processes;
        time_quanta = 0;

        if (current_process == 0) {
            printf("\n");
        }
    }
}

void main() {
    struct process processes[MAX_PROCESSES];
    int num_processes, i;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    round_robin(processes, num_processes);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}