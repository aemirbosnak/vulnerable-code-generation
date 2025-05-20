//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(struct Process processes[], int n, int quantum) {
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_burst[i] = processes[i].burst_time;

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0;
                if (remaining_burst[i] > quantum) {
                    t += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    t = t + remaining_burst[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void findAverageTimes(struct Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("Processes  Burst Time  Arrival Time  Waiting",
           " Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].burst_time,
               processes[i].arrival_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    printf("\nAverage waiting time: %.2f\n",
           total_waiting_time / n);
    printf("Average turnaround time: %.2f\n",
           total_turnaround_time / n);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findAverageTimes(processes, n, quantum);

    return 0;
}