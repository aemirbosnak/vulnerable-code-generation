//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define TIME_QUANTUM 10

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_waiting_time(struct Process processes[], int n) {
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes != n) {
        int is_completed = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                is_completed = 0;

                if (remaining_burst_time[i] > TIME_QUANTUM) {
                    current_time += TIME_QUANTUM;
                    remaining_burst_time[i] -= TIME_QUANTUM;
                } else {
                    current_time += remaining_burst_time[i];
                    processes[i].waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst_time[i] = 0;
                    completed_processes++;
                }
            }
        }
        if (is_completed) {
            current_time++;
        }
    }
}

void calculate_turnaround_time(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void calculate_average_time(struct Process processes[], int n, float* avg_waiting_time, float* avg_turnaround_time) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    *avg_waiting_time = (float)total_waiting_time/n;
    *avg_turnaround_time = (float)total_turnaround_time/n;
}

void print_processes(struct Process processes[], int n) {
    printf("PID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d    ", processes[i].pid);
        printf("%d           ", processes[i].arrival_time);
        printf("%d           ", processes[i].burst_time);
        printf("%d             ", processes[i].waiting_time);
        printf("%d              \n", processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    float avg_waiting_time, avg_turnaround_time;
    calculate_average_time(processes, n, &avg_waiting_time, &avg_turnaround_time);
    print_processes(processes, n);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);

    return 0;
}