//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, current_time = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= TIME_QUANTUM) {
            current_time += processes[i].burst_time;
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
        } else {
            for (j = 0; j < n; j++) {
                if (j!= i && processes[j].burst_time <= TIME_QUANTUM) {
                    current_time += processes[j].burst_time;
                }
            }

            current_time += processes[i].burst_time;
            processes[i].waiting_time = current_time - processes[i].burst_time - processes[i].turnaround_time;
            processes[i].turnaround_time = current_time - processes[i].burst_time;
        }
    }
}

void print_processes(struct process processes[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d:\n", processes[i].pid);
        printf("Burst time: %d\n", processes[i].burst_time);
        printf("Waiting time: %d\n", processes[i].waiting_time);
        printf("Turnaround time: %d\n\n", processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);
    print_processes(processes, n);

    return 0;
}