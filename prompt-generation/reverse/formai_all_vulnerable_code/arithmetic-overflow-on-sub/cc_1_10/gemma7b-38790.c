//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_a_g(Process **processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i]->waiting_time = 0;
        processes[i]->turnaround_time = processes[i]->burst_time;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i]->burst_time > processes[j]->burst_time) {
                int temp = processes[i]->burst_time;
                processes[i]->burst_time = processes[j]->burst_time;
                processes[j]->burst_time = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        processes[i]->waiting_time = processes[i]->turnaround_time - processes[i]->burst_time;
        processes[i]->turnaround_time = processes[i]->burst_time + processes[i]->waiting_time;
    }
}

int main() {
    Process processes[MAX_PROCESS];

    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].pid = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 5 + 1;
    }

    calculate_a_g(processes, MAX_PROCESS);

    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process %d: Name: %s, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}