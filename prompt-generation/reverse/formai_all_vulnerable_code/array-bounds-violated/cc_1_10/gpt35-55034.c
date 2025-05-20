//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * This program demonstrates the Round Robin CPU scheduling algorithm
 * in a cheerful way!
 *
 * The Round Robin algorithm is designed to provide fair CPU time
 * to all processes. In this algorithm, each process is given a fixed
 * time slice to execute. Once the time slice is over, the process is
 * moved to the end of the ready queue and the next process is given
 * a chance to execute.
 */

#define TIME_SLICE 10 // time slice in milliseconds

typedef struct process {
    char name[10];
    int burst;
    int remaining;
} Process;

int main() {
    int num_processes;
    printf("How many processes do you want to simulate? ");
    scanf("%d", &num_processes);

    Process processes[num_processes];
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("Enter the name of process %d: ", i+1);
        scanf("%s", processes[i].name);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst);
        processes[i].remaining = processes[i].burst;
    }

    int total_burst_time = 0;
    for (i = 0; i < num_processes; i++) {
        total_burst_time += processes[i].burst;
    }

    int current_time = 0;
    int current_process = 0;
    int all_processes_completed = 0;

    printf("\nStarting Round Robin CPU scheduling...\n");
    printf("**************************************\n");

    while (!all_processes_completed) {
        if (processes[current_process].remaining > 0) {
            printf("Time %d: Running process %s\n", current_time, processes[current_process].name);
            processes[current_process].remaining -= TIME_SLICE;
            current_time += TIME_SLICE;
        } else {
            current_process++;
        }

        if (current_process == num_processes) {
            current_process = 0;
        }

        int completed_processes = 0;
        for (i = 0; i < num_processes; i++) {
            if (processes[i].remaining <= 0) {
                completed_processes++;
            }
        }

        if (completed_processes == num_processes) {
            all_processes_completed = 1;
        }
    }

    printf("\nAll processes have completed execution.\n");

    return 0;
}