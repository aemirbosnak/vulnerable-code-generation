//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_WAIT_TIME 10

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int quantum = 2;
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        int min_index = -1;
        int min_burst_time = MAX_WAIT_TIME;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= min_burst_time) {
                min_index = i;
                min_burst_time = processes[i].burst_time;
            }
        }

        if (min_index == -1) {
            current_time += quantum;
        } else {
            processes[min_index].burst_time -= quantum;

            if (processes[min_index].burst_time == 0) {
                completed_processes++;
            } else {
                processes[min_index].waiting_time += current_time - processes[min_index].burst_time;
                processes[min_index].turnaround_time += processes[min_index].waiting_time + processes[min_index].burst_time;
            }
        }
    }
}

int main() {
    int n;
    struct process processes[MAX_PROCESSES];
    int i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}