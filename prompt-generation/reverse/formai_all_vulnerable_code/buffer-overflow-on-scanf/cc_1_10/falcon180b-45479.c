//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n) {
    int completed_processes = 0;
    int current_time = 0;
    int next_process = 0;
    int i;

    while (completed_processes < n) {
        if (processes[next_process].burst_time > QUANTUM) {
            processes[next_process].burst_time -= QUANTUM;
            current_time += QUANTUM;
        } else {
            processes[next_process].burst_time = 0;
            current_time += processes[next_process].burst_time;
        }
        completed_processes++;
        next_process = (next_process + 1) % n;
    }

    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}