//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME_QUANTA 5

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void execute_process(Process* process, int quantum) {
    if (process->burst_time > quantum) {
        printf("Process %d executed for %d time units\n", process->id, quantum);
        process->burst_time -= quantum;
        process->waiting_time += quantum;
    } else {
        printf("Process %d executed for %d time units\n", process->id, process->burst_time);
        process->burst_time = 0;
        process->waiting_time += process->burst_time;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int time_quanta = MAX_TIME_QUANTA;

    printf("Enter number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    printf("Enter process IDs and burst times:\n");
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burst_time);
    }

    printf("Scheduling using Round Robin algorithm with time quantum of %d:\n", time_quanta);

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0) {
                int time_to_execute = processes[i].burst_time < time_quanta? processes[i].burst_time : time_quanta;
                execute_process(&processes[i], time_to_execute);
                current_time += time_to_execute;
            }
        }
    }

    printf("All processes completed in %d time units\n", current_time);

    return 0;
}