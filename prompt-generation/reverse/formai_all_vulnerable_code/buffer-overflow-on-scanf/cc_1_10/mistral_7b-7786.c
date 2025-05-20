//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Happy Scheduling Algorithms - Round Robin with a slice of 2 time units
void round_robin(Process processes[], int num_processes) {
    int time = 0;
    int quantum = 2;
    int index = 0;

    for (int i = 0; i < num_processes; ++i) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\n=== Happy Round Robin Scheduling ===\n");
    while (time < (num_processes * quantum)) {
        if (processes[index].arrival_time <= time && processes[index].burst_time > 0) {
            printf("\nProcess %d is running...\n", processes[index].pid);
            if (processes[index].burst_time <= quantum) {
                time += processes[index].burst_time;
                processes[index].burst_time = 0;
                processes[index].turnaround_time = time - processes[index].arrival_time;
                processes[index].waiting_time = processes[index].turnaround_time - processes[index].burst_time;
            } else {
                time += quantum;
                processes[index].burst_time -= quantum;
            }

            index = (index + 1) % num_processes;
        } else {
            index = (index + 1) % num_processes;
        }
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; ++i) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int num_processes;
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];

    for (int i = 0; i < num_processes; ++i) {
        printf("\nEnter the arrival time and burst time for Process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    round_robin(processes, num_processes);

    return 0;
}