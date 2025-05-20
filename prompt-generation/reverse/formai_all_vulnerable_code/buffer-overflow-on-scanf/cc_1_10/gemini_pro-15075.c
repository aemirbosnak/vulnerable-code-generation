//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} process;

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter process %d details:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }

    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].completed) {
                continue;
            }

            if (processes[i].arrival_time <= current_time) {
                if (processes[i].remaining_time <= time_quantum) {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completed = true;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].remaining_time -= time_quantum;
                    current_time += time_quantum;
                }
            }
        }
    }

    printf("\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}