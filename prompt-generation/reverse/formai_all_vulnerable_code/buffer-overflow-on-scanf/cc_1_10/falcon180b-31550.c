//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define DELAY 2

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n) {
    int i, j, completed_processes = 0, current_time = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time) {
            if (processes[i].burst_time > DELAY) {
                for (j = 0; j < processes[i].burst_time / DELAY; j++) {
                    printf("Process %d is executing...\n", processes[i].id);
                    fflush(stdout);
                    sleep(1);
                }
            } else {
                printf("Process %d is executing...\n", processes[i].id);
                fflush(stdout);
                sleep(processes[i].burst_time / 1000000);
            }

            processes[i].waiting_time = processes[i].arrival_time - current_time - processes[i].burst_time;
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

            printf("Process %d has completed.\n", processes[i].id);
            fflush(stdout);

            completed_processes++;
        } else {
            break;
        }

        current_time += processes[i].burst_time;
    }
}

void print_processes(struct process *processes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d: Arrival Time = %d, Burst Time = %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time for each process:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    execute_processes(processes, n);

    printf("\nProcesses executed in the order of their arrival:\n");
    print_processes(processes, n);

    return 0;
}