//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_process(struct process *processes, int n, int quantum) {
    int i, j, max_index = 0;
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > quantum) {
            processes[i].burst_time -= quantum;
            for (j = 0; j < n; j++) {
                if (j!= i && processes[j].burst_time > quantum && processes[j].waiting_time <= processes[max_index].waiting_time) {
                    max_index = j;
                }
            }
            processes[i].waiting_time += quantum;
            processes[max_index].waiting_time -= quantum;
        } else {
            processes[i].burst_time = 0;
            processes[i].waiting_time += processes[i].burst_time;
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        }
    }
}

void print_processes(struct process *processes, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("PID: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i, j, sum_waiting_time = 0, sum_turnaround_time = 0, max_waiting_time = 0, max_turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter PID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_process(processes, n, TIME_QUANTUM);

    printf("\nProcesses after execution:\n");
    print_processes(processes, n);

    for (i = 0; i < n; i++) {
        sum_waiting_time += processes[i].waiting_time;
        sum_turnaround_time += processes[i].turnaround_time;

        if (processes[i].waiting_time > max_waiting_time) {
            max_waiting_time = processes[i].waiting_time;
        }

        if (processes[i].turnaround_time > max_turnaround_time) {
            max_turnaround_time = processes[i].turnaround_time;
        }
    }

    printf("\nAverage waiting time: %.2f\n", (float)sum_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)sum_turnaround_time/n);
    printf("Maximum waiting time: %d\n", max_waiting_time);
    printf("Maximum turnaround time: %d\n", max_turnaround_time);

    return 0;
}