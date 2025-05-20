//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completed;
};

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes, time_quantum;
    int curr_time = 0, completed_processes = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: \n", i + 1);

        printf("\tArrival Time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("\tBurst Time: ");
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }

    printf("\n");
    printf("Process\t\tTurnaround Time\t\tWaiting Time\n");

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].completed) {
                continue;
            }

            printf("Executing process %d\n", i + 1);

            if (processes[i].remaining_time <= time_quantum) {
                curr_time += processes[i].remaining_time;
                processes[i].remaining_time = 0;
                processes[i].completed = 1;
                completed_processes++;

                int turnaround_time = curr_time - processes[i].arrival_time;
                int waiting_time = turnaround_time - processes[i].burst_time;

                printf("%d\t\t%d\t\t%d\n", i + 1, turnaround_time, waiting_time);
            } else {
                curr_time += time_quantum;
                processes[i].remaining_time -= time_quantum;
            }
        }
    }

    return 0;
}