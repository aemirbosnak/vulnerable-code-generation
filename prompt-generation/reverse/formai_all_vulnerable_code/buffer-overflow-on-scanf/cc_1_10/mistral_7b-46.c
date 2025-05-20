//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void round_robin(Process processes[], int n, int quantum);
void calculate_stats(Process processes[], int n);

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter PID and Burst Time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].pid, &processes[i].burst_time);
    }

    printf("\nEnter Time Quantum: ");
    int quantum;
    scanf("%d", &quantum);

    round_robin(processes, n, quantum);
    calculate_stats(processes, n);

    return 0;
}

void round_robin(Process processes[], int n, int quantum) {
    int time = 0, i = 0;
    int completed = 0;
    Process current = processes[i];

    while (completed < n) {
        if (current.burst_time > quantum) {
            current.burst_time -= quantum;
            time += quantum;
            i = (i + 1) % n;
            current = processes[i];
        } else {
            time += current.burst_time;
            current.burst_time = 0;
            current.waiting_time = time - current.pid;
            completed++;
        }
    }
}

void calculate_stats(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess\tPID\tWaiting Time\tTurnaround Time");

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("\n%d\t%d\t\t%d\t\t%d", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\n\nAverage waiting time: %f", (float)total_waiting_time / n);
    printf("\nAverage turnaround time: %f", (float)total_turnaround_time / n);
}