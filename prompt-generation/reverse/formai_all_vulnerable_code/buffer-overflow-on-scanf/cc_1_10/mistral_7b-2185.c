//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROC 5
#define TIME_QUANTUM 3

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void createProcesses(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % 10 + 1;
        printf("Process %d: Burst time = %d\n", processes[i].pid, processes[i].burst_time);
    }
}

void roundRobinScheduling(Process processes[], int n) {
    int time = 0;
    int completed = 0;
    Process current = {-1, 0, 0, 0};

    while (completed < n) {
        if (current.burst_time > 0) {
            if (current.burst_time > TIME_QUANTUM) {
                current.burst_time -= TIME_QUANTUM;
                time += TIME_QUANTUM;
            } else {
                current.burst_time = 0;
                completed++;
            }
        } else {
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (processes[i].burst_time > 0) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("No process is waiting in the ready queue.\n");
                continue;
            }

            current = processes[index];
            processes[index].burst_time = 0;
            time += TIME_QUANTUM;
        }
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = time - processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("Process %d: Waiting time = %d, Turnaround time = %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    srand(time(NULL));
    Process processes[MAX_PROC];

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    createProcesses(processes, n);

    roundRobinScheduling(processes, n);

    return 0;
}