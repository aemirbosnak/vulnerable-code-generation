//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_times(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void print_processes(Process *processes, int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burst_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

void round_robin(Process *processes, int n, int time_quantum) {
    int time = 0;
    bool done;
    int completed = 0;

    while (completed < n) {
        done = false;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
                done = true;
            }
        }

        if (!done) {
            break; // no process is left to execute
        }
    }

    calculate_times(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, time_quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    round_robin(processes, n, time_quantum);
    print_processes(processes, n);

    return 0;
}